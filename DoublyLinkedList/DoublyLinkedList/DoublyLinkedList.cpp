// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* prevNode;
    node* nextNode;

    node(int data):
        data{ data }, prevNode{ nullptr }, nextNode{ nullptr }
    {}
};

class doublyLinkedList
{
private:
    node* head;
    node* tail;
    int length;

public:
    doublyLinkedList(int value) {
        node* newNode = new node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList(void) {
        if (length == 0) { cout << "Empty DLL" << endl;  return; }

        node* tempNode = head;
        while (tempNode) {
            cout << tempNode->data << " ";
            tempNode = tempNode->nextNode;
        }
        cout << endl;
    }

    void getHead(void) {
        cout << head->data << endl;
    }

    void getTail(void) {
        cout << tail->data << endl;
    }

    void getLength(void) {
        cout << length << endl;
    }

    void append(int value) {

        node* newNode = new node(value);
        if (length == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast(void) {
        if (length == 0) return;

        node* tempNode = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prevNode;
            tail->nextNode = nullptr;
        }
        delete tempNode;
        length--;
    }

    void prepend(int value) {
        node* newNode = new node(value);
        if (length == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->nextNode = head;
            head->prevNode = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst(void) {
        
        if (length == 0) return;
        node* tempNode = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->nextNode;
            head->prevNode = nullptr;
        }
        delete tempNode;
        length--;
    }

    node* get(int index) { 
        if ((index < 0) || (index > length)) return nullptr;
        if (length == 0) return nullptr;
        if (length == 1) return head;
   
        node* tempNode = head;
        if (index < length / 2) {
            for (int i = 0; i < index; i++) {
                tempNode = tempNode->nextNode;
            }
        }
        else {
            tempNode = tail;
            for (int i = length - 1; i > length-index; i--){
                tempNode = tempNode->prevNode;
            }
        }
        return tempNode;
    }

    bool set(int index, int value) {
        node* temp = get(index);

        if (temp) {
            temp->data = value;
            return true;
        }
        return false;
    }

    bool insertNode(int index, int value) {
     
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        else if(index == length){
            append(value);
            return true;
        }
        
        node* prevNode = get(index - 1);
        node* nextNode = prevNode->nextNode;
        node* newNode = new node(value);

        prevNode->nextNode = newNode;
        newNode->prevNode = prevNode;
        newNode->nextNode = nextNode;
        nextNode->prevNode = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {

        if (index < 0 || index > length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        node* temp = get(index);
        if (temp) {
            node* prevTemp = temp->prevNode;
            node* nextTemp = temp->nextNode;

            prevTemp->nextNode = nextTemp;
            delete temp;
            length--;
        }
    }

    void reverseDLL(void) {

        if (length < 3) return;
        
        node* mainNode = head;
        node* afterNode = head;

        node* tempNode = nullptr;
        for (int i = 0; i < length; i++) {
            afterNode = afterNode->nextNode;
            
            // swapping each node's prev and next
            tempNode = mainNode->prevNode;
            mainNode->prevNode = mainNode->nextNode;
            mainNode->nextNode = tempNode;

            // jumping to next node
            mainNode = afterNode;
        }

        tempNode = head;
        head = tail;
        tail = tempNode;
    }
};

int main()
{
    doublyLinkedList* myDll = new doublyLinkedList(10);
    myDll->printList();

    myDll->append(20);
    myDll->append(30);
    myDll->printList();

    myDll->prepend(5);
    myDll->prepend(4);
    myDll->printList();

    myDll->deleteFirst();
    myDll->printList();

    myDll->prepend(2);
    myDll->printList();

    myDll->reverseDLL();
    myDll->printList();
}
