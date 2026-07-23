#include <iostream>
#include <string>
using namespace std;
//  Binary Tree
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

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insertChild(string name)
    {
        Node* newNode = new Node();

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node* current = root;

        while (current-> right != nullptr)
        {
            current = current->right;
        }

        current->right = newNode;
        newNode->left = current;
    }

    void insertAfter(string afterName, string newName)
    {
        Node* current = root;

        while (current != nullptr && current->name != afterName)
        {
            current = current->right;
        }

        if (current == nullptr)
        {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);

        newNode->right = current->right;
        newNode->left = current;

        if (current->right != nullptr)
        {
            current->right->left = newNode;
        }

        current->right = newNode;
    }

    void deleteByName(string name)
    {
        if (root == nullptr)
        {
            return;
        }

       /* Node* current = root;

        while (current != nullptr)
        {
            if (current->name == name)
            {
                if (current->left != nullptr)
                {
                    current->left->right = current->right;
                }
                else
                {
                    root = current->right;
                }

                if (current->right != nullptr)
                {
                    current->right->left = current->left;
                }

                delete current;
                return;
            }

            current = current->right;
        }
    }

    void display()
    {
        Node* current = root;

        while (current != nullptr)
        {
            cout << current->name << endl;
            current = current->right;
        }
    }

    void displayReverse()
    {
        if (root == nullptr)
        {
            return;
        }

        Node* current = root;

        while (current->right != nullptr)
        {
            current = current->right;
        }

        while (current != nullptr)
        {
            cout << current->name << endl;
            current = current->left;
        }
    }
};

int main()
{
    BinaryTree list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    cout << endl;
    cout << "After inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << endl;
    cout << "After inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    cout << endl;
    cout << "After deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << endl;
    cout << "Reverse BinaryTree:" << endl;
    list.displayReverse();

    cout << endl;
    cout << "Final list (in order):" << endl;
    list.display();

    return 0;
} */