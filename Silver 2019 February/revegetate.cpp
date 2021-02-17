/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;

#define pb push_back
#define mp make_pair
#define pib pair<int, bool>
#include <vector>
typedef vector<bool> vb;

int n, m, comp = 0;
vector<vector<pib> > adj;
vb vis;
void dfs(int v){
    if(vis[v]) return;
    vis[v] = 1;
    for(pib u : adj[v]) dfs(u.fi);
}
int main() {
    ifstream cin("revegetate.in");
    ofstream fout("revegetate.out");
    
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    for(int i = 0; i < m; i++){
        char c; int a, b; cin >> c >> a >> b;
        adj[a].pb(mp(b, c == 'S'));
        adj[b].pb(mp(a, c == 'S'));
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]) comp++, dfs(i);
    
    fout << "1";
    for(int i = 0; i < comp; i++) fout << "0";
    fout << endl;
    return 0;
}
