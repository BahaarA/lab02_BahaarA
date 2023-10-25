// intlist.cpp
// Implements class IntList
// Bahaar Ahuja, October 23, 2023

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    Node* srcNode = source.first;
    Node* preNode = nullptr;
    while (srcNode){
        Node* newNode = new Node;
        newNode->info = srcNode->info;
        newNode->next = nullptr;

        if (first) {
            
            preNode->next = newNode;
        
        }
        else{
            first = newNode;
        }
        preNode = newNode;
        srcNode = srcNode->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
   while (first){
    Node* temp = first;
    first = first-> next;
    delete temp;
   }
}


// return sum of values in list
int IntList::sum() const {
    int tot = 0;
    Node* curNode = first;
    while (curNode){
        tot = tot + curNode-> info;
        curNode = curNode-> next;
    }
    return tot;

}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for (Node* currentNode = first; currentNode; currentNode = currentNode->next) {
        if (currentNode->info == value) {
            return true;
        }
    }
    
    return false;  
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!first) {
        return 0;  //  Empty list
    }

    int max = first->info;
    Node* curNode = first->next;

    while (curNode) {
        if (curNode->info > max) {
            max = curNode->info;
        }
        curNode = curNode->next;
    }

    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!first) {
        return 0.0;  // Empty list
    }
    int total = 0;
    int count = 0;
    for (Node* curNode = first; curNode; curNode = curNode->next) {
        total = total +currentNode->info;
        count++;
    }

    return static_cast<double>(total) / count;
}
    
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = first;
    first = newNode;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source) {  
        while (first) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }

        // Copy elements from the source list (similar to the copy constructor)
        Node* srcNode = source.first;
    Node* preNode = nullptr;
    while (srcNode){
        Node* newNode = new Node;
        newNode->info = srcNode->info;
        newNode->next = nullptr;

        if (first) {
            
            preNode->next = newNode;
        
        }
        else{
            first = newNode;
        }
        preNode = newNode;
        srcNode = srcNode->next;
    }
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
