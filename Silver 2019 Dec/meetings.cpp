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
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#include <vector>
#include <algorithm>

int main() {
    ifstream cin("meetings.in");
    ofstream fout("meetings.out");

    ll n, l;
    cin >> n >> l;
    ll totalW = 0;
    vector<pair<int, pll> > ar;  // (x, (w, 1 if right))
    vector<ll> rT, lT;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        totalW += a;
        ar.pb(mp(b, mp(a, c)));
        if (c == -1) lT.pb(b);
        else rT.pb(l - b);
    }
    sort(all(ar)); sort(all(rT)); sort(all(lT));
    vector<pll> times;
    int j = lT.size(), k = rT.size() - 1;
    for (int i = 0; i < n; i++) 
        {if (i < j) times.pb(mp(lT[i], ar[i].se.fi));
        else times.pb(mp(rT[k--], ar[i].se.fi));}

    sort(all(times));
    ll weight, t = 0;
    for (auto p : times) {
        weight += p.se;
        t = p.fi;
        if (weight * 2 >= totalW) break;
    }
    int intersections = 0;
    for (auto p : ar) 
        if (p.se.se == 1) intersections += lower_bound(all(lT), p.fi) - upper_bound(all(lT), p.fi + 2 * t);
    fout << -intersections << endl;
    return 0;
}
