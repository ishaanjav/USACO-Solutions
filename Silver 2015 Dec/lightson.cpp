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
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

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

pair<int, int> decc(int i) {
    return mp(i / 110, i % 110);
}

int encc(int a, int b) {
    return a * 110 + b;
}
vi adj[25000];
bool visited[102][102];
int n, m;
bool canDo(int a, int b) {
    return (a >= 1 && a <= n && b >= 1 && b <= n);
}
int xs[] = {0, 0, -1, 1};
int ys[] = {1, -1, 0, 0};
int main() {
    ifstream cin("lightson.in");
    ofstream fout("lightson.out");

    cin >> n >> m;
    bool on[n + 1][n + 1];
    SET(on, false);
    /* for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) cout << on[i][j] << " ";
        cout << endl;
    } */
    on[1][1] = 1;
    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        // if (a == 1 && b == 1) on[x][y] = 1;
        adj[encc(a, b)].pb(encc(x, y));
    }
    bool changes = true;
    while (changes) {
        changes = false;
        queue<pair<int, int> > q;
        // q.push(mp(1, 2));
        // q.push(mp(2, 1));
        q.push(mp(1, 1));
        SET(visited, false);
        // cout << "CHAGNED\n";
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (!on[p.fi][p.se] || visited[p.fi][p.se]) continue;
            visited[p.fi][p.se] = 1;
            // cout << "AT: " << p.fi << p.second << endl;
            for (int turnedOn : adj[encc(p.fi, p.se)]) {
                pair<int, int> u = decc(turnedOn);
                int x = u.fi, y = u.se;
                // cout << "on before " << on[x][y] << endl;
                if (on[x][y]) continue;
                changes = 1;
                on[x][y] = 1;
            }
            for (int k = 0; k < 4; k++) {
                int x = p.fi + xs[k], y = p.se + ys[k];
                if (!canDo(x, y)) continue;
                q.push(mp(x, y));
                // cout << "   going to " << x << " " << y << " from " << p.fi << "," << p.se << endl;
            }
        }
    }
    int reachable = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            reachable += on[i][j];
            cout << on[i][j] << " ";
        }
        cout << endl;
    }

    fout << reachable << "\n";
    cout << reachable << "\n";

    return 0;
}
