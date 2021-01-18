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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
#include <stack>
//#include <queue>

unordered_set<int> closed;
vvi adj;
int n, m;
ofstream fout("closing.out");
bool good(int road = 0) {
    if (closed.size() == n) return 1;
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if ((FOUND(closed, i))) continue;
        s.push(i);
        // cout << "Start: " << i << endl;
        break;
    }
    bool visited[n + 1];
    SET(visited, false);
    bool instack[n + 1];
    SET(instack, false);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (visited[v]) continue;
        visited[v] = 1;
        for (int neighbor : adj[v]) {
            if (FOUND(closed, neighbor)) continue;
            if (!visited[neighbor] && !instack[neighbor]) {
                s.push(neighbor);
                instack[neighbor] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (FOUND(closed, i)) continue;
        if (!visited[i]) return false;
    }
    return 1;
}
void solve(int f = 0) {
    cout << (good(f) ? "YES\n" : "NO\n");
    fout << (good(f) ? "YES\n" : "NO\n");
}
int main() {
    ifstream cin("closing.in");

    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    solve(0);
    for (int i = 0; i < n - 1; i++) {
        int f;
        cin >> f;
        closed.insert(f);
        // cout << "F: " << f << endl;
        solve(f);
    }
    return 0;
}
