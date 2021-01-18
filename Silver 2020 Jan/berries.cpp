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

int main() {
    ifstream cin("berries.in");
    ofstream fout("berries.out");

    int n, k;
    cin >> n >> k;
    int ar[n];
    read(ar);

    int best = 0;
    for (int m = 1; m <= 1000; m++) {
        int quants[1001];  // quants[i] ==> How many baskets with i apples.
        for (int i = 0; i < 1001; i++) quants[i] = 0;
        each(ar) quants[m] += i / m, quants[i % m]++;
        if (quants[m] < k / 2) break;
        int elsieGot = 0;
        int bessie = 0;
        int bGot = 0;
        for (int b = m; b >= 0; b--) {
            int q = quants[b];
            int elsieNeed = k / 2 - elsieGot;
            int take = min(elsieNeed, q);
            q -= take;
            elsieGot += take;
            bessie += min(k / 2 - bGot, q) * b;
            bGot += q;
            if (bGot >= k / 2) break;
        }
        // cout << bessie << endl;
        if (elsieGot < k / 2) continue;
        max_self(best, bessie);
    }

    fout << best << endl;

    return 0;
}