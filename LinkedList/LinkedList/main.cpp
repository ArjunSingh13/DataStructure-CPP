// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int passData = 0)
    {
        this->data = passData;
        next = nullptr;
    }
};

class linkedList
{
private:
    node* head;
    node* tail;
    int length;

public:
    linkedList(int val = 0)
    {
        // node is constructore so when create newNode pass value along
        // new does dma so its scope is forever until not delete
        node* newNode = new node(val);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~linkedList() {
        node* temp = head;
        while (head) { // keep traversing head until end and temp will keep deleting
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printlist() {
        node* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void getHead() {
        if (head == nullptr){
            cout << "no elements in array" << endl;
        }
        else {
            cout << head->data << endl;
        }
    }

    void getTail()
    {
        if (tail == nullptr){
            cout << "no elements in list";
        }
        else{
            cout << tail->data << endl;
        }
    }
 
    void getLength(){
        cout << "length is " << length << endl;
    }

    void append(int data) {

        node* newNode = new node(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;  // tail's next should contain address of newNode
            tail = newNode;        // tail should be pointing to last new node 
        }
             
        length++;
        cout << "New length is " << length << endl;
    }

    /**
    * Take two node ptrs current and pre to delete last node
    */
    void deleteLast(void)
    {
        node* curNode = head;
        node* preNode = head;
        if (length == 0)
        {
            cout << "already empty linkedlist" << endl;
        }
        else if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            delete curNode;
            length--;
        }
        else {
            while (curNode->next)
            {
                preNode = curNode;
                curNode = curNode->next;
            }

            // reach to the end
            tail = preNode;
            tail->next = nullptr;
            delete curNode;
            length--;
        }
    }

    /* add data at beginning */
    void prepend(int data)
    {
        node* newNode = new node(data);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
            // no need to do anything with tail
        }

        length++;
    }

    void deleteFirst(void) {
        if (length == 0) {
            cout << "LL already empty" << endl;
        }
        else if (length == 1) {
            head = nullptr;
            tail = nullptr;
            delete head;
            length = 0;
        }
        else {
            node* temp = head;
            head = head->next;

            temp = nullptr;
            delete temp;
            length--;
        }
    }

    node* get(int index) {
        if (index < 0 || index > length){
            cout << "Incorrect input data" << endl;
            return nullptr;
        }
        else {
            node* temp = head;
            for (int i = 0; i<index; i++){
                temp = temp->next;
            }
            return temp;
        }
    }

    bool set(int index, int val) {
        node* temp = get(index);
        if (temp) {
            temp->data = val;
            return true;
        }
        else {
            return false;
        }
    }

    bool insert(int index, int value){
        if (index < 0 || index > length) return false;

        if (index == 0) prepend(value);
        else if (index == length) append(value);
        else {
            node* traverseNode = head;
            node* newNode = new node(value);

            for (int i = 0; i < index-1; i++){
                traverseNode = traverseNode->next;
            }
            newNode->next = traverseNode->next;
            traverseNode->next = newNode;
        }

        length++;
        return true;
    }

    bool deleteNode(int index) {
        if (index < 0 || index >= length) return false;
        if (index == 0) { deleteFirst(); return true; }
        else if (index == length - 1) { deleteLast(); return true; }
        
        node* prevNode = get(index-1);
        node* tempNode = prevNode->next;

        prevNode->next = tempNode->next;
        delete tempNode;
        length--;
    }

    void printList(void) {
        
        if (length == 0) cout << "Empty List" << endl;
        else {

            node* tempNode = head;
            for (int i = 0; i < length; i++)
            {
                while (tempNode)
                {
                    cout << tempNode->data << " ";
                    tempNode = tempNode->next;
                }
            }
            cout << endl;
        }
    }

    bool reverse(void)
    {
        if (length == 0) return false;
        else {
            // for reversing the list
            node* beforeNode = nullptr;
            node* currentNode = head;
            node* afterNode = currentNode;

            // Here swapping head and tail
            node* tempNode = head;
            head = tail;
            tail = tempNode;

            // actual reversing of list
            for (int i = 0; i < length; i++)
            {
                afterNode = afterNode->next;
                currentNode->next = beforeNode;
                beforeNode = currentNode;
                currentNode = afterNode;
            }
        }
        return true;
    }
};


int main()
{
    linkedList* myLinkedList = new linkedList(4);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->append(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->deleteLast();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->printList();
    myLinkedList->reverse();
    myLinkedList->printList();
}
 
