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

#include <cstring>

int main() {
    ifstream cin("swap.in");
    ofstream fout("swap.out");

    int n, m, l;
    cin >> n >> m >> l;
    int ar[n + 1];
    for (int i = 1; i <= n; i++) ar[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= (b - a) / 2 + a; j++) swap(ar[j], ar[b - j + a]);
    }
    int ans[n + 1], whereIs[n + 1];
    for (int i = 1; i <= n; i++) whereIs[ar[i]] = i;

    bool done[n + 1];
    SET(done, false);
    for (int i = 1; i <= n; i++) {
        if (done[i]) continue;
        done[i] = true;
        vi places;
        int pos = whereIs[i];
        places.pb(pos);
        while (pos != i) {
            done[pos] = 1;
            pos = whereIs[pos];
            places.pb(pos);
        }
        // each(places) cout << i << endl;
        for (int i = 0; i < places.size(); i++) {
            pos = places[((i + l) % places.size())];
            ans[pos] = places[i];
        }
        // cout << endl;
    }
    for (int i = 1; i <= n; i++) fout << ans[i] << endl;

    return 0;
}