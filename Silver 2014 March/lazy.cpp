/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;
#define ll long long

ll colSum[401][401];
int main() {
    ifstream cin("lazy.in");
    ofstream fout("lazy.out");
    
    int n, k; cin >> n >> k;
    ll grid[n+1][n+1];
    for(int i = 0; i <= n; i++)
    for(int j = 0; j < n; j++){
        if(i == 0) grid[i][j] = 0;
        else cin >> grid[i][j];
    }
    for(int j = 0; j < n; j++)
        for(int row =1; row <= n; row++)
            colSum[row][j] += colSum[row-1][j] + grid[row][j];
    ll answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            ll sum = 0;
            char grid[n+1][n];
            for(int steps = 0; steps <= k && j + steps < n; steps++){
                ll lowRow = max(1, i - (k - steps));
                ll upRow = min(i + k - steps, n);
                sum += colSum[upRow][j+steps] - colSum[lowRow - 1][j+steps];
            }
            for(int steps = 1; steps <= k && j - steps >= 0 ; steps++){
                ll lowRow = max(1, i - (k - steps));
                ll upRow = min(i + k - steps, n);
                sum += colSum[upRow][j-steps] - colSum[lowRow - 1][j-steps];
            }
            max_self(answer, sum);
        }
    }
    fout << answer << endl;
    return 0;
}
