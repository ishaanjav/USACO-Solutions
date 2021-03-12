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

// Solution:
// For each combined talent from 0 to ... find the minimum weight required to achieve that talent.
// Then, loop over each talent and find the max talent/min weight ratio.

double dp[1000000];
int main() {
    ifstream cin("talent.in");
    ofstream fout("talent.out");

    ll n, w;
    cin >> n >> w;
    double weights[n], values[n];
    double maxT = 0, bestRatio = 0;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
        maxT += values[i];
    }
    for (int i = 1; i < 1000000; i++) dp[i] = 100000000;
    dp[0] = 0;
    for (int item = 0; item < n; item++) {
        int weight = weights[item], value = values[item];
        for (int value_already = maxT - value; value_already >= 0; value_already--) 
            min_self(dp[value_already + value], dp[value_already] + weight);
            
    for (int i = 0; i <= maxT; i++) 
        if (dp[i] >= w) max_self(bestRatio, ((double)i) / dp[i]);
    ll ans = bestRatio * 1000;
    fout << ans << endl;
    return 0;
}