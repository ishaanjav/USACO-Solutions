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
#include <algorithm>
#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

ll area(multiset<ll> a, multiset<ll> b) {
    ll lo = *a.begin(), hi = *(--a.end());  // for xs
    ll l = *b.begin(), h = *(--b.end());    // for ys
    return (hi - lo) * (h - l);
}
int main() {
    ifstream cin("split.in");
    ofstream fout("split.out");

    int n;
    cin >> n;
    multiset<ll> lx, ly, ux, uy;
    pii ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i].fi >> ar[i].se;
        ux.ins(ar[i].fi);
        uy.ins(ar[i].se);
    }
    sort(ar, ar + n);
    ll ans = area(ux, uy);
    ll total = ans;
    for (int i = 0; i < n - 1; i++) {
        ll x = ar[i].fi, y = ar[i].se;
        ux.erase(ux.lower_bound(x));
        uy.erase(uy.lower_bound(y));
        lx.ins(x);
        ly.ins(y);
        min_self(ans, area(lx, ly) + area(ux, uy));
    }
    fout << total - ans << endl;
    return 0;
}
