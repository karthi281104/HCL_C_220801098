#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[20];
    float marks;
};

int main() {
    ofstream file("student.dat", ios::binary);

    Student s;

    for(int i = 1; i <= 5; i++) {
        cout << "Enter roll, name, marks: ";
        cin >> s.roll >> s.name >> s.marks;
        file.write((char*)&s, sizeof(s));
    }

    file.close();
    cout << "File created successfully!";
}