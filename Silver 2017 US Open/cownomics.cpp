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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
// #include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("cownomics.in");
    ofstream fout("cownomics.out");

    int n, m;
    cin >> n >> m;

    string grid[n * 2];
    for (int i = 0; i < n * 2; i++)
        cin >> grid[i];

    ll tots = 0;
    // tots = m * (m - 1) * (m - 2) / 6;
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                unordered_set<string> freq;
                for (int z = 0; z < n; z++) {
                    string q = "";
                    q += grid[z][i]; /*  + grid[z][j] + grid[z][k]; */
                    q += grid[z][j]; /*  + grid[z][j] + grid[z][k]; */
                    q += grid[z][k]; /*  + grid[z][j] + grid[z][k]; */
                    freq.insert(q);
                    // cout << q << "   asdfasd\n";
                }
                for (int z = n; z < 2 * n; z++) {
                    string q = "";
                    q += grid[z][i]; /*  + grid[z][j] + grid[z][k]; */
                    q += grid[z][j]; /*  + grid[z][j] + grid[z][k]; */
                    q += grid[z][k]; /*  + grid[z][j] + grid[z][k]; */
                    if (FOUND(freq, q)) {
                        // cout << "Found at " << z << " " << i << " "  << j << " " << k <<endl;
                        goto finished;
                    }
                }
                tots++;
                // cout << i << " " << j << " " << k << endl;
            finished:;
            }
        }
    }

    fout << tots << "\n";

    return 0;
}
