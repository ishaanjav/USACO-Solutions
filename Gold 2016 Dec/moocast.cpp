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

// SOLUTION
// Use O(n^2) minimum spanning tree to find how to connect the vertices (Cows)
// each time you add a vertex max your answer with that edge weight (distance ^ 2)

bool vis[10001];
pii ar[1001];
int btw(int i, int j) {
    return (ar[i].fi - ar[j].fi) * (ar[i].fi - ar[j].fi) +
           (ar[i].se - ar[j].se) * (ar[i].se - ar[j].se);
}
int main() {
    ifstream cin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i].fi >> ar[i].se;
    int dist[n + 1];  // stores squared distances
    for (int i = 0; i <= n; i++) dist[i] = 1000000000, vis[i] = 0;
    int worst = 0;
    for (int a = 0; a < n; a++) {
        int v = -1;
        for (int u = 0; u < n; u++)
            if(vis[u]) continue;
            else if ((v == -1 || dist[u] < dist[v]))  v = u;
        vis[v] = 1;
        if (a != 0) { max_self(worst, dist[v]); } 
        else dist[v] = 0;
        for (int u = 0; u < n; u++) min_self(dist[u], btw(u, v));
    }
    fout << worst << endl;
    return 0;
}
