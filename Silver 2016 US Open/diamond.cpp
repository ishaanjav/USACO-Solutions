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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("diamond.in");
    ofstream fout("diamond.out");

    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int& x : ar) cin >> x;

    sort(ar, ar + n);
    int l[n], r[n];
    SET(l, 0);
    SET(r, 0);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && ar[j] + k < ar[i]) j++;
        int dist = i - j + 1;
        l[i] = dist;
        if (i > 0) max_self(l[i], l[i - 1]);
    }
    j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 && ar[j] - k > ar[i]) {
            j--;
        }
        int dist = j - i + 1;
        r[i] = dist;
        if (i < n - 1) max_self(r[i], r[i + 1]);
    }
    int ans = min(2, n);
    for (int i = 0; i < n - 1; i++) {
        max_self(ans, l[i] + r[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] << " " << r[i] << endl;
    }
    cout << ans << endl;
    fout << ans << endl;

    return 0;
}
