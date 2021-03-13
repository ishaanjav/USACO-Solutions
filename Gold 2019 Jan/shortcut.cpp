/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
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
#include <queue>

// Solution:
// 1. Do Djikstra and find shortest path from 1 to all other vertices
//   a. Keep track of best previous vertex to take in vector called "pre"
// 2. Construct a directed graph with root at 1. Edges go in direction of best path.
// 3. DFS the directed graph. The function returns the # of cows that will arrive at the current vertex
//   a. Add this amount to the # of cows already at the vertex from the start.
//   b. The amount saved by connecting this vertex to 1 is total # of cows * (distance[vertex] - t)
//   c. Choose the maximum answer and print it

int n, m, t;
vi sizes;
vector<vector<pll> > adj;
vi pre;
bool vis[10001];
vvi jda;
int into[10001];
vector<ll> dist;
long long djikstra(int start = 1, int target = n) {
    dist.assign(n + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >
        pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        ll x = pq.top().first;
        pq.pop();
        if (x != dist[v]) {
            continue;
        }
        for (pair<ll, ll> i : adj[v]) {
            int u = i.first, w = i.second;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pre[u] = v;
                pq.push(make_pair(dist[u], u));
            } else if (dist[u] == dist[v] + w)
                min_self(pre[u], v);
        }
    }
    return dist[target];
}
ll ans = 0;
int dfs(int v = 1) {
    int cows = sizes[v];
    for (int u : jda[v]) cows += dfs(u);
    max_self(ans, cows * (dist[v] - t));
    return cows;
}
int main() {
    ifstream cin("shortcut.in");
    ofstream fout("shortcut.out");

    cin >> n >> m >> t;
    sizes.rs(n + 1);
    adj.rs(n + 1);
    pre.rs(n + 1);
    for (int i = 1; i <= n; i++) cin >> sizes[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    djikstra(1);
    jda.rs(n + 1);
    for (int i = 1; i <= n; i++) jda[pre[i]].pb(i);
    dfs();
    fout << ans << endl;
    return 0;
}
