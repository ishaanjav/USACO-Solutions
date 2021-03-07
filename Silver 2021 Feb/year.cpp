/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

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
#define SET(a,c) memset(a,c,sizeof(a))
#define MOD 1000000007
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>

ll getL(ll a){return a - (a%12) + 12;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<pll> difs;
    int ar[n+1];
    for(int i =0 ; i < n; i++) cin >> ar[i];
    ar[n] = 0; sort(ar, ar + n); reverse(ar, ar+ n);
    n++;
    int r;
    for(int i = 0; i < n;){
        r = getL(ar[i]) - 12;
        if(i == n - 1) r = -1;
        while(i < n && ar[i] > r) i++;
        if(i < n) difs.pb(mp(r - (getL(ar[i])), i - 1));
    }
    sort(rall(difs));
    vi pos;
    int cnt = 0;
    for(pll p: difs){
        pos.pb(difs[cnt++].se);
        if(cnt == k-1) break;
    }
    sort(all(pos));
    int ans = 0;
    int cur = getL(ar[0]);
    int p = 0;
    for(int i = 0; i < n; i++){
        if(p < k && pos[p] == i){
            int l = getL(ar[i]);
            ans += cur - l + 12;
            p++;
            if(i + 2 == n) { cur = 0; break; }
            cur = getL(ar[i+1]);
        }
    }
    cout << ans + cur << endl;
    return 0;
}
