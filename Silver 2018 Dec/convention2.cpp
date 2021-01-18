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
#include <queue>
typedef pair<ll, pll> cow;
int n;
bool comp(cow a, cow b) {
    if (a.se.fi == b.se.fi) return a.fi < b.fi;
    return a.se.fi < b.se.fi;
}
int main() {
    ifstream cin("convention2.in");
    ofstream fout("convention2.out");

    cin >> n;
    vector<pair<ll, pll> > cows;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cows.pb(mp(i, mp(a, b)));
    }
    sort(all(cows), comp);
    priority_queue<pair<ll, pll>, vector<pair<ll, pll> >, greater<pair<ll, pll> > > pq;

    int i = 0;
    ll maxWait = 0;
    while (i != n) {
        pq.push(cows[i]);
        ll time = cows[i++].se.fi;
        while (!pq.empty()) {
            cow c = pq.top();
            pq.pop();
            max_self(maxWait, (ll)max(0ll, time - c.se.fi));
            if (time < c.se.fi) time = c.se.fi;
            time += c.se.se;  // finish time of this cow
            for (; i < n && cows[i].se.fi <= time; i++) pq.push(cows[i]);
        }
    }
    fout << maxWait << endl;
    return 0;
}