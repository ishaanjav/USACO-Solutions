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
int n, m;
string pref;
vvi adj;
int id[1000000]; int c =0;
void dfs(int v, int p){
    id[v] = c;
    for(int u : adj[v]) if(pref[u] == pref[v] && !id[u]) dfs(u, v);
}
int main() {
    ifstream cin("milkvisits.in");
    ofstream fout("milkvisits.out");

    cin >> n >> m >> pref;
    adj.resize(n + 1);
    pref = " " + pref;
    for(int i =0 ; i < n -1; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        if(id[i]) continue;
        c++;
        dfs(i, 0);
    }

    for(int i = 0; i <m ; i++){
        int a, b; char c; cin >> a >> b >> c;
        fout << (id[a] != id[b] || pref[a] == c);
    }

    return 0;
}
