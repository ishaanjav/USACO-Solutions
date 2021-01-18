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

int n;
vector<pii> points;
int main() {
    ifstream cin("moop.in");
    ofstream fout("moop.out");

    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) cin >> points[i].fi >> points[i].se;
    int LL[n + 1];  // lowest on left
    int BR[n + 1];  // biggest on right
    sort(all(points));
    LL[0] = points[0].se;
    BR[n] = points[n-1].se;
    for(int i = 1; i < n; i++) LL[i] = min(LL[i-1], points[i].se);
    for(int i = n-1; i > 0; i--) BR[i] = max(BR[i+1], points[i].se);
    int comps = 1;
    for(int i = 1; i < n; i++) if(LL[i-1] > BR[i]) comps++;
    fout << comps<<endl;
    return 0;
}
