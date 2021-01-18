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
    ifstream cin("cereal.in");
    ofstream fout("cereal.out");

    int n, m;
    cin >> n >> m;
    int whoHas[m + 1];  // whoHas[i] = which cow has cereal i.
    for (int i = 0; i <= m; i++) whoHas[i] = 0;
    int p1[n], p2[n];
    for (int i = 0; i < n; i++) cin >> p1[i] >> p2[i];
    int ans[n + 1];
    ans[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (!whoHas[p1[i]]) {
            whoHas[p1[i]] = i;
            ans[i] = 1 + ans[i + 1];
            continue;
        }
        ans[i] = ans[i + 1];
        int who = i;
        while (who != 0) {
            int prefer1 = whoHas[p1[who]];
            if (prefer1 == 0 || prefer1 > who) {
                if (prefer1 == 0) {
                    whoHas[p1[who]] = who;
                    ans[i]++;
                    break;
                }
                whoHas[p1[who]] = who;
                who = prefer1;
            } else {
                int prefer2 = whoHas[p2[who]];
                if (prefer2 == 0) {
                    whoHas[p2[who]] = who;
                    ans[i]++;
                    break;
                }
                if (prefer2 < who) break;
                int orig = whoHas[p2[who]];
                whoHas[p2[who]] = who;
                who = orig;
            }
        }
    }
    for (int i = 0; i < n; i++) fout << ans[i] << endl;
    return 0;
}