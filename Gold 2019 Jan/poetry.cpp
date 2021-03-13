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
const int nax = 5001;
ll dp[nax];
int n, m, k;

unordered_map<int, vi> type;  // type[t] = vector of syllable lengths
unordered_map<int, ll> num;
vi ar;
void builddp() {
    dp[0] = 1;
    for (int j = 1; j <= k; j++) {
        dp[j] = 0;
        for (int word = 0; word < n; word++)
            if (ar[word] <= j) dp[j] += dp[j - ar[word]];
        dp[j] %= MOD;
    }
}
ll exp(int base, int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return base % MOD;
    ll ans = exp(base, pow / 2);
    ans = (ans * ans) % MOD;
    if (pow % 2) ans = (ans * base) % MOD;
    return ans % MOD;
}

int main() {
    ifstream cin("poetry.in");
    ofstream fout("poetry.out");

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar.pb(a);
        type[b].pb(a);
    }
    builddp();
    // for (int i = 0; i <= k; i++) cout << dp[i] << " ";
    for (auto p : type) {
        ll sum = 0;
        for (int len : p.se) {
            sum += dp[k - len];
            sum %= MOD;
        }
        num[p.fi] = sum % MOD;
    }
    ll ans = 1;
    n = num.size();
    vl var;
    for (auto p : num) var.pb(p.se);

    unordered_map<char, int> freq;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        freq[c]++;
    }
    for (auto p : freq) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += exp(var[i], p.se);
        }
        sum %= MOD;
        ans *= sum;
        ans %= MOD;
    }
    fout << ans << endl;
    return 0;
}
