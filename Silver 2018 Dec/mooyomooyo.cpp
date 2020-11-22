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
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
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

vector<string> grid;
int rows, cols = 10;
int k;
bool inBounds(int i, int j) { return i >= 0 && i < rows && j < cols && j >= 0; }
vector<pii> trace;

int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, 1, -1};
bool vis[101][10];
void dfs(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;
    trace.pb(mp(i, j));
    for (int d = 0; d < 4; d++) {
        int x = xs[d] + i, y = ys[d] + j;
        if (inBounds(x, y) && grid[x][y] == grid[i][j]) dfs(x, y);
    }
}

bool moveDown() {
    bool changed = false;
    for (int c = 0; c < 10; c++) {
        int lastZero = -1;
        for (int r = rows - 1; r >= 0; r--) {
            if (lastZero == -1 && grid[r][c] == '0') lastZero = r;
            if (grid[r][c] != '0') {
                if (lastZero == -1) continue;
                grid[lastZero][c] = grid[r][c];
                grid[r][c] = '0';
                r = lastZero;
                lastZero = -1;
                changed = 1;
            }
        }
    }
    return changed;
}

int main() {
    ifstream cin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    cin >> rows >> k;

    grid.resize(rows);
    for (int i = 0; i < rows; i++) cin >> grid[i];

    bool changes = true;

    while (changes) {
        changes = false;
        SET(vis, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == '0' || vis[i][j]) continue;
                trace.clear();
                dfs(i, j);
                changes |= (trace.size() >= k);
                if (trace.size() >= k)
                    for (pii p : trace)
                        grid[p.fi][p.se] = '0';
            }
        }
        changes |= moveDown();
    }

    for (string s : grid) fout << s + "\n";
    return 0;
}