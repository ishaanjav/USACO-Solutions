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
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#include <vector>
#include <unordered_map>
#include <algorithm>

bool comp(pair<pii, int> a, pair<pii, int> b){
    if(a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
    return a.fi.fi < b.fi.fi;
}
int main() {
    ifstream cin("triangles.in");
    ofstream fout("triangles.out");
    
    int n; cin >> n;
    vector<pair<pll, int> > ar;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ar.pb(mp(mp(a,b), i));
    }
    unordered_map<int, ll> ys, xs; // xs[id] = sum of all horizontal distances from point with id.
    sort(all(ar));

    for(int i = 0; i < n;){
        int j = i;
        vector<pii> points;
        while(j < n && ar[i].fi.fi == ar[j].fi.fi){
            points.pb(ar[j].fi);
            j++;
        }
        ll sum = 0; // all points in points have the same x.
        ll y = points[0].se; // the lowest y
        for(int p = i+1; p < j; p++)
            sum += points[p-i].se - y;
        ys[ar[i].se] = sum;
        // when we move up to the 2nd lowest point,
        //  we get closer to n-1 of the points and farther from 1 point = closer to n - 2.
        //   this is over a distance of points[p+1].y - points[p].y
        int m = points.size();
        for(int p = 1; p < m; p++){
            int closerTo = m - p;
            int fartherFrom = p;
            int distance = points[p].se - points[p-1].se;
            sum += distance * (fartherFrom - closerTo);
            ys[ar[i+p].se] = sum;
        }
        i = j;
    }
    
    sort(all(ar), comp);
    for(int i = 0; i < n;){
        int j = i;
        vector<pii> points;
        while(j < n && ar[i].fi.se == ar[j].fi.se){
            points.pb(ar[j].fi);
            j++;
        }
        ll sum = 0; // all points in points have the same y.
        ll y = points[0].fi; // the lowest x
        for(int p = i+1; p < j; p++)
            sum += points[p-i].fi - y;
        xs[ar[i].se] = sum;
        int m = points.size();
        for(int p = 1; p < m; p++){
            int closerTo = m - p;
            int fartherFrom = p;
            int distance = points[p].fi - points[p-1].fi;
            sum += distance * (fartherFrom - closerTo);
            xs[ar[i+p].se] = sum;
        }
        i = j;
    }
    ll ans = 0;
    for(int i =0 ; i < n; i++){
        ans += ys[ar[i].se] * xs[ar[i].se];
        ans %= MOD;
    }
    fout << ans << endl;
    return 0;
}
