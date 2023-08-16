/**
*  TIPS:
*  1. Always do boundry check for length i.e. length = 0, length = 1, length < 0
*  2. Always after implementing solution see if you have correctly updated all public 
        elements of class. Eg length, top for Stack and length, front, back for Queue
   3. For Queue add (enqueue) at last and remove (dequeue) from front, so both operations
        stay O(1)
   4. For Stack, because it's growing upwards, the ->next connection for node is backwards
      to previous node.
*/
#include <iostream>

using namespace std;

template<typename T>
class node {
public:
    T data;
    node* next;

    node(T value):
        data{ value }, next{ nullptr }{}
};

/**
* Stack is Last in first out
* In stack you have top node and height
* node is made of data and next node.
* here next node in actual is previous node 
* because stack only has push and pop.
* 
* when we do pop we go to previous node. 
* when we do push we add a new node.
*/
template <typename T>
class stack {
private:
    node<T>* top;
    int height;

public:
    stack(T value) {
        node<T>* newNode = new node<T>(value);
        top = newNode;
        height = 1;
    }

    void getTop() {
        cout << "Top: " << top->data << endl;
    }

    void getHeight() {
        cout << "Height: " << height << endl;
    }

    void printStack() {
        node<T>* temp = top;
        cout << "Stack is : " << endl;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void push(T value) {
        node<T>* newNode = new node<T>(value);
        
        // its in bottom direction as stack grows bottom to top ,
        //so new node's next is pointing to bottom direction which is top here
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop(void) {

        if (height == 0) return INT_MIN;  // Means stack is empty
        
        node<T>* tempNode = top;
        int poppedVal = tempNode->data;

        top = top->next;
        delete tempNode;
        height--;
        return poppedVal;
    }

    // use an extra stack to sort and use a temporary variable/
    // store first value in temp variable and push to new stack
    // now compare second value with whats in temp. if its greater
    // then copy to temp variable and pop back from new stack
    // back to original stack. 
    void sortStack(stack<int>& inputStack) {

    }
};

/**
* Queue is First in first out
* Since if we have front and back node pointer
* Adding at back is O(1) and removing at front is O(1)
* 
* So this is how we will implement a queue rather than doing vice versa.
*/ 
template<typename T>
class queue {
private:
    node<T>* front;
    node<T>* back;
    int length;

public:
    queue(T val) {
        node<T>* newNode = new node<T>(val);
        front = newNode;
        back = newNode;
        length = 1;
    }

    // add to back
    void enqueue(T val) {
        node<T>* newNode = new node<T>(val);

        if (length == 0) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }

        length++;
    }

    // remove from front
    int dequeue() {
        if (length == 0) return INT_MIN;
        
        node<T>* tempNode = front;
        int val = tempNode->data;
        if (length == 1) {
            front = nullptr;
            back = nullptr;
        }
        else {
            front = front->next;
        }
        delete tempNode;
        length--;
        return val;
    }


};

int main()
{
    stack<int>* myStack = new stack<int>(10);

    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    cout << "**********************" << endl;
    myStack->push(1);
    myStack->push(5);
    myStack->printStack();

    cout << "**********************" << endl;
    myStack->push(18);
    myStack->push(3);
    myStack->printStack();

}
