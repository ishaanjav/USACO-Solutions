#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define SET(a, c) memset(a, c, sizeof(a))
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#include <vector>
typedef vector<vector<int> > vvi;
#include <algorithm>
#include <cstring>

// left most first.
bool ytop(pair<pii, int> a, pair<pii, int> b) {
    return a.fi.fi < b.fi.fi;
}
// lowest y first.
bool easts(pair<pii, int> a, pair<pii, int> b) {
    return a.fi.se < b.fi.se;
}
vvi adj;
int dfs(int v){
    int c = 0;
    for(int i: adj[v]) c += dfs(i) + 1; 
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<pii, int> > ns, es;
    adj.resize(n + 1);

    for (int i = 0; i < n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'E') {
            es.pb(mp(mp(a, b), i));
        } else
            ns.pb(mp(mp(a, b), i));
    }
    sort(all(ns), ytop);
    sort(all(es), easts);

    int p = ns.size(), q = n - p;
    bool cutOff[q + 1];
    SET(cutOff, false);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            int dy = es[j].fi.se - ns[i].fi.se;
            int dx = ns[i].fi.fi - es[j].fi.fi;
            if (cutOff[j] || dx < 0 || dy < 0 || dx == dy) continue;
            // east cuts off north
            if(dy > dx){
                adj[es[j].se].pb(ns[i].se);
                break;
            }
            // north cuts off east
            cutOff[j] = 1;
            adj[ns[i].se].pb(es[j].se);
        }
    }
    for(int i = 0; i < n; i++) cout << dfs(i) << endl;
}