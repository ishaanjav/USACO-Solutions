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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")

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

int main() {
    ifstream cin("homework.in");
    ofstream fout("homework.out");

    int n;
    cin >> n;

    vi ans;
    int ar[n];
    for (int& x : ar) cin >> x;

    ll mi = min(ar[n - 1], ar[n - 2]);
    ll sum = ar[n - 1] + ar[n - 2];
    ans.pb(n - 2);

    ll best = sum - mi;
    ll count = 1;

    for (int i = n - 3; i >= 1; i--) {
        sum += ar[i];
        min_self(mi, (ll)ar[i]);
        ll f1 = (sum - mi) * (count);
        ll f2 = best * (n - i - 1);
        // cout << mi << " , " << i << "   " << f1 << "," << f2 << endl;
        if (f1 == f2) {
            ans.pb(i);
        } else if (f2 < f1) {
            best = sum - mi;
            ans.clear();
            ans.pb(i);
            count = n - i - 1;
            // cout << "  best now " << best << "," << count << endl;
        }
    }

    for (int i : ans) {
        fout << i << endl;
    }

    //fout <<  << "\n";

    return 0;
}
