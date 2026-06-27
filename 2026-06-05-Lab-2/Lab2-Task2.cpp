#include <algorithm> // for sort,reverse,max,count,find
#include <iostream>
#include <vector>
using namespace std;

//define function median bypass ref
int median(const vector<vector<int>>& mat){
    vector <int> arr;

    // flatten the matrix
    for (int i=0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            arr.push_back(mat[i][j]);
        }
    }

    //sort the array
    sort(arr.begin(),arr.end());

    //find the median element
    int midnumber = arr.size() / 2;
    return arr[midnumber];
}

int main(){
    vector < vector<int>> matrix = 
    { {1,2,3},
    {4,5,6},
    {7,8,9},
};
cout << median(matrix) << endl;
return 0;
}