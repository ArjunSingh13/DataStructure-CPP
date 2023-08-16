/**
*  Adding to a BST:
*  1. 3 kinds of BST: Perfect, Full, Complete
*  2. Node has data, left and right pointer.
*  3. Left data is always smaller than right data.
*  4. This file contains insert() and contain()(to check 
*     if a value is part of BST or not) functions.
*  5. Breadth First Search function added in class
*/
#include <iostream>
#include <queue>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int value)
        : data{value}, left{nullptr}, right{nullptr} {}
};

class BST {
private:
    node* root;

    // recursively call itself for left then right, just order of print change
    // for Pre , post and in order traversal..
    void DFS_PreorderInternal(node* tempNode) {
        cout << tempNode->data << " ";
        if (tempNode->left) DFS_PreorderInternal(tempNode->left);
        if (tempNode->right) DFS_PreorderInternal(tempNode->right);
    }

    void DFS_InorderInternal(node* tempNode) {
        if (tempNode->left) DFS_PreorderInternal(tempNode->left);
        cout << tempNode->data << " ";
        if (tempNode->right) DFS_PreorderInternal(tempNode->right);
    }

    void DFS_PostorderInternal(node* tempNode) {
        if (tempNode->left) DFS_PreorderInternal(tempNode->left);
        if (tempNode->right) DFS_PreorderInternal(tempNode->right);
        cout << tempNode->data << " ";
    }
public:
    BST() {
        root = nullptr;
    }

    bool insert(int data) {

        node* newNode = new node(data);
        if (root == nullptr) {
            root = newNode;
        }
        else {

            node* tempNode = root;
            while (true){  // come out if false
                    
                if (newNode->data == tempNode->data) return false;

                if (newNode->data < tempNode->data) {  // go left
                    if (tempNode->left == nullptr) {     // is temp->left equal to NULL?
                        tempNode->left = newNode;        // if true then put new node on left 
                        return true;
                    }
                    tempNode = tempNode->left;              // if temp->left is not null yet then move to left
                }
                else {
                    if (tempNode->right == nullptr) {
                        tempNode->right = newNode;
                        return true;
                    }
                    tempNode = tempNode->right;
                }
            }
        }
    }

    bool contain(int val) {

        if (root == nullptr) return false;

        node* tempNode = root;

        bool retFlag = false;
        while (true) {
            if (val == tempNode->data) {
                retFlag = true;
                break;
            }
            else if (val < tempNode->data) {
                if (tempNode->left == nullptr) break;
                tempNode = tempNode->left;
            }
            else {
                if (tempNode->right == nullptr) break;
                tempNode = tempNode->right;
            }
        }

        if (retFlag) {
            cout << "BST contains " << val << endl;
        }
        else {
            cout << "BST does not contain " << val << endl;
        }
        return retFlag;
    }

    /**
    *  In BFS we take root of the bst and push to queue. Now we check the queue
    *  until there are elements in queue, we keep each front element on at a time
    * in a temp node. we keep popping every loop on item. Then we check for that 
    * node with help of currentNode pointer  if there are left/right nodes further
    * to it then we push them to queue. at the same time in next iteration of loop
    * we look for item at front which is now right node of the root and we do same 
    * for it. Keep repeating until for last row of Bst we find nullptr as return 
    * and then we stop adding new items to queue and now just keep popping from front
    * of queue and keep printing data.
   */
    void BFS() {
        queue<node*> myQueue;   // Create a queue to add elements of BST
        myQueue.push(root);         // Give root of BST to myQueue
        
        node* currentNode = nullptr; // take a temp node to traverse over BST
        while (myQueue.size() > 0) {
            currentNode = myQueue.front();   // Put front of queue in node
            cout << currentNode->data;      // cout the data of current of node
            myQueue.pop();                  // pop front of queue

            if (currentNode->left != nullptr) {  //if left is not null push it to queue
                myQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                myQueue.push(currentNode->right);
            }
        }
    }

    void DFS_Preorder() {
        node* tempNode = root;
        DFS_PreorderInternal(tempNode);
    }

    void DFS_Inorder() {
        node* tempNode = root;
        DFS_InorderInternal(tempNode);
    }

    void DFS_Postorder() {
        node* tempNode = root;
        DFS_PostorderInternal(tempNode);
    }
};

int main()
{
    BST* myBST = new BST();
    
    myBST->insert(1);
    myBST->insert(2);
    myBST->insert(3);
    myBST->insert(4);
    myBST->insert(5);

    myBST->contain(1);
    myBST->contain(5);
    myBST->contain(11);

    myBST->BFS();
    return 0;

}
