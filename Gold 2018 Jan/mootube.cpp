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
#define mp make_pair
#define pll pair<ll, ll>

vector<vector<pll> > adj;
int dfs(ll v, ll k, ll p = 0) {
    ll cur = 1;
    for (pll u : adj[v])
        if (u.se >= k && u.fi != p) cur += dfs(u.fi, k, v);
    return cur;
}
int main() {
    ifstream cin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    cin >> n >> q;
    adj.rs(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    while (q--) {
        ll k, v; cin >> k >> v;
        fout << dfs(v, k) - 1 << endl;
    }
    return 0;
}
