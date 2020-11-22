#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

int a, b, together;
int n, m;
vector<vector<ll> > adj;
vector<ll> aD, bD;
vector<ll> distFromEnd;
bool visited[50000];

vector<ll> bfs(int src){
    vector<ll> dist(n, -1);
    queue<int> q;
    dist[src] =0;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : adj[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}
int main() {
    ifstream cin("piggyback.in");
    ofstream fout("piggyback.out");

    cin >> a >> b >> together >> n >> m;
    adj.resize(n);
    bD.assign(n, 100000);
    aD.assign(n, 100000);
    distFromEnd.assign(n, 100000);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(visited, false, sizeof(visited));
    aD[0] = 0;
    bD[1] = 0;
    
    vector<ll> aD = bfs(0);
    vector<ll> bD = bfs(1);
    vector<ll> distFromEnd = bfs(n -1);    


    /* for (int i = 0; i < n; i++)
        cout << i + 1 << ":  " << aD[i] << " " << bD[i] << "  |  " << distFromEnd[i] << "\n";
 */
    ll ans = aD[n - 1] * a + bD[n - 1] * b;
    for (int i = 0; i < n; i++) {
        ans = min(ans, aD[i] * a + bD[i] * b + distFromEnd[i] * together);
    }
    cout << ans << endl;
    fout << ans << endl;

    return 0;
}