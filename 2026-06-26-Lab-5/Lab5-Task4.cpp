#include <iostream>
#include <string>

using namespace std;


class Queue {
    int front;
    int rear;
    string arr[4];

public:
    Queue() {
        // -1 means no one is in line yet
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(string value) {
 
        if (rear == 4-1) {
            cout << "Queue is Full! Cannot add."<< endl;
            return;
        }

        if (front == -1) {
            front = 0; // The front of the line is now index 0
        }

        rear++; // Move the rear index to the next empty chair
        arr[rear] = value; // Put the person in that chair
    }

    // Dequeue
    void dequeue() {
        // If the line is empty, or the front has passed the rear
        if (front == -1 || front > rear) {
            cout << "Queue is Empty! Nobody to remove." << endl;
            return;
        }

        // The person at the front leaves, so the NEXT person becomes the front
        front++;
    }

    // Peek: Look at who is first in line
    string peek() {
        if (front == -1 || front > rear) {
            return "Queue is empty";
        }
        return arr[front];
    }
    
    // Display
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        // Loop from the 'front' index to the 'rear' index
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue("Aimar");
    q.enqueue("Ahmad");
    q.enqueue("Anjana");
    q.enqueue("Jessy");

    cout << "Current Line (Front to Rear):" << endl;
    q.display();

    cout << "\n First person in the line: " << q.peek() << endl;

    cout << "\n Aimar gets his food and leaves.." << endl;
    q.dequeue();

    cout << "\n Current Line:" << endl;
    q.display();
    
    cout << "\n Let's try adding someone else..." << endl;
    q.enqueue("Ali");

    return 0;
}