#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <cmath>
#include <iomanip>

using namespace std;

class WalletAuditor;

class Wallet {
    friend class WalletAuditor;

private:
    double balance;

public:
    explicit Wallet(double initialBalance = 0.0) : balance(initialBalance) {
        if (initialBalance < 0.0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
    }

    void deposit(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument("Deposit amount must be > 0");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument("Withdraw amount must be > 0");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
    }
};

class WalletAuditor {
public:
    static void report(const Wallet& wallet) {
        cout << "WalletAuditor report: balance = " << fixed << setprecision(2) << wallet.balance << "\n";
    }
};

class WalletAuditHelper {
public:
    static void reportViaAuditor(const Wallet& wallet) {
        cout << "WalletAuditHelper: can call auditor, but cannot read Wallet internals directly\n";
        WalletAuditor::report(wallet);
    }
};

class Media {
public:
    virtual ~Media() {
        cout << "~Media\n";
    }

    virtual void play() const {
        cout << "Media::play\n";
    }
};

class Audio : public Media {
private:
    string title;

public:
    explicit Audio(string t) : title(std::move(t)) {}

    ~Audio() override {
        cout << "~Audio (" << title << ")\n";
    }

    void play() const override {
        cout << "Playing audio: " << title << "\n";
    }
};

class Video : public Media {
private:
    string title;

public:
    explicit Video(string t) : title(std::move(t)) {}

    ~Video() override {
        cout << "~Video (" << title << ")\n";
    }

    void play() const override {
        cout << "Playing video: " << title << "\n";
    }
};

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(1.0), height(1.0) {
        setWidth(w);
        setHeight(h);
    }

    void setWidth(double w) {
        if (w <= 0.0) {
            throw invalid_argument("Width must be > 0");
        }
        width = w;
    }

    void setHeight(double h) {
        if (h <= 0.0) {
            throw invalid_argument("Height must be > 0");
        }
        height = h;
    }

    double area() const {
        return width * height;
    }
};

namespace MathOps {
    int pow(int base, int exp) {
        if (exp < 0) {
            throw invalid_argument("Integer pow expects exp >= 0");
        }
        long long result = 1;
        long long b = base;
        int e = exp;
        while (e > 0) {
            if (e & 1) {
                result *= b;
            }
            b *= b;
            e >>= 1;
        }
        return static_cast<int>(result);
    }

    double pow(double base, double exp) {
        return std::pow(base, exp);
    }
}

class Function {
public:
    virtual ~Function() = default;
    virtual double evaluate(double x) const = 0;
};

class LinearFunction : public Function {
private:
    double a;
    double b;

public:
    LinearFunction(double slope, double intercept) : a(slope), b(intercept) {}

    double evaluate(double x) const override {
        return a * x + b;
    }
};

class QuadraticFunction : public Function {
private:
    double a;
    double b;
    double c;

public:
    QuadraticFunction(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}

    double evaluate(double x) const override {
        return a * x * x + b * x + c;
    }
};

static void walletDemo() {
    cout << "\n1) Friend class demo\n";

    Wallet wallet(100.00);
    wallet.deposit(50.00);
    wallet.withdraw(20.00);

    WalletAuditor::report(wallet);

    cout << "Friendship is not transitive: WalletAuditHelper is not a friend of Wallet\n";
    WalletAuditHelper::reportViaAuditor(wallet);
}

static void mediaDemo() {
    cout << "\n2) Virtual function + vector<unique_ptr<Media>> demo\n";

    {
        vector<unique_ptr<Media>> playlist;
        playlist.push_back(make_unique<Audio>("Song A"));
        playlist.push_back(make_unique<Video>("Clip B"));
        playlist.push_back(make_unique<Audio>("Song C"));

        for (const auto& m : playlist) {
            m->play();
        }

        cout << "Destroying playlist (virtual destructor ensures derived destructors run)\n";
    }
}

static void rectangleDemo() {
    cout << "\n3) Encapsulation + invariants demo\n";

    Rectangle r(4.0, 3.0);
    cout << "Area initially: " << r.area() << "\n";

    try {
        r.setWidth(-10.0);
    } catch (const exception& ex) {
        cout << "Rejected invalid width: " << ex.what() << "\n";
    }

    try {
        r.setHeight(0.0);
    } catch (const exception& ex) {
        cout << "Rejected invalid height: " << ex.what() << "\n";
    }

    cout << "Area after failed updates: " << r.area() << "\n";
    cout << "Width/height are private, so main cannot directly break invariants\n";
}

static void mathOpsAndPolymorphismDemo() {
    cout << "\n4) Overloading (compile-time) vs overriding (run-time) demo\n";

    int bi = 2;
    int ei = 10;
    double bd = 2.0;
    double ed = 10.0;

    cout << "MathOps::pow(int,int)  : " << MathOps::pow(bi, ei) << "\n";
    cout << "MathOps::pow(double,double): " << MathOps::pow(bd, ed) << "\n";

    unique_ptr<Function> f1 = make_unique<LinearFunction>(3.0, 2.0);
    unique_ptr<Function> f2 = make_unique<QuadraticFunction>(1.0, -2.0, 1.0);

    Function* basePtr = f1.get();
    cout << "Function* -> LinearFunction evaluate(5): " << basePtr->evaluate(5.0) << "\n";

    basePtr = f2.get();
    cout << "Function* -> QuadraticFunction evaluate(5): " << basePtr->evaluate(5.0) << "\n";

    cout << "Overload is chosen by the static types of arguments; override by dynamic type of object\n";
}

int main() {
    cout << fixed << setprecision(2);

    try {
        walletDemo();
        mediaDemo();
        rectangleDemo();
        mathOpsAndPolymorphismDemo();
    } catch (const exception& ex) {
        cout << "Unhandled exception: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
