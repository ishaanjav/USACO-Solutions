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

#include <algorithm>

ll l, n, f, b;
vector<pll> rest;
int main() {
    ifstream cin("reststops.in");
    ofstream fout("reststops.out");

    cin >> l >> n >> f >> b;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        rest.pb(mp(b, a));
    }

    sort(all(rest));  // (tastiness, x)
    reverse(all(rest));

    ll fTime[n];
    for (int i = 0; i < n; i++) fTime[i] = rest[i].se * f;

    ll ans = 0;
    ll time = 0;
    ll last = 0;
    for (int i = 0; i < n; i++) {
        // we want to calculate from last to this x, how much time does it take her
        // this will be time + (x - last) * b;
        // we want to see how much time we have until farmer gets here (above - fTime[i])
        // if we have time, eat here.
        //    Increase ans
        //    set last to this position
        //    set time equal to farmerTime
        // if we don't have time, just continue;
        ll x = rest[i].se;
        ll getHere = time + (x - last) * b;
        ll dist = getHere - fTime[i];
        if (dist >= 0 || x < last) continue;
        // cout << "Restop at " << x << " for " << -dist << " " << getHere << endl;
        ans += -dist * rest[i].fi;  // add tastiness
        time = fTime[i];
        last = x;
    }

    fout << ans << endl;
    return 0;
}