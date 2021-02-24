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
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a,c) memset(a,c,sizeof(a))
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
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
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
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>
//14
int rows, cols;
bool inBounds(int i, int j) {return i >= 0 && i < rows && j < cols && j >= 0;}
int main() {
    ifstream cin("ccski.in");
    ofstream fout("ccski.out");
    
    int n, m; cin >> n >> m;
    rows = n, cols = m;
    ll grid[n][m]; bool way[n][m];
    ll hi = 0;
    vector<pii> waywards;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){ cin >> grid[i][j]; max_self(hi, grid[i][j]);}
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> way[i][j];
            if(way[i][j]) waywards.pb(mp(i,j));
        }
    hi ++;
    if(waywards.size() == 0){
        fout << "0\n";
        return 0;
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    ll lo = 0;
    ll ans = hi;
    while(lo <= hi){
        ll D = (lo + hi)/2;
        cout << D << endl;
        bool vis[n][m]; SET(vis, false);
        queue<pii> q;
        q.push(waywards[0]);
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            if(vis[top.fi][top.se]) continue;
            vis[top.fi][top.se] = 1;
            for(int d = 0; d < 4; d++){
                int x = dx[d] + top.fi, y = dy[d] + top.se;
                if(inBounds(x,y) && !vis[x][y] && abs(grid[top.fi][top.se] - grid[x][y]) <= D)
                    q.push(mp(x,y));
            }
        }
        bool good = true;
        for(pii wayward : waywards)
            if(!vis[wayward.fi][wayward.se]) good = false;
        if(!good) lo = D + 1;
        else hi = D - 1, ans = D;
    }
    fout << ans << endl;
    return 0;
}
