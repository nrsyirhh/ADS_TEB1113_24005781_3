#include <iostream>
#include <string>
using namespace std;

// QUEUE - FIFO (First In First Out)
class Node {
public:
    string name;
    Node* next;

    Node(string value) {
        name = value;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string value) {
        Node* newNode = new Node(value);

        // if queue is empty
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }
        // if there is a person ....
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        // if queue is emptry
        if (front == nullptr) {
            cout << "Queue is empty! Nobody in line." << endl;
            return;
        }
        
        Node* current = front; // Take person in the front
        front = front->next;   // Second person become first

        
        if (front == nullptr) {
            rear = nullptr;
        }

        delete current; 
    }

    // peek
    string peek() {
        if (front == nullptr) {
            return "Queue is empty";
        }
        return front->name;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        // temp = temporary
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "" << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue("Aimar");
    q.enqueue("Anjana");
    q.enqueue("Ahmad");
    
    q.display();
    
    cout << "Front of queue (peek): " << q.peek() << endl;
    
    cout << "Dequeueing 1 person..." << endl;
    q.dequeue();
    
    q.display();
    
    return 0;
}