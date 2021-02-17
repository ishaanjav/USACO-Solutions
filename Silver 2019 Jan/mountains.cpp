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

#include <algorithm>

int main() {
    ifstream cin("mountains.in");
    ofstream fout("mountains.out");
    
    int n; cin >> n;
    pll ar[n];
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ar[i] = mp(a - b, a + b);
    }
    sort(ar, ar + n);
    int ans = 0, i = 0;
    while(i < n){
        ans ++;
        pll p = ar[i];
        while(i < n && (p.fi == ar[i].fi || p.se >= ar[i].se)) i++;
    }
    fout << ans << endl;
}

