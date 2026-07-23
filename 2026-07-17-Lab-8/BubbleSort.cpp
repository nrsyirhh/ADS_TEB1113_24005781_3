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

//bubble sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool isSwapped = false;
    
    
    for (int i = 0 ; i < n-1 ; i ++){
        for (int j= 0 ; j < n-i-1; j++){
            if (arr[j]> arr[j+1]){
                // if true, swap
                cout << "Swapping " << arr[j] << " and " << arr[j+1] << " : ";
                swap(arr[j],arr[j+1]);
                isSwapped = true;
                printVector(arr);
            }
        }
        if (!isSwapped){
            break;
        }
    }
}


    int main(){
        vector<int> numdata = {9,5,4,1,2,6,7,8,3};
        printVector(numdata);
        
        bubbleSort(numdata);
        
        cout<< "Sorted : " ; printVector(numdata);
        return 0;
    }


