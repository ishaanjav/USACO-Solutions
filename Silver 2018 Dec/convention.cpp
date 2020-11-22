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

// #include <algorithm>
#include <algorithm>

int n, m, c;
bool canDo(ll dif, ll ar[]) {
    int busCount = 0;
    for (int i = 0; i < n;) {
        int cap = 0;
        ll first = ar[i];
        bool changed = false;
        while (i < n && cap < c && first + dif >= ar[i]) {
            i++;
            cap++;
            changed = true;
        }
        if (!changed) i++;
        busCount++;
    }
    return busCount <= m;
}
int main() {
    ifstream cin("convention.in");
    ofstream fout("convention.out");

    cin >> n >> m >> c;
    ll ar[n];
    read(ar);
    sort(ar, ar + n);

    ll lo = 1, hi = 1e10;
    sort(ar, ar + n);

    ll ans = ar[n - 1] - ar[0];
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (canDo(mid, ar)) {
            hi = mid - 1;
            ans = mid;
        } else
            lo = mid + 1;
    }

    fout << ans << "\n";

    return 0;
}
