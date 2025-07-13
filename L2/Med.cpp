//ID:22010882
//Name:Aliff Haiqal
//Lab:G1
//Search in a Row-wise and Column-wise Sorted Matrix
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(const vector<vector<int>>& mat, int key) {
    int rows = mat.size();
    int cols = mat[0].size();
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0) {
        if (mat[i][j] == key)
            return true;
        else if (mat[i][j] > key)
            j--;
        else
            i++;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int key = 29;
    if (searchMatrix(matrix, key))
        cout << key << " found in matrix." << endl;
    else
        cout << key << " not found in matrix." << endl;
    return 0;
}
