//ID:22010882
//Name:Aliff Haiqal
//Lab:G1
//Snake Pattern in a Matrix
#include <iostream>
#include <vector>
using namespace std;

void printSnake(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
        } else {
            for (int j = cols - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    printSnake(matrix);
    return 0;
}
