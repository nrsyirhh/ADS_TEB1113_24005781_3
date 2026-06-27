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
    public:
    string name;
    Stack* next = nullptr;
    Stack* top = nullptr;
    
//push
void push(string value){
    Stack* newNode = new Stack();
    newNode -> name = value;
    newNode -> next = top;
    top = newNode;
}

//pop
void pop(){
    if (top== nullptr){
        return;
    }
    Stack* current = top; //
    top = top -> next;
    delete current;
}

//peek
string peek(){
    if (top == nullptr){
        return "Stack is empty.";
    }
    return top-> name;
}
};

int main() {
    Stack stack;
    
    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anjana");
    stack.push("Jessy");
    
    cout << "Peek top item: " << stack.peek() << endl;
    cout << " Current stack: " << endl;
    Stack* display_node = stack.top;

    for(int i = 0; i < 4; i++){
        cout << display_node->name << endl; 
        display_node = display_node->next;
    }
    
    return 0;
}