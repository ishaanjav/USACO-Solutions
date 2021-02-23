/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define SET(a,c) memset(a,c,sizeof(a))
#define fi first
#define se second
#define min_self(a, b) a = min(a, b);

#include <vector>
typedef vector<int> vi;
#include <cstring>
#include <queue>
int n, c;
vector<pii> ar;
ll graph[2001][2001];
ll prim(){
    ll dist[n+1]; bool vis[n+1];
    for(int i = 0; i <= n; i++) dist[i] = 1e9;
    ll cost = 0;
    SET(vis, false);
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++)
            if(!vis[j] && (v == -1 || dist[j] < dist[v])) v = j;
        if(v == -1) return -1;
        vis[v] = 1;
        if(i == 0) dist[v] = 0;
        cost += dist[v];
        for(int u = 0; u < n; u++)
            min_self(dist[u], graph[u][v]);
    }
    for(int i = 0; i < n; i++) if(dist[i] == 1e9) return -1;
    return cost;
}
int main() {
    ifstream cin("irrigation.in");
    ofstream fout("irrigation.out");
    
    cin >> n >> c;
    ar.resize(n);
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) graph[i][j] = 1e9;
    for(int i = 0; i < n; i++){
        cin >> ar[i].fi >> ar[i].se;
        for(int j = 0; j < i; j++){
            int cost = (ar[j].fi - ar[i].fi)*(ar[j].fi - ar[i].fi) +
            (ar[j].se - ar[i].se)*(ar[j].se - ar[i].se);
            if(cost >= c)
                graph[i][j] = graph[j][i] = cost;
        }
    }
    fout << prim() << endl;
    return 0;
}
