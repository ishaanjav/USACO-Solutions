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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>

// About an hour

// IDEA:
// 1. Do Djikstra from vertex n and reverse edges to find shortest distance from n to each vertex for both gps types.
//   a. When doing Djikstra, keep track of which vertex we have to go to next. 5 --> 4 --> 3 . Because the edges are reversed, goTo[3] = 4.
// 2. Now again do djikstra but store <# honks, vertex> when going to a vertex in prioirty queue.
//   a. To calculate number of honks when going to neighboring vertex, just check if neighbor (u) = goTo[v] then no honks required because v to u is on shortest path. Otherwise, increase honks by 1. Do it for both GPS.
//   b. Add it to priority queue with new # of honks.

// IMPORTANT NOTE: If edge a --> b and dist[a] - dist[b] = edgeWeight(a,b), then a and b are on the same shortest path to n.
#include <queue>
vector<vector<pair<int, pll> > > adj, jda; // vertex, cost1, cost2
vl dist1, dist2;
int n, m;
vi goTo1, goTo2;
void djik(int target, vector<ll> & dist, vi & goTo, int t = 0) {
    int start = n;
    dist.resize(target+1);
    goTo.resize(target+1);
    for(int i = 0; i<=n; i++) dist[i] = 1e17;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    goTo[start] = -1;
    while (!pq.empty()) {
        ll v = pq.top().second, x = pq.top().first;
        pq.pop();
        if (x != dist[v]) {
            continue;
        }
        for (pair<int, pll> i : jda[v]) {
            ll u = i.first, w = i.se.second;
            if(t == 0) w = i.se.fi;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                goTo[u] = v;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
}
int djikstra(){
    vl honks(n+1);
    for(int i = 0; i<=n; i++) honks[i] = 1e17;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push(make_pair(0, 1));
    honks[1] = 0;
    while (!pq.empty()) {
        ll v = pq.top().second, x = pq.top().first;
        pq.pop();
        if(v == n) return x;
        if (x != honks[v]) {
            continue;
        }
        for (pair<int, pll> i : adj[v]) {
            ll u = i.first;
            int weight = 0;
            weight += goTo1[v] != u;
            weight += goTo2[v] != u;
            if (honks[u] > honks[v] + weight) {
                honks[u] = honks[v] + weight;
                pq.push(make_pair(honks[u], u));
            }
        }
    }
}
int main() {
    ifstream cin("gpsduel.in");
    ofstream fout("gpsduel.out");
    
  cin >> n >> m;
    adj.resize(n+1);
    jda.resize(n+1);
    for(int i = 0; i < m; i++){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].pb(mp(b,mp(c,d)));
        jda[b].pb(mp(a,mp(c,d)));
    }
    djik(n, dist1, goTo1);
    djik(n, dist2, goTo2, 1);
    fout << djikstra()<< endl;
    return 0;
}
