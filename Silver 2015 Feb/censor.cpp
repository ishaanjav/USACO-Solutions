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
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

#define mod 1000000007
#define base 101
#define HA 100000007

int main() {
    ifstream cin("censor.in");
    ofstream fout("censor.out");

    string s, k;
    cin >> s >> k;
    vector<ll> pows(1, 1), hash(1, 0);
    string ans = "";
    int tHash = 0;
    for (int i = 0; i < k.length(); i++) {
        tHash = (tHash * HA + base + (k[i] - 'a')) % mod;
    }
    cout << tHash << endl
         << endl;
    for (int i = 0; i < s.length(); i++) {
        ans += s[i];
        hash.pb(((hash.back() * HA + base + (s[i] - 'a'))) % mod);
        pows.pb((pows.back() * base) % mod);
        if (ans.size() >= k.length()) {
            ll hashSubstring = (hash[ans.size() - k.length()] * pows[k.length()]) % mod;
            ll substringHash = (mod + hash.back() - hashSubstring) % mod;
            if (substringHash == tHash && ans.substr(ans.size() - k.length()) == k) {
                ans.resize(ans.size() - k.length());
                hash.resize(hash.size() - k.length());
                pows.resize(pows.size() - k.length());
            }
        }
    }

    fout << ans << endl;
    cout << ans << endl;

    return 0;
}
