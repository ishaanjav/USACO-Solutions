/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a,c) memset(a,c,sizeof(a))
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
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
#include <cstring>
#include <queue>

int n, m;
vector<vector<pll > > adj;
vi order;
vi path;
long long djikstra(int start = 1, int target = n) {
    vector<ll> dist(n+1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    order.resize(n+1);
    while (!pq.empty()) {
        ll v = pq.top().second, x = pq.top().first;
        pq.pop();
        if (v == target) break;
        if (x != dist[v]) continue;
        for (pair<ll, ll> i : adj[v]) {
            ll u = i.first, w = i.second;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                order[u] = v;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
    int v = n;
    while(v != 1){
        path.pb(v);
        v = order[v];
    }
    path.pb(v);
    reverse(all(path));
    return dist[target];
}
long long djik(int s1, int s2, int start = 1, int target = n) {
    vector<ll> dist(n+1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        ll v = pq.top().second, x = pq.top().first;
        pq.pop();
        if (v == target) return dist[v];
        if (x != dist[v]) {
            continue;
        }
        for (pair<ll, ll> i : adj[v]) {
            ll u = i.first, w = i.second;
            if((u == s1 && v == s2) || (u == s2 && v == s1)) w *= 2;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
    return dist[target];
}
int main() {
    ifstream cin("rblock.in");
    ofstream fout("rblock.out");
    
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    ll reg = djikstra();
    ll ans = 0;
    for(int i = 0; i < path.size() - 1; i++){
        ll res = djik(path[i], path[i+1]);
        max_self(ans, res - reg);
    }
    fout << ans << endl;
    return 0;
}
