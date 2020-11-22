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
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("rental.in");
    ofstream fout("rental.out");

    int n, m, r;
    cin >> n >> m >> r;
    vl cows, farms;
    cows.resize(n);
    farms.resize(r);
    vector<pll> shops;  //price, amt
    shops.resize(m);
    read(cows);
    for (int i = 0; i < m; i++) cin >> shops[i].se >> shops[i].fi;
    read(farms);

    sort(rall(cows));
    sort(rall(shops));
    sort(rall(farms));

    // Idea: count individually how much you earn by renting 0 to n cows and selling 0 to n cows.
    // ans is max sell[i] + rent[n-i]

    ll best = 0, cur = 0;
    int cowsLeft = n;
    int giveUpTo = min(n, r);
    ll selling[n + 1], renting[n + 1];
    SET(selling, 0);
    SET(renting, 0);

    int shop = 0;
    for (int i = 1; i <= n; i++) {
        renting[i] = renting[i - 1];
        if (i <= r) renting[i] += farms[i - 1];

        selling[i] = selling[i - 1];
        ll cap = cows[i - 1];
        ll taken = 0;
        while (shop < m && taken < cap) {
            ll &quant = shops[shop].se, val = shops[shop].fi;
            ll take = min(cap, quant);
            quant -= take;
            cap -= take;
            selling[i] += take * val;
            if (!quant) shop++;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        max_self(ans, renting[i] + selling[n - i]);
        cout << renting[i] << " " << selling[n - i] << endl;
    }
    fout << ans;

    return 0;
}
