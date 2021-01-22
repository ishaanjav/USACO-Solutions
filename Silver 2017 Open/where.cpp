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
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <cstring>
#include <queue>

struct PCL {
    int i1, j1, i2, j2;
    PCL(int i, int j, int k, int l) {
        i1 = i, j1 = j, i2 = k, j2 = l;
    }
};
vector<PCL> pcls;
bool inBounds(int r, int c, int i, int j, int k, int l) {
    return r >= i && r <= k && c >= j && c <= l;
}
bool inside(int i, int j) {
    PCL a = pcls[i], b = pcls[j];
    return inBounds(a.i1, a.j1, b.i1, b.j1, b.i2, b.j2) && inBounds(a.i2, a.j2, b.i1, b.j1, b.i2, b.j2);
}
int main() {
    ifstream cin("where.in");
    ofstream fout("where.out");

    int n;
    cin >> n;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];
    int count = 0;
    bool visited[n + 1][n + 1];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    if (i == k && j == l) continue;
                    unordered_set<char> chars;
                    for (int r = i; r <= k; r++)
                        for (int c = j; c <= l; c++) chars.ins(grid[r][c]);
                    if (chars.size() != 2) continue;
                    SET(visited, false);
                    unordered_map<char, int> u;
                    for (int r = i; r <= k; r++)
                        for (int c = j; c <= l; c++) {
                            if (visited[r][c]) continue;
                            queue<pii> q;
                            q.push(mp(r, c));
                            u[grid[r][c]]++;
                            while (!q.empty()) {
                                pii top = q.front();
                                q.pop();
                                if (visited[top.fi][top.se]) continue;
                                visited[top.fi][top.se] = 1;
                                for (int d = 0; d < 4; d++) {
                                    int x = dx[d] + top.fi, y = dy[d] + top.se;
                                    if (!inBounds(x, y, i, j, k, l) || visited[x][y] || grid[x][y] != grid[top.fi][top.se]) continue;
                                    q.push(mp(x, y));
                                }
                            }
                        }
                    int cnt = 0;
                    for (auto p : u) if (p.se > 1) cnt++;
                    if (cnt == 1) pcls.pb(PCL(i, j, k, l));
                }
            }
        }
    }
    int ans = pcls.size();
    n = ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && inside(i, j)) {
                ans--;
                break;
            }
    fout << ans << Endl;
    return 0;
}