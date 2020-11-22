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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("helpcross.in");
    ofstream fout("helpcross.out");

    int n, m;
    cin >> n >> m;
    ll chickens[n];
    pll ar[m];
    for (ll& x : chickens) cin >> x;
    for (pll& x : ar) cin >> x.fi >> x.se;

    sort(ar, ar + m);
    sort(chickens, chickens + n);

    ll counter = 0;
    int j = 0, i = 0;
    while (i < m && j < n) {
        if (ar[i].fi <= chickens[j] && ar[i].se >= chickens[j]) {
            counter++, i++, j++;
            // continue;
        }
        while (i < m && ar[i].se < chickens[j]) i++;
        while (j < n && ar[i].fi > chickens[j]) j++;
    }

    //Go through eachickens cow
    // for (int i = 0; j < n && i < m; i++) {
    //     // cout << ar[i].fi << " " << ar[i].se << endl;
    //     if (ar[i].fi <= chickens[j] && ar[i].se >= chickens[j])
    //         counter++, j++;
    //     else {
    //         while (j < n && chickens[j] < ar[i].fi) j++;
    //         if (j == n) break;
    //         if (ar[i].fi <= chickens[j] && ar[i].se >= chickens[j])
    //             counter++, j++;
    //     }
    // }
    cout << counter << endl;
    fout << counter << endl;

    return 0;
}