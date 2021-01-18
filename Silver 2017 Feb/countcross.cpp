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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

int id[101][101];
struct pair_hash {
    inline std::size_t operator()(const std::pair<pll, pll>& v) const {
        return v.fi.fi * 10000001 + v.fi.se * 100001 + v.se.fi * 101 + v.se.se;
    }
};

unordered_set<pair<pll, pll>, pair_hash> roads;
bool inBounds(int x, int y, int n) { return x > 0 && x <= n && y > 0 && y <= n; }
int main() {
    ifstream cin("countcross.in");
    ofstream fout("countcross.out");

    int n, k, r;
    cin >> n >> k >> r;

    // Do BFS and mark id of cows
    // In the end, have a map of cow id and frequency
    // # of distant pairs is # of cow id 1 * # of cow id 2 + # of cow id 1 * # of cow id 3...
    //                     + # of cow id 2 * # of cow id 3 + ....

    unordered_map<int, ll> freq;

    while (r--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        roads.ins(mp(mp(a, b), mp(c, d)));
    }
    queue<pii> q;
    int c = 0;
    int xs[] = {0, 0, -1, 1};
    int ys[] = {1, -1, 0, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (id[i][j] != 0) continue;
            c++;

            q.push(mp(i, j));
            //            cout << "---\n";
            while (!q.empty()) {
                pii top = q.front();
                q.pop();
                if (id[top.fi][top.se] != 0) continue;
                id[top.fi][top.se] = c;
                //                cout <<  "  at " << top.fi << " " << top.se <<endl;
                for (int d = 0; d < 4; d++) {
                    int x = top.fi + xs[d], y = top.se + ys[d];
                    if (!inBounds(x, y, n) || FOUND(roads, mp(mp(x, y), top)) || FOUND(roads, mp(top, mp(x, y))) || id[x][y] == c) continue;
                    //                    cout << " going to " << x << "," << y << " from " << top.fi <<"," <<top.se<<endl;
                    q.push(mp(x, y));
                }
            }
        }
    }
    //    for(int i = 1; i <= n; i++){
    //        for(int j = 1 ; j <= n; j++){
    //            cout << id[i][j] << " ";
    //
    //        }
    //        cout <<endl;
    //    }
    cout << endl;
    while (k--) {
        int r, c;
        cin >> r >> c;
        //        cout << r << " " << c << " == " << id[r][c] << endl;
        freq[id[r][c]]++;
    }
    ll count = 0;
    for (pii p : freq) {
        //        cout << p.fi << " " << p.se <<endl;
        for (pii s : freq) {
            if (p == s) continue;
            count += p.se * s.se;
        }
    }
    count /= 2;
    cout << count;
    fout << count;

    //fout <<  << "\";

    return 0;
}
