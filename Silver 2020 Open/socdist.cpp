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

vector<pll> ar;
int n, m;
bool canDo(ll dist){
    int cows = 0;
    int i = 0;
    ll lastPos = -1e18;
    while(cows < n && i < m){
        ll first = max(lastPos + dist, ar[i].fi);
        if(first > ar[i].se){i++; continue;}
        ll length = ar[i].se - first;
        if(first <= ar[i].se) cows++;
        cows += length/dist;
        lastPos = first + length/dist * dist;
        i++;
    }
    return cows >= n;
}
int main() {
    ifstream cin("socdist.in");
    ofstream fout("socdist.out");

    cin >> n >> m;
    ll lo = 0, hi = -1;
    ar.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ar[i].fi >> ar[i].se;
        max_self(hi, ar[i].se);
    }
    sort(all(ar));
    ll ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(canDo(mid)) lo = mid + 1, ans = mid;
        else hi = mid - 1;
    }
    fout << ans << endl;
    return 0;
}