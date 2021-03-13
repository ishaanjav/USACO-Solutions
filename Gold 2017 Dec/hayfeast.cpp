/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define fi first
#define se second
#define rs resize
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
#include <cmath>
#include <unordered_map>

vector<vl> table;
vl pows;
unordered_map<int, int> logs;
ll query(int l, int r) {
    l--, r--;
    int size = r + 1 - l;
    int query;
    int row = logs[pows[size]];
    if (pows[size] == size) {
        query = table[row][l];
    } else {
        query = max(table[row][l], table[row][r + 1 - pows[size]]);
    }
    return query;
}
int main() {
    ifstream cin("hayfeast.in");
    ofstream fout("hayfeast.out");

    ll n, m;
    cin >> n >> m;
    pll ar[n];
    for (pll& p : ar) cin >> p.fi >> p.se;

    int levels = log2(n) + 1;
    table.resize(levels, vl(n, 0));

    pows.rs(n + 1);
    int p = 1;

    // PRECOMPUTING LOGS AND POWERS
    int l = 0;
    logs[1] = l++;
    for (int i = 0; i < n; i++) {
        table[0][i] = ar[i].se;
        pows[i + 1] = p;
        if (i + 2 == p * 2) {
            p *= 2;
            logs[i + 2] = l++;
        }
    }

    // PREPROCESSING
    for (int level = 1; level < levels; level++) {
        int size = 1 << level;  // size of interval
        for (int i = 0; i <= n - size; i++)
            table[level][i] =
                max(table[level - 1][i], table[level - 1][i + size / 2]);
    }
    ll cur = 0, right = 0, ans = 1e18;
    for (int i = 0; i < n;) {
        while (right < n && cur < m) 
            cur += ar[right].fi, right++;
        if (cur < m) break;
        min_self(ans, query(i+1, right));
        cur -= ar[i++].fi;
    }
    fout << ans << endl;
    return 0;
}
