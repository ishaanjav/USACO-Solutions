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

vector<vector<pll> > adj;
ll loc[100001];
ll id[100001];
int n, m, c;

void dfs(ll v, ll w) {
    id[v] = c;
    for (pll u : adj[v])
        if (u.se >= w && !id[u.fi]) dfs(u.fi, w);
}

bool canDo(ll w) {
    for (int i = 1; i <= n; i++) id[i] = 0;
    c = 1;
    for (int i = 1; i <= n; i++) {
        if (id[i]) continue;
        dfs(i, w);
        c++;
    }
    for (int i = 1; i <= n; i++) {
        if (id[i] != id[loc[i]]) return false;
    }
    return 1;
}

int main() {
    ifstream cin("wormsort.in");
    ofstream fout("wormsort.out");

    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> loc[i];

    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }

    ll lo = 0, hi = 1e9;
    while (lo <= hi) {
        ll mid = hi - (hi - lo) / 2;
        if (canDo(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    fout << hi << endl;
    return 0;
}