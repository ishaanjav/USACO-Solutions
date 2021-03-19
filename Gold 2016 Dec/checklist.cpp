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

// Solution: Recursive DP
// States: H position, G position, whether previous cow was a H or a G

int n, m;
pll h[1001], g[1001];
ll dist(pll a, pll b) { return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se); }
bool done[1001][1001][2];
ll dp[1001][1001][2];
ll recurse(int a = 0, int b = 0, ll px = -1, ll py = -1, int from = 0) {
    if (a == n-1 && b == m) return dist(mp(px, py), mp(h[n-1].fi, h[n-1].se));
    if(done[a][b][from]) return dp[a][b][from];
    ll ans = 1e18;
    if (a < n) min_self(ans, recurse(a + 1, b, h[a].fi, h[a].se, 0) + dist(h[a], mp(px, py)));
    if (b < m) min_self(ans, recurse(a, b + 1, g[b].fi, g[b].se, 1) + dist(g[b], mp(px, py)));
    done[a][b][from] = 1;
    return dp[a][b][from] = ans;
}
int main() {
    ifstream cin("checklist.in");
    ofstream fout("checklist.out");
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> h[i].fi >> h[i].se;
    for (int i = 0; i < m; i++) cin >> g[i].fi >> g[i].se;

    fout << recurse(1, 0, h[0].fi, h[0].se) << endl;
    return 0;
}
