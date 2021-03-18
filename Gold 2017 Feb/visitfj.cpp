/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
#define read(ar) \
    for (auto& x : ar) cin >> x;
#define each(ar) for (auto i : ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("visitfj.in");
    ofstream fout("visitfj.out");

    int n, rf;
    cin >> n >> rf;
    int grid[n][n];
    for (int i = 0; i < n; i++) read(grid[i]);
    int dists[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dists[i][j] = -1;
    dists[0][0] = 0;
    // int i = 0, j = 0;
    // for (int r = max(0, i - 3); r <= min(n - 1, i + 3); r++) {
    //     for (int l = max(0, j - 3); l <= min(n - 1, j + 3); l++) {
    //         if (abs(r - i) + abs(l - j) <= 3 && dists[r][l] != -1) {
    //                 dists[i][j] = dists[r][l] + abs(r - i) + abs(l - j) +
    //                 grid[r][l];
    //             min_self(dists[i][j],
    //                      dists[r][l] + abs(r - i) + abs(l - j) + grid[r][l]);
    //         }
    //     }
    // }
    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = max(0, i - 3); r <= min(n - 1, i + 3); r++) {
                    for (int l = max(0, j - 3); l <= min(n - 1, j + 3); l++) {
                        int d = abs(r - i) + abs(l - j);
                        if ((d == 3 || d == 1) && dists[r][l] != -1) {
                            int add = grid[i][j];
                            int moves = 3 * rf;
                            if (i == n - 1 && j == n - 1) add = 0;
                            if (dists[i][j] == -1)
                                dists[i][j] = dists[r][l] + moves + add;
                            // if (i == 2 && j == 2)
                            //     if (dists[i][j] > dists[r][l] + moves + add)
                            //     {
                            //         cout << dists[i][j] << endl;
                            //         cout << dists[r][l] << " " << moves << "
                            //         "
                            //              << add << endl;
                            //     }
                            min_self(dists[i][j], dists[r][l] + moves + add);
                            // if (l == 3 && r == 0 && i == 2 && j == 2) {
                            //     cout << moves << " " << dists[i][j] << endl;
                            // }
                        }

                        // if (abs(r - i) + abs(l - j) <= 3 && dists[r][l] !=
                        // -1) {
                        //     int add = grid[i][j];
                        //     int moves = (abs(r - i) + abs(l - j)) * rf;
                        //     if (i == n - 1 && j == n - 1 &&
                        //         abs(r - i) + abs(l - j) < 3)
                        //         add = 0;
                        //     if (dists[i][j] == -1)
                        //         dists[i][j] = dists[r][l] + moves + add;
                        //     if (i == 2 && j == 2)
                        //         if (dists[i][j] > dists[r][l] + moves + add)
                        //         {
                        //             cout << dists[i][j] << endl;
                        //             cout << dists[r][l] << " " << moves << "
                        //             "
                        //                  << add << endl;
                        //         }
                        //     min_self(dists[i][j], dists[r][l] + moves + add);
                        //     if (l == 3 && r == 0 && i == 2 && j == 2) {
                        //         cout << moves << " " << dists[i][j] << endl;
                        //     }
                        // }
                    }
                }
            }
        }
    }
    int i = n - 1, j = n - 1;
    dists[i][j] = -1;
    for (int r = max(0, i - 3); r <= min(n - 1, i + 3); r++) {
        for (int l = max(0, j - 3); l <= min(n - 1, j + 3); l++) {
            int d = abs(r - i) + abs(l - j);
            if (d <= 3 && dists[r][l] != -1) {
                int add = 0;
                if (d == 3) add = grid[i][j];
                int moves = d * rf;

                if (dists[i][j] == -1) dists[i][j] = dists[r][l] + moves + add;
                // if (i == 2 && j == 2)
                //     if (dists[i][j] > dists[r][l] + moves + add)
                //     {
                //         cout << dists[i][j] << endl;
                //         cout << dists[r][l] << " " << moves << "
                //         "
                //              << add << endl;
                //     }
                min_self(dists[i][j], dists[r][l] + moves + add);
                // if (l == 3 && r == 0 && i == 2 && j == 2) {
                //     cout << moves << " " << dists[i][j] << endl;
                // }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << dists[i][j] << " ";
    //     cout << endl;
    // }
    fout << dists[n - 1][n - 1] << endl;
    return 0;
}
