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
vvi adj;
int cl[2501];
// 1/14/21
// My approach is a good strategy to think of for whenever there is a DFS tree problem
// Idea is we know for a fact there is only one way to make leaves into 12:
//   - keep repeating leaf parent and leaf until the leaf is 12
// So the idea for my soultion is the dfs function returns the new clock value of the child.
// We have to make the child 12 by going back and forth between parent and child.
// So curNum (clock of parent) will += 12 - child's clock because we HAVE TO make child's clock 12.
// We do this for every child the parent has and return the curNum %12
//  This is the parent's new clock
// Now if the parent had a parent, its parent will do the same to it and increase its value if not a 12
//  until we finally return the value of curNum from the initial call with the root.
// In loop on line 90, we check if value of dfs was 0 mod 12 or if value was 1, we can use this root
// Reason we include 1 is because dfs returns going parent---child---parent. The last child to parent
// step is not necessary if parent is already 12.
int dfs(int v, int par = 0) {
    int curNum = cl[v];
    for (int u : adj[v]) {
        if (u == par) continue;
        int newChild = dfs(u, v);
        curNum += 12 - newChild;  // This includes when Bessie returns
    }
    curNum %= 12;
    return curNum;
}
int main() {
    ifstream cin("clocktree.in");
    ofstream fout("clocktree.out");

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> cl[i + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int val = dfs(i);
        ans += ((val % 12 == 0) || (val == 1 && adj[i].size() > 0));
    }

    fout << ans << endl;
    return 0;
}