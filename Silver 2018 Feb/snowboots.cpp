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
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
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

#include <cstring>

int main() {
    ifstream cin("snowboots.in");
    ofstream fout("snowboots.out");

    ll n, b;
    cin >> n >> b;
    ll ar[n];
    read(ar);
    vector<pll> boots;
    for (int i = 0; i < b; i++) {
        ll x, z;
        cin >> x >> z;
        boots.pb(mp(x, z));
    }

    // pair<ll, ll> dp[n + 1];
    // for (int i = 0; i <= n; i++)
    // dp[i] = mp(-1, -1);
    // dp[0] = mp(1, 0);  //# of boots, last boot taken

    // for (int boot = 0; boot < b; boot++) {
    //     ll deep = boots[boot].fi, dist = boots[boot].se;
    //     for (int i = 1; i <= n; i++) {
    //         for (int pos = max(0ll, i - dist); pos < i; pos++) {
    //             if (dp[pos].fi == -1) continue;
    //             if (dp[i].fi == -1) {
    //                 dp[i] = mp(dp[pos].fi + 1, dp[pos].se);
    //                 continue;
    //             }
    //             int fact = (boot != dp[pos].se);
    //             if (fact + dp[pos].fi <= dp[i].fi)
    //                 dp[i] = mp(fact + dp[pos].fi, boot);
    //         }
    //     }
    // }
    ll dp[n + 1];
    SET(dp, -1);
    dp[0] = 0;
    for (int boot = 0; boot < b; boot++) {
        ll deep = boots[boot].fi, dist = boots[boot].se;
        for (int i = 1; i <= n; i++) {
            for (int pos = max(0ll, i - dist); pos < i; pos++) {
                if (ar[pos] > deep || dp[pos] == -1) continue;
                if (dp[i] == -1) {
                    dp[i] = boot;
                    continue;
                }
                min_self(dp[0], (ll)boot);
            }
        }
    }
    // for (auto p : dp) {
    //     // cout << p.fi << "," << p.se << endl;
    //     cout << p << endl;
    // }
    fout << dp[n] << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int boot = 0; boot < b; boot++) {
    //         ll deep = boots[boot].fi, dist = boots[boot].se;
    //         for (int pos = i + 1; pos < min(n, i + dist + 1); i++) {
    //             if (ar[pos] > deep) continue;
    //             if ()
    //         }
    //     }
    // }

    //fout <<  << "\n";

    return 0;
}
