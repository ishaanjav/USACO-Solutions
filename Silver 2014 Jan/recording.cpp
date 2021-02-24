/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
bool finishTime(pll a, pll b){
    if(a.se != b.se) return a.se < b.se;
    return a.fi < b.fi;
}
int main() {
    ifstream cin("recording.in");
    ofstream fout("recording.out");
    
    int n;
    cin >> n;
    vector<pll> ar;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ar.pb(mp(a,b));
    }
    sort(all(ar), finishTime);
    int time1 = 0, time2 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int start = ar[i].fi;
        if(start >= time1 && start >= time2){
            if(time2 > time1) time2 = ar[i].se;
            else time1 = ar[i].se;
            ans++;
        }
        else if(start >= time1) time1 = ar[i].se, ans ++;
        else if(start >= time2) ans++, time2 = ar[i].se;
    }
    fout << ans << endl;
    return 0;
}
