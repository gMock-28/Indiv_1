#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string key;
    int value;
    Node* prev;
    Node* next;

    Node(string key, int value, Node* prev, Node* next) {
        this->key = key;
        this->value = value;
        this->prev = prev;
        this->next = next;
    }

    friend 	ostream& operator<< (ostream& out, const Node& x) {
        out << "('" << x.key << "': " << x.value << ")" << endl;
        return out;
    };

};

class List {
private:
    Node* head;
    Node* tail;
public:
    List(): head(nullptr), tail(nullptr) {};
    ~List() {
        while (head)
        {
            Node* cur = head;
            head = head->next;
            delete cur;
        }
        head = tail = nullptr;
    }

    bool isEmpty() const;

    void addFirst(string key, int value);
    void addLast(string key, int value);

    void delFirst();
    void delLast();

    int count();

    void sorting();

    bool checkElem(string key, int value);

    void raiseValue(string key) {
        Node* cur = this->head;
        while (cur) {
            if (cur->key == key) {
                cur->value += 1;
                break;
            } else {
                cur = cur->next;
            }
        }
    };

    friend ostream& operator << (ostream& out, const List& list) {
        Node* cur = list.head;
        out << "{";
        while (cur) {
            out << "('" << cur->key << "': " << cur->value << ")";
            if (cur->next) out << "; ";
            cur = cur->next;
        }
        out << "}" << endl;
        return out;
    };

//    friend ostream& operator >> (ostream& in, const List& list) {
//        int n;
//        Node* cur = list.head;
//        string key;
//        int value;

//        cout << "Enter the quantity of elements: ";
//        cin >> n;

//        for (int i = 0; i < n; i++) {
//            cout << "Enter " << i + 1 << " key: ";
//            in >> cur->key;

//            cout << "Enter a Value" << " " ;
//            cin >> value;
//            cur->value = value;

//            cout << endl;

//        }
//        return in;
//    };

    int operator[] (string);

};
