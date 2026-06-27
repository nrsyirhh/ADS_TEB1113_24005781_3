#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anjana
Jessy
*/


class Stack{
    int top;
    string arr[4];

    public:
    Stack(){
        top = -1; // empty stack
    }

    // push : put item on top
    void push(string value){
        if (top >= 4-1){
            cout << "Stack Overflow ! Cannot add more." << endl;
            return;
        }
        top++;
        arr[top] = value; // store the val as the element
    }

    // pop : removes the top item
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        top--;
    }

    //peek
    string peek() {
        if (top < 0) {
            return "Stack is empty";
        }
        return arr[top];
    }

    // display 
    void display(){
        if (top<0){
            cout << "Stack is empty."<< endl;
            return;
        }
        for(int i = top; i >= 0; i--){ // loop backward
            cout << arr[i]<<endl;
        }
    }
};

int main(){
    Stack stack;
    
    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anjana");
    stack.push("Jessy");

    cout << "Peek top item: " << stack.peek() << endl << endl;
    
    cout << "Current Stack:" << endl;
    stack.display();
    
    return 0;
}