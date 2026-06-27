#include <iostream>
#include <string>
using namespace std;
// QUEUE - LIFO

class Node{
    public:
    string name;
    Node* next;

    Node(string value){
        name = value 
        next = nullptr;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string value){
        Node* newNode = new Node(value);

        // If the line is completely empty
        if (rear==nullptr){
            front = newNode;
            rear = newNode;
            return;
        }
        // If people are already in line
        rear -> next = newNode;
        rear = newNode;
    }

    void dequeue(){
        //if line is empty
        if (front == nullptr){
            cout << "Queue is empty! Nobody in line." << endl;
            return;
        }
    Node* current = front; // Grab the person currently at the front
    front = front -> next; // Make the 2nd person the new front of the line
    }

    if (front == nullptr) {
            rear = nullptr;
        }

        delete current
}

// peek

string peek() {
        if (front == nullptr) {
            return "Queue is empty";
        }
        return front->name;
    }

// display

