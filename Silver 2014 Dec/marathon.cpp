#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int n, k;
vector<pair<ll, ll> > coo;
bool used[501][501];
ll dp[501][501];

ll firstX, firstY;
ll solve(int pos = 0, int skip = 0, ll prevX = -1, ll prevY = -1) {
    if (prevX == -1)
        prevX = firstX, prevY = firstY;
    if (used[pos][skip]) return dp[pos][skip];
    if (pos == n - 1) {
        //Calculate current stuff from prevX and return
        return abs(prevX - coo[pos].first) + abs(prevY - coo[pos].second);
    }
    ll ans = 1000000000;
    if (skip < k) {
        ans = solve(pos + 1, skip + 1, prevX, prevY);
    }
    //Calculate current from prev and then add it to below expression
    ll choice2 = solve(pos + 1, skip, coo[pos].first, coo[pos].second) + abs(prevX - coo[pos].first) + abs(prevY - coo[pos].second);
    cout << "Skipping " << pos + 1 << " = " << ans << "  not skipping: " << choice2 << endl;
    ans = min(ans, choice2);
    used[pos][skip] = 1;
    dp[pos][skip] = ans;
    return ans;
}

int main() {
    ifstream cin("marathon.in");
    ofstream fout("marathon.out");

    cin >> n >> k;
    n--;
    cin >> firstX >> firstY;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        coo.pb(mp(a, b));
    }

    ll ans = solve();
    ans = max(ans, abs(firstX - coo[n-1].first) + abs(firstY - coo[n-1].second)

    fout << ans << "\n";
    cout << ans << "\n";

    return 0;
}