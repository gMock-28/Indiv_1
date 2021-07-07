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

    bool checkElem(string key, int value);

    //Геттеры и сеттеры

    string get_key() {
        Node* cur = this->head;
        return cur->key;
    };

    int get_value() {
        Node* cur = this->head;
        return cur->value;
    };

    void set_key(string key) {
        Node* cur = this->head;
        cur->key = key;
    };

    void set_value(string key) {
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

   /* friend ostream& operator >> (ostream& in, const List& list) {
        int n;
        Node* cur = list.head;
        string key;
        int value;

        cout << "Enter kol-vo elems" << endl;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter a Key" << i + 1 << ": ";
            cin >> key;
            cur->key = key;

            cout << "Enter a Value" << " " ;
            cin >> value;
            cur->value = value;

            cout << endl;

        }

    }; */

    int operator[] (string);

};
