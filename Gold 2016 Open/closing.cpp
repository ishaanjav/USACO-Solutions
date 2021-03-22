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
#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int n, m;
vvi adj;
unordered_set<int> inGraph;
vi parent, sizes;
int find(int v){return (parent[v] == parent[parent[v]] ? parent[v] : parent[v] = find(parent[v]));}
void merge(int a, int b){
    a = find(a), b = find(b);
    cout << "  merge " << a<< " " <<b << endl;
    if(a == b) return;
    if(sizes[b] > sizes[a]) swap(a,b);
    sizes[a] += sizes[b];
    parent[b] = a;
}
int main() {
    ifstream cin("closing.in");
    ofstream fout("closing.out");

    cin >> n >> m;
    adj.rs(n+1);
    parent.rs(n+1);
    sizes.rs(n+1, 1);
    for(int i =0 ; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi order; for(int i = 0; i < n; i++) {int a; cin >> a;order.pb(a); parent[i+1] = i + 1;}
    vb ans;
    for(int i = 0; i < n; i++){
        int add = order[n-1-i];
        // need to merge add with all of its neighbors
        for(int u : adj[add])
            if(FOUND(inGraph, u)) merge(u, add);
        bool connected = sizes[find(add)] == i + 1;
        for(int i = 1; i <= 4; i++) cout << find(i) << " ";
        cout << endl;
        inGraph.ins(add);
        ans.pb(connected || i == 0);
    }
    reverse(all(ans));
    each(ans) fout << (i?"YES\n":"NO\n");
    return 0;
}
