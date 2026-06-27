#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    Node* next; // pointer that points to the next Node in the list
};

int main() {

    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    node1->name = "Aimar"; //node1->next = node 2 // -> means access
    node2->name = "Ahmad"; //node2->next = node 3
    node3->name = "Anjana"; //node3->next = node 4
    node4->name = "Jessy"; //node4->next = NULL
   
   node1-> next = node2;
   node2-> next = node3;
   node3-> next = node4;
   
   Node* display_node = node1;
   while(display_node != NULL){ // while we havent reached the EOL
       cout<< display_node -> name << endl;
       display_node = display_node -> next;
   }
   return 0;
}
