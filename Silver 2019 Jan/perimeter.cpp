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
//#include <queue>

int n;
vector<string> grid;
bool visited[1001][1001];
bool surrounding[1001][1001];
int perim = 0;
vector<pii> blobs;
int rows, cols;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int i, int j) {
    int counter = 1;
    visited[i][j] = 1;
    int f = 0;
    for (int d = 0; d < 4; d++) {
        int x = dx[d] + i, y = dy[d] + j;
        if (!visited[x][y] && grid[x][y] == '#')
            counter += dfs(x, y);
        perim += grid[x][y] != '#';
    }
    return counter;
}

int main() {
    ifstream cin("perimeter.in");
    ofstream fout("perimeter.out");

    cin >> n;
    rows = cols = n + 2;

    grid.resize(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = "." + grid[i] + ".";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j] || grid[i][j] == '.') continue;
            perim = 0;
            SET(surrounding, false);
            int area = dfs(i, j);
            blobs.pb(mp(area, perim));
        }
    }

    int area = 0;
    perim = 0;
    for (int i = 0; i < blobs.size(); i++) {
        if (blobs[i].fi > area) {
            area = blobs[i].fi;
            perim = blobs[i].se;
        } else if (blobs[i].fi == area && perim > blobs[i].se)
            perim = blobs[i].se;
    }

    fout << area << " " << perim << endl;

    return 0;
}