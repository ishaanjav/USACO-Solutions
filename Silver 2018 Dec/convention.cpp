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

int n, m, c;
vl cows;
bool canDo(ll mid) {
    int buses = 0;
    for (int i = 0; i < n;) {
        buses++;
        int j = i;
        while (j < n && j - i < c && cows[j] <= cows[i] + mid) j++;
        i = j;
    }
    return buses <= m;
}
int main() {
    ifstream cin("convention.in");
    ofstream fout("convention.out");

    cin >> n >> m >> c;
    cows.resize(n);
    for (int i = 0; i < n; i++) cin >> cows[i];
    sort(all(cows));

    ll lo = 0, hi = cows[n - 1] - cows[0];
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (canDo(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    fout << ans << endl;
    return 0;
}