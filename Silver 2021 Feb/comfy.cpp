/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

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
#define pr(p) to_string(p.fi-1000) + "," + to_string(p.se-1000)
#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <queue>

int f = 2000;
bool cow[4001][4001];
int nei[4001][4001];
bool extra[4001][4001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
ll ans[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    pii ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i].fi >> ar[i].se;
        ar[i].fi += f; ar[i].se += f;
    }
    queue<pii> three;
    
    cow[ar[0].fi][ar[0].se] = 1;
    ll extraCnt = 0;
    
    for(int i = 1; i < n; i++){
        pii pt = ar[i];
        cow[pt.fi][pt.se] = 1;
        if(extra[pt.fi][pt.se]){
            extra[pt.fi][pt.se] = 0;
            extraCnt--;
            ans[i] = extraCnt;
            continue;
        }
        // Update neighbors.
        int cnt = 0;
        for(int d = 0; d < 4; d++){
            int x = dx[d] + pt.fi, y = dy[d] + pt.se;
            if(cow[x][y]){
                cnt++;
                nei[x][y]++;
                // New comfortable cow.
                if(nei[x][y] == 3) three.push(mp(x,y));
            }
        }
        nei[pt.fi][pt.se] = cnt;
        if(cnt == 3) three.push(mp(pt.fi,pt.se));
        while(!three.empty()){
            pll top = three.front();
            three.pop();
            if(nei[top.fi][top.se] != 3) continue;
            // If cow has three neighbors, need to find spot to add new cow
            // When adding new cow, increase its neighbors by 1.
            // If any neighbors become 3 then add them to queue.
            int x = -1, y = -1;
            for(int d = 0; d < 4; d++){
                x = dx[d] + top.fi, y = dy[d] + top.se;
                if(!cow[x][y]) break;
            }
            cow[x][y] = 1;
            extra[x][y] = 1;
            extraCnt++;
            // Increase the neighbors and also count how many neighbors it has.
            for(int d = 0; d < 4; d++){
                int nX = dx[d] + x, nY = dy[d] + y;
                if(cow[nX][nY]){
                    nei[nX][nY]++;
                    nei[x][y]++;
                    if(nei[nX][nY] == 3) three.push(mp(nX, nY));
                }
            }
            if(nei[x][y] == 3) three.push(mp(x, y));
        }
        
        ans[i] = extraCnt;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
