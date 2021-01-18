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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
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

// 9/8/20
// Solved 26:22

int main() {
    ifstream cin("angry.in");
    ofstream fout("angry.out");

    int n, cows;
    cin >> n >> cows;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);

    ll lo = 1, hi = ar[n - 1] - ar[0];
    ll ans = -1;
    while (lo <= hi) {
        ll radius = (lo + hi) / 2;
        bool works = 1;

        int p = 0;
        ll place = ar[0] + radius;
        for (int i = 0; i < cows; i++) {
            while (p < n && place + radius >= ar[p]) {
                p++;
            }
            if (p == n) break;
            place = ar[p] + radius;
        }
        if (p != n) works = 0;
        // cout << radius << endl;
        if (!works) {
            lo = radius + 1;
        } else
            hi = radius - 1, ans = radius;
    }

    cout << ans;
    fout << ans;

    return 0;
}
