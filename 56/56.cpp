#include <iostream>

using namespace std;
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        DeleteAll();
    }

    void AddToHead(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void DeleteFromTail() {
        if (tail == nullptr) {
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void DeleteAll() {
        while (head != nullptr) {
            DeleteFromHead();
        }
    }

    void Show() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList<int> list;
    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);

    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(6);

    cout << "List after adding elements:" << endl;
    list.Show();
    list.DeleteFromHead();
    cout << "List after deleting from head:" << endl;
    list.Show();
    list.DeleteFromTail();
    cout << "List after deleting from tail:" << endl;
    list.Show();
    list.DeleteAll();
    cout << "List after deleting all elements:" << endl;
    list.Show();
}