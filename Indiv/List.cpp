#include <iostream>
#include "List.h"

using namespace std;

bool List::isEmpty() const {
    return this->head == nullptr && this->tail == nullptr;
};

void List::addFirst(string key, int value) {
    Node* elem = new Node(key, value, nullptr, this->head);
    if (!this->head)
        this->tail = elem;
    this->head = elem;
};

void List::addLast(string key, int value) {
    if(this->isEmpty()) {
        Node* elem = new Node(key, value, nullptr, nullptr);
        this->head = this->tail = elem;
    } else {
        Node* elem = new Node(key, value, this->tail, nullptr);
        this->tail->next = elem;
        this->tail = elem;
    }
};

void List::delFirst() {
    if (this->head)
    {
        if (this->head != this->tail) {
            Node* newFirst = new Node(this->head->next->key, this->head->next->value, nullptr, this->head->next->next);
            delete this->head;
            this->head = newFirst;
        } else {
            delete this->head;
            this->head = this->tail = nullptr;
        }
    }
};

void List::delLast() {
    if (this->tail)
    {
        if (this->head != this->tail) {
            Node* newLast = this->head;
            // Node* newLast = new Node(this->head->key, this->head->value, this->head->prev, this->head->next);
            while (newLast->next != this->tail)
                newLast = newLast->next;
            delete this->tail;
            newLast->next = nullptr;
            this->tail = newLast;
        } else {
            this->delFirst();
        }
    } else {
        cout << "There are no elements!" << endl;
    }
};

int List::count() {
    int i = 0;
    Node* cur = this->head;
    while (cur) {
        i++;
        cur = cur->next;
    }

    return i;
}

bool List::checkElem(string key, int value) {
    Node* cur = this->head;
    while (cur) {
        if (cur->key == key && cur->value == value) {
            return true;
        } else {
            cur = cur->next;
        }
    }
    return false;
}

void List::sorting() {
    Node *left = head;
    Node *right = head->next;

    Node *temp = new Node("0", 0, nullptr, nullptr);

    while (left->next){
           while (right){
                   if ((left->key) < (right->key)){
                       temp->key = left->key;
                       temp->value = left->value;
                       left->key = right->key;
                       left->value = right->value;
                       right->key = temp->key;
                       right->value = temp->value;
                  }
              right = right->next;
          }
      left = left->next;
      right = left->next;
    }
}

int List::operator [] (string key) {
    Node* cur = this->head;
    while (cur) {
        if (cur->key == key) {
            return cur->value;
        } else {
            cur = cur->next;
        }
    }
    return -1;
}

