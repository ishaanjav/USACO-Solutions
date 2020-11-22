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

#include <cstring>

// Second task of solution is lazy and slow
// 9/10

vvi grid;
int n, rows, cols;
bool vis[251][251];
bool inBounds(int i, int j) { return i >= 0 && i < rows && j < cols && j >= 0; }

vvi cool;

int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, 1, -1};
int id = 0;
vi sizes;
int dfs(int i, int j, int f = 0, int g = 0) {
    vis[i][j] = 1;
    cool[i][j] = id;
    int counter = 1;
    for (int d = 0; d < 4; d++) {
        int x = xs[d] + i, y = ys[d] + j;
        if (inBounds(x, y) && !vis[x][y] && grid[x][y] == grid[i][j]) counter += dfs(x, y);
    }
    return counter;
}
int dfs2(int i, int j, int f = 0, int g = 0) {
    vis[i][j] = 1;
    int counter = 1;
    for (int d = 0; d < 4; d++) {
        int x = xs[d] + i, y = ys[d] + j;
        if (inBounds(x, y) && !vis[x][y] && (grid[x][y] == f || grid[x][y] == g)) counter += dfs2(x, y, f, g);
    }
    return counter;
}

int main() {
    ifstream cin("multimoo.in");
    ofstream fout("multimoo.out");

    cin >> n;
    rows = cols = n;
    grid.resize(n, vi(n));
    cool.resize(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    int ans1 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            sizes.pb(dfs(i, j));
            max_self(ans1, sizes.back());
            id++;
        }
    }
    int ans2 = ans1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 4; d++) {
                int x = xs[d] + i, y = ys[d] + j;
                if (!inBounds(x, y) || grid[x][y] == grid[i][j]) continue;
                SET(vis, false);
                max_self(ans2, dfs2(i, j, grid[i][j], grid[x][y]));
            }
        }
    }

    fout << ans1 << "\n";
    fout << ans2 << "\n";

    return 0;
}