#include <iostream>
#include <string>
using namespace std;
//  Binary Search Tree
class Node
{
public:
    string name;
    Node* right;
    Node* left;

    Node(string n)
    {
        name = n;
        right = nullptr;
        left = nullptr;
    }
};

class BinarySearchTree
{
    private:
    Node* insertNode(Node* current, string name){
        if (current == nullptr){
            return new Node(name);
        }

        if (name < current -> name){
            current -> left = insertNode(current ->left,name);
        }
        else if (name > current -> name){
            current -> right = insertNode(current ->right, name);
        }

        return current;
    }

    void inOrderTraversal(Node* current){
        if (current != nullptr){
            inOrderTraversal(current->left);
            cout << current -> name << endl;
            inOrderTraversal(current ->);
        }
    }
public:
    Node* root;

    BinarySearchTree()
    {
        root = nullptr;
    }

    // public insert func
    void insertName(string name)
    {
        root = insertNode(root, name);
    }

    void display() {
        inOrderTraversal(root);
    }
};

int main() {
    BinarySearchTree bst;
    cout << "Inserting names into the BST..." << endl;
    bst.insertName("Jessy");
    bst.insertName("Aimar");
    bst.insertName("Anjana");

    cout << "\nBST displayed (In-Order Traversal automatically sorts alphabetically):" << endl;
    bst.display();

    return 0;
}

   

     