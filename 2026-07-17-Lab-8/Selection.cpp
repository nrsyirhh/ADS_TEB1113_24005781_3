#include <iostream>
#include <vector>
#include <utility> // for swapping places
using namespace std;

void printVector(const vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
       cout << arr[i] << " ";
    }
    cout << "\n";
}

// selection sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element 
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted
        if (min_index !=i) {
            cout << "Swapping " << arr[i] << " and " << arr[min_index] << " : ";
            swap(arr[i], arr[min_index]);
            printVector(arr);
        }
    }
}

int main(){
    vector<int> numdata = {9, 5, 4, 1, 2, 6, 7, 8, 3};
    cout << "Original: "; 
    printVector(numdata);
    cout << "\n";
    
    selectionSort(numdata);
    
    cout << "\nSorted  : "; 
    printVector(numdata);
    return 0;
}