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

vector<pair<pll, int> > ar;
vi rem;
int n;
bool ys(pair<pll, int> a, pair<pll, int> b) { return a.fi.se < b.fi.se; }
ll area(int i, int j, int k) {
    int ids[] = {rem[i], rem[j], rem[k]};
    ll ax = 1e18, bx = -1, ay = 1e18, by = -1;
    for (int i = 0; i < n; i++) {
        for (int f = 0; f < 3; f++)
            if (ar[i].se == ids[f]) goto done;
        min_self(ax, ar[i].fi.fi);
        max_self(bx, ar[i].fi.fi);
        min_self(ay, ar[i].fi.se);
        max_self(by, ar[i].fi.se);
    done:;
    }
    return (bx - ax) * (by - ay);
}
void candidates() {
    sort(all(ar));
    for (int i = 0; i < 3; i++) rem.pb(ar[i].se);
    for (int i = n - 1; i > n - 4; i--) rem.pb(ar[i].se);
    sort(all(ar), ys);
    for (int i = 0; i < 3; i++) rem.pb(ar[i].se);
    for (int i = n - 1; i > n - 4; i--) rem.pb(ar[i].se);
}
int main() {
    ifstream cin("reduce.in");
    ofstream fout("reduce.out");

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar.pb(mp(mp(a, b), i));
    }
    candidates();

    int k = rem.size();
    ll lowest = 1e18;
    for (int i = 0; i < k; i++)
        for (int j = i; j < k; j++)
            for (int r = j; r < k; r++)
                min_self(lowest, area(i, j, r));
    fout << lowest << endl;
    return 0;
}
