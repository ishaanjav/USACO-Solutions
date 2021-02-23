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
#define pii pair<int, int>
#define SET(a,c) memset(a,c,sizeof(a))
#define endl "\n"
#define fi first
#define se second
#define min_self(a, b) a = min(a, b);

#include <vector>
#include <cstring>
#include <queue>

bool reach[201][201];
bool vis[201];
int main() {
    ifstream cin("moocast.in");
    ofstream fout("moocast.out");
    
    int n; cin >> n;
    vector<pair<pii, int> > cows;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        cows.pb(mp(mp(a,b),c));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll dist = (cows[i].fi.fi - cows[j].fi.fi)*(cows[i].fi.fi - cows[j].fi.fi)
            + (cows[i].fi.se - cows[j].fi.se) * (cows[i].fi.se - cows[j].fi.se);
            reach[i][j] = dist <= cows[i].se * cows[i].se;
            reach[j][i] = dist <= cows[j].se * cows[j].se;
        }
    }
    ll ans = 0;
    for(int src = 0; src < n; src++){
        SET(vis, false);
        ll cur = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(vis[top]) continue;
            vis[top] = 1;
            cur++;
            for(int v = 0; v < n; v++)
            if(!vis[v] && reach[top][v]) q.push(v);
        }
        max_self(ans, cur);
    }
    fout << ans << endl;
    return 0;
}
