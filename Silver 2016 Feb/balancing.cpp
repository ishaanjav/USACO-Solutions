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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
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

#include <algorithm>

vector<pii> ar;
vector<pii> by;
bool ys(pii a, pii b) {
    if (a.se != b.se) return a.se < b.se;
    return a.fi < b.fi;
}
int main() {
    ifstream cin("balancing.in");
    ofstream fout("balancing.out");

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar.pb(mp(a, b));
        by.pb(mp(a, b));
    }
    sort(all(ar));
    sort(all(by), ys);

    ll ans = n - 1;
    ll onLeft = 0, onRight = n;
    for (int i = 0; i < n;) {
        ll line = ar[i].fi + 1;
        while (i < n && ar[i].fi == line - 1) {
            onLeft++;
            onRight--;
            i++;
        }
        ll belowL = 0, belowR = 0;
        for (int j = 0; j < n;) {
            ll yLine = by[j].se;
            while (j < n && by[j].se == yLine) {
                if (by[j].fi > line)
                    belowR++;
                else
                    belowL++;
                j++;
            }
            min_self(ans, max(max(onLeft - belowL, belowL), max(onRight - belowR, belowR)));
        }
    }
    fout << ans << endl;
    return 0;
}
