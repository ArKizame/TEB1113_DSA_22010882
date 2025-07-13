//ID:22010882
//Name:Aliff Haiqal
//Lab:G1
//Matrix Chain Multiplication
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int gap = 2; gap < n; gap++) {
        for (int i = 1; i < n - gap + 1; i++) {
            int j = i + gap - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};
    cout << matrixChainMultiplication(dimensions) << endl;
    return 0;
}
