#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
#define mod 1000000007
int main() {
    ifstream cin("hopscotch.in");
    ofstream fout("hopscotch.out");

    int rows, cols, k;
    cin >> rows >> cols >> k;
    int ar[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) cin >> ar[i][j];

    ll ways[rows][cols];
    for (int i = 0; i < cols; i++) ways[rows - 1][i] = 0;
    for (int i = 0; i < rows; i++) ways[i][cols - 1] = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) ways[i][j] = 0;
    ways[rows - 1][cols - 1] = 1;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            int cur = ar[i][j];
            // ways[i][j] = 0;
            // ways[i][j] = (cur != ar[rows - 1][cols - 1]);
            // cout << i << " " << j << " | " << ways[i][j] << endl;
            for (int k = i + 1; k < rows; k++) {
                for (int l = j + 1; l < cols; l++) {
                    if (cur != ar[k][l]) {
                        ways[i][j] = (ways[i][j] + ways[k][l]) % mod;
                        // ways[k][l] += ways[i][j];
                        // ways[k][l] %= mod;
                    }
                }
            }
        }
    }
    /*  
    ways[0][0] = 1;
    int r = rows, c = cols;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = i + 1; k < r; k++) {
                for (int l = j + 1; l < c; l++) {
                    if (ar[i][j] != ar[k][l]) {
                        ways[k][l] += ways[i][j];
                        ways[k][l] %= mod;
                    }
                }
            }
        }
    } */
    ll ans = ways[0][0];
    /*   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << ways[i][j] << " ";
        cout << endl;
    } */
    // ans = ways[rows - 1][cols - 1];
    fout << ans << "\n";
    cout << ans << "\n";

    return 0;
}