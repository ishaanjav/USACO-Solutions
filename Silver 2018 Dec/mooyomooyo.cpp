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
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>
bool visited[101][10];
int n, k;
vector<vector<char> > grid;
ofstream fout("mooyomooyo.out");
void printGrid() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) fout << grid[i][j];
        fout << endl;
    }
}
void fallDown() {
    for (int col = 0; col < 10; col++) {
        vector<char> nums;
        for (int r = n - 1; r >= 0; r--)
            if (grid[r][col] != '0') nums.pb(grid[r][col]);
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c++ < nums.size())
                grid[i][col] = nums[c - 1];
            else
                grid[i][col] = '0';
        }
    }
}
bool inBounds(int i, int j, int rows, int cols) { return i >= 0 && i < rows && j < cols && j >= 0; }
int main() {
    ifstream cin("mooyomooyo.in");

    cin >> n >> k;
    grid.resize(n, vector<char>(10));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) cin >> grid[i][j];
    }
    bool changes = false;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    do {
        changes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                queue<pii> q;
                vector<pii> track;
                q.push(mp(i, j));
                while (!q.empty()) {
                    pii top = q.front();
                    q.pop();
                    if (visited[top.fi][top.se]) continue;
                    visited[top.fi][top.se] = 1;
                    track.pb(top);
                    for (int d = 0; d < 4; d++) {
                        int newR = dx[d] + top.fi, newC = dy[d] + top.se;
                        if (inBounds(newR, newC, n, 10) && !visited[newR][newC] && grid[newR][newC] == grid[i][j]) {
                            q.push(mp(newR, newC));
                        }
                    }
                }
                if (track.size() >= k) {
                    each(track) grid[i.fi][i.se] = '0';
                    changes = 1;
                }
            }
        }
        SET(visited, false);
        fallDown();
    } while (changes);
    printGrid();
    return 0;
}
