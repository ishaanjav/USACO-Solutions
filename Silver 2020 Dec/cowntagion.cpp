#include <iostream>
using namespace std;

#include <vector>
typedef vector<vector<int> > vvi;
#include <cmath>

vvi adj;
long long pow2(int a) { return ceil(log2(a)); }
int dfs(int v, int p) {
    int ans = pow2(adj[v].size() + (v==1));
    for(int u : adj[v]) if( u != p) ans += dfs(u, v) + 1; 
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = dfs(1, 0);
    cout << ans << endl;
}