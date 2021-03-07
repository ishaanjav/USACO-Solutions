/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#include <string>
#include <vector>
typedef vector<int> vi;

int prefix[501][501]; // # of at >= 100
int one[501][501]; //  # of 100s
bool cols[501];
int rows[501];
int main() {
    int n; cin >> n;
    int grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        vi pre; pre.rs(n+1);
        for(int j = i; j < n; j++) {
            ll len = 0, cur = 0;
            for(int k = 0; k < n; k++) {
                if(len * (j + 1 - i) != cur)
                    cur = len = 0;
                pre[k] += grid[j][k] >= 100;
                cur += pre[k];
                if(cur == (j + 1 - i) * ++len) answer += len;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        vi pre; pre.rs(n+1);
        for(int j = i; j < n; j++) {
            ll len = 0, cur = 0;
            for(int k = 0; k < n; k++) {
                if(len * (j + 1 - i) != cur)
                    cur = len = 0;
                pre[k] += grid[j][k] > 100;
                cur += pre[k];
                if(cur == (j + 1 - i) * ++len) answer -= len;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
