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

// using the FIRST element as the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; 
    int i = low;          // Index tracking the boundary of elements smaller than the pivot

    // iterate number after pivot
    for (int j = low + 1; j <= high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Swap the original pivot with the element at i
    swap(arr[low], arr[i]);
    cout << "Pivot " << pivot << " locked at index " << i << " : ";
    printVector(arr);
    
    return i;
}

// Recursive quick sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr,low, pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    vector<int> numdata = {9, 5, 4, 1, 2, 6, 7, 8, 3};
    cout << "Original: "; 
    printVector(numdata);
    cout << "\n";
    
    startQuickSort(numdata);
    
    cout << "\n Sorted  : "; 
    printVector(numdata);
    return 0;
}