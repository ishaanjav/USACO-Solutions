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
// #include <unordered_set>
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
ll ans = 1e18;
unordered_map<int, int> name;
int root = 0;
// return length of name of file/folder given its id
vvi adj;
ll l(int a) { return name[a]; }
// is it a folder
bool is(int a) { return adj[a].size() > 0; }
vl files;  // number of files in v's subdirectory
ll totalLength = 0, totalFiles = 0;
ll dfs(int v, int depth = 0, ll nameLength = 0) {
    int cnt = adj[v].size() == 0;
    // if this is a file we have to calculate the path length to this file
    if (!is(v)) totalLength += nameLength + depth - 1 + name[v];
    // nameLength is sum of name lengths on path: folder1/folder2/ would be
    // length of folder1folder2
    if (v != root) nameLength += name[v];
    for (int child : adj[v]) cnt += dfs(child, depth + 1, nameLength);
    files[v] = cnt - (adj[v].size() == 0);
    return cnt;
}
// amt is the total length for the parent.
ll dfs2(int v, ll amt) {
    if (v != root) {
        // when we move down, all files not in our subdirectory get ../ added to
        // them the # of files not in our subdirectory is totalFiles - files[v];
        ll add = 3 * (totalFiles - files[v]);
        // the files in our subdirectory get folderName/ removed from them
        //  so they get name[v] + 1 removed. There are files[v] files
        ll subtract = files[v] * (name[v] + 1);
        amt += add - subtract;
    }
    min_self(ans, amt);
    for (int child : adj[v]) {
        if (is(child)) {
            dfs2(child, amt);
        }
    }
}
int main() {
    ifstream cin("dirtraverse.in");
    ofstream fout("dirtraverse.out");

    int n;
    cin >> n;
    adj.rs(n + 1);
    files.rs(n + 1);
    for (int i = 0; i < n; i++) {
        string nam; int children;
        cin >> nam >> children;
        if (nam == "bessie") root = i;
        name[i] = nam.length();
        totalFiles += children == 0;
        while (children--) {
            int a; cin >> a;
            adj[i].pb(a - 1);
        }
    }
    dfs(root);
    ans = totalLength;
    dfs2(root, totalLength);
    fout << ans << endl;
    return 0;
}
