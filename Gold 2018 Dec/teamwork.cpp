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
int n, k;
vi ar;
bool done[10001];
ll dp[10001];
ll recurse(int p = 0) {
    if (done[p]) return dp[p];
    if (p == n) return 0;
    int cur = ar[p];
    ll score = 0;
    for (int i = p; i < min(n, p + k); i++) {
        max_self(cur, ar[i]);
        max_self(score, cur * (i - p + 1) + recurse(i + 1));
    }
    done[p] = 1;
    dp[p] = score;
    return score;
}
int main() {
    ifstream cin("teamwork.in");
    ofstream fout("teamwork.out");

    cin >> n >> k;
    ar.rs(n);
    read(ar);
    ll ans = recurse();
    fout << ans << endl;
    return 0;
}
