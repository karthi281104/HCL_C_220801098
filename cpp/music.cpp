#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    int size;

public:
    Playlist() {
        head = NULL;
        size = 0;
    }

    void insertAtBeginning(string name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void insertAtPosition(string name, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(name);
            return;
        }

        Node* newNode = new Node(name);
        Node* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtPosition(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }

            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }

        size--;
    }

    void display() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "\nPlaylist:\n";
        while (temp != NULL) {
            cout << temp->song << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Playlist p;
    int choice, pos;
    string name;

    do {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, name);
            p.insertAtBeginning(name);
            break;

        case 2:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, name);
            p.insertAtEnd(name);
            break;

        case 3:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter position: ";
            cin >> pos;
            p.insertAtPosition(name, pos);
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;
            p.deleteAtPosition(pos);
            break;

        case 5:
            p.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}