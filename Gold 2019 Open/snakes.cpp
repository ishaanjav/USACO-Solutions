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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vi ar;
int n, k;
unordered_map<int, int> comp;
const int nax = 401;
bool done[nax][nax];
int dp[nax][nax];
int recurse(int p = 0, int changes = -1) {
    if (p == n) return 0;
    if (changes == k) return -1;
    if (done[p][changes + 1]) return dp[p][changes + 1];
    int value = -1;
    int sum = 0;
    int biggest = 0;
    for (int i = p; i < n; i++) {
        max_self(biggest, ar[i]);
        sum += ar[i];
        int res = recurse(i + 1, changes + 1);
        if (res != -1) {
            if (value == -1) value = (biggest * (i - p + 1) - sum) + res;
            else min_self(value, (biggest * (i - p + 1) - sum) + res);
        }
    }
    done[p][changes + 1] = 1;
    dp[p][changes + 1] = value;
    return value;
}
int main() {
    ifstream cin("snakes.in");
    ofstream fout("snakes.out");

    cin >> n >> k;
    ar.rs(n);
    read(ar);
    int c = 1;
    for (int i = 0; i < n; i++)
        if (comp[ar[i]] == 0) comp[ar[i]] = c++;
    fout << recurse() << endl;
    return 0;
}
