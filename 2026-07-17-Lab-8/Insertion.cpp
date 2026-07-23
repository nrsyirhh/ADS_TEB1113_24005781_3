#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
       cout << arr[i] << " ";
    }
    cout << "\n";
}
// insertion sort function
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    // Iterate from the second element to the end
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        bool isShifted = false;
        // Compare key with before 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            isShifted = true;
        }
        arr[j + 1] = key;
        // Print the array state if elements were shift
        if (isShifted) {
            cout << "Inserted " << key << " at index " << j + 1 << " : ";
            printVector(arr);
        }
    }
}

int main(){
    vector<int> numdata = {9, 5, 4, 1, 2, 6, 7, 8, 3};
    cout << " Original: "; 
    printVector(numdata);
    cout << "\n";
    
    insertionSort(numdata);
    
    cout << "\n Sorted  : "; 
    printVector(numdata);
    return 0;
}