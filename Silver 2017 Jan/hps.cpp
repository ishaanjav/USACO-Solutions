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
//#include <algorithm>
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
    ifstream cin("hps.in");
    ofstream fout("hps.out");

    int n;
    cin >> n;
    char ar[n];
    for (char& x : ar) cin >> x;
    int p[n];
    int h[n];
    int s[n];
    int lp[n];
    int ls[n];
    int lh[n];
    SET(p, 0);
    SET(h, 0);
    SET(s, 0);
    SET(ls, 0);
    SET(lh, 0);
    SET(lp, 0);

    p[0] = ar[0] == 'P';
    h[0] = ar[0] == 'H';
    s[0] = ar[0] == 'S';
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + (ar[i] == 'P');
        s[i] = s[i - 1] + (ar[i] == 'S');
        h[i] = h[i - 1] + (ar[i] == 'H');
    }
    lp[n - 1] = ar[n - 1] == 'P';
    lh[n - 1] = ar[n - 1] == 'H';
    ls[n - 1] = ar[n - 1] == 'S';
    for (int i = n - 2; i >= 0; i--) {
        lp[i] = lp[i + 1] + (ar[i] == 'P');
        ls[i] = ls[i + 1] + (ar[i] == 'S');
        lh[i] = lh[i + 1] + (ar[i] == 'H');
    }
    int best = max(p[n - 1], max(s[n - 1], h[n - 1]));
    for (int i = 0; i < n - 1; i++) {
        max_self(best, p[i] + lh[i + 1]);
        max_self(best, p[i] + ls[i + 1]);
        max_self(best, s[i] + lh[i + 1]);
        max_self(best, s[i] + lp[i + 1]);
        max_self(best, h[i] + ls[i + 1]);
        max_self(best, h[i] + lp[i + 1]);
    }
    cout << best;
    fout << best;
    //fout <<  << "\";

    return 0;
}
