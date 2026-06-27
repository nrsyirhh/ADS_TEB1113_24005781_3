#include <iostream>
#include <vector>
using namespace std;

void printSnake(const vector<vector<int>>& mat){ // 2D Vector
    // loop through each row 
    for (int i=0; i < mat.size(); i++){
        // for even row : Left to right
        if (i%2 == 0){
            for( int j = 0 ; j < mat[i].size(); j++)
            cout << mat [i][j]<< "  ";
        }
        else {
            for (int j= mat[i].size()-1; j >= 0; j--)
            cout << mat [i][j]<< "  ";
        }
    }
}

int main(){
    vector<vector<int>> mat ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    printSnake(mat);
    return 0;
}