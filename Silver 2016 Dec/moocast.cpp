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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
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
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
#include <cmath>
#include <cstring>
#include <unordered_map>
//#include <sstream>
//#include <stack>
#include <queue>

vi parent, sizes;

int findParent(int p) {
    if (parent[p] != parent[parent[p]]) parent[p] = findParent(parent[p]);
    return parent[p];
}
void unionNodes(int a, int b) {
    a = findParent(a), b = findParent(b);
    if (a == b) return;
    // cout << " union " << a << " " << b << endl;
    if (sizes[b] > sizes[a]) swap(a, b);
    sizes[a] += sizes[b];
    parent[b] = parent[a];
}

ll calc(pair<pii, int> a, pair<pii, int> b) {
    return ((a.fi.fi - b.fi.fi) * (a.fi.fi - b.fi.fi) + (a.fi.se - b.fi.se) * (a.fi.second - b.fi.se));
}

int main() {
    ifstream cin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    cin >> n;
    pair<pii, double> ar[n];
    parent.resize(n);
    sizes.resize(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].fi.fi >> ar[i].fi.se >> ar[i].se;
        parent[i] = i;
    }
    sort(ar, ar + n);

    // for (int i = 0; i < n; i++) {
    //     double r = ar[i].se;
    //     for (int j = i + 1; j < n && ar[j].fi.fi <= ar[i].fi.fi + r; j++) {
    //         double dist = calc(ar[i], ar[j]);
    //         if (dist <= r * r) {
    //             unionNodes(i, j);
    //             // cout << "  " << r << "  | " << ar[i].fi.fi << " " << ar[i].fi.se << "  , " << ar[j].fi.fi << " " << ar[j].fi.se << endl;
    //         }
    //     }
    // }
    bool adj[n][n];
    SET(adj, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (calc(ar[i], ar[j]) < ar[i].se * ar[i].se) adj[i][j] = 1;
        }
    }
    int best = 1;
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        bool visited[n];
        SET(visited, false);
        int cur = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (visited[v]) continue;
            visited[v] = 1;
            cur++;
            for (int j = 0; j < n; j++) {
                if (adj[v][j])
                    q.push(j);
            }
        }
        max_self(best, cur);
    }

    cout << best << endl;
    fout << best << endl;
    //fout <<  << "\";

    return 0;
}
