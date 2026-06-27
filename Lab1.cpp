#include <iostream>
#include <string>
using namespace std;

        struct Student{
        int id;
        string name;
        int age;
        string course;
    };
    
    void displayAll(const Student student[], int size);
    void searchRecord(const Student student[],int size,int searchId);
    void updateRecord(Student student[],int size, int updateId);
    
int main(){
    
    Student student[5];
    student [0] = {24005784,"Hakim",20,"Computer Science"};
    student [1] = {24002654,"Luqman",20,"Petroleum Engineering"};
    student [2] = {24001452,"Husna",19,"Chemical Engineering"};
    student [3] = {24003652,"Amalia",21,"Business Management"};
    student [4] = {24003258,"Dhia",20,"Biology"};
    
int choice;

do{
    
cout<< "\n ==== STUDENT DATABASE ==== \n" ;
cout<< "1. Display all records \n ";
cout<< "2. Search for a student data\n";
cout<< "3. Update a student record\n";
cout<< "4. Exit \n";
cout<<"\n Enter your choice: "; cin >> choice;

switch(choice){
    case 1:
    displayAll(student,5);
    break;
    case 2:{
    int searchId;
    cout << "\n Enter Student ID to search : "; cin >> searchId;
    searchRecord(student,5,searchId);
    break;}
    case 3:{
    int updateId;
    cout << "\n Enter Student ID to update : "; cin>> updateId;
    updateRecord(student,5,updateId);
    break;}
    case 4:
        cout<< "\n Thanks for using this system.";
        break;
    default:
    cout << "Invalid choice. Please try again \n";
}
} while (choice != 4);
return 0;
}



void displayAll(const Student student[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " \n -- Student " << i + 1 << " --\n"; 
        cout << "Student ID: " << student[i].id << "\n";
        cout << "Name: " << student[i].name << "\n";
        cout << "Age: " << student[i].age << "\n";
        cout << "Course: " << student[i].course << "\n";
    }
}

void searchRecord(const Student student[], int size, int searchId)
{
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (student[i].id == searchId) {
            cout << "\n -- Student found -- \n";
            cout << "Student ID: " << student[i].id << "\n";
            cout << "Name: " << student[i].name << "\n";
            cout << "Age: " << student[i].age << "\n";
            cout << "Course: " << student[i].course << "\n";
            found = true;
            break;
        }
    else {
        cout << "\n Student with ID " << searchId << " not found. \n";
    }
    }
}

void updateRecord(Student student[], int size, int updateId) {
    int answer;
    for (int i = 0; i < size; i++)
    {
        if (student[i].id == updateId) {
            cout << "\n -- Student found -- \n";
            cout << "Student ID: " << student[i].id << "\n";
            cout << "Name: " << student[i].name << "\n";
            cout << "Age: " << student[i].age << "\n";
            cout << "Course: " << student[i].course << "\n";
            cout << "\n Proceed to update? 1 - Yes / 0 - No : "; cin >> answer;
            
            if (answer == 1) {
                cout << "\n Enter new name: ";
                cin.ignore();
                getline(cin, student[i].name);
                
                cout << " Enter new age: ";
                cin >> student[i].age; 
                
                cout << " Enter new course: ";
                cin.ignore();
                getline(cin, student[i].course);
                
                cout << "\n Record updated successfully.\n";
            } else {
                cout << "Update cancelled.\n";
            }
            break;
        }
    }
}
