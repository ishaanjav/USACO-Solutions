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
    ifstream cin("maxcross.in");
    ofstream fout("maxcross.out");

    int n, k, b;
    cin >> n >> k >> b;
    bool broken[n + 1];
    SET(broken, false);

    while (b--) {
        int a;
        cin >> a;
        broken[a] = 1;
    }

    int ans = k;
    int cur = 0;
    for (int i = 1; i <= k; i++)
        cur += broken[i];
    min_self(ans, cur);

    for (int i = k + 1; i <= n; i++) {
        if (broken[i]) cur++;
        if (broken[i - k]) cur--;

        min_self(ans, cur);
    }

    cout << ans;
    fout << ans;

    //fout <<  << "\";

    return 0;
}
