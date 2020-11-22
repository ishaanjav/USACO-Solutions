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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("cowcode.in");
    ofstream fout("cowcode.out");

    string s;
    cin >> s;
    ll n;
    cin >> n;
    vector<ll> pows;
    ll length = s.length();
    pows.pb(s.length());
    ll last = length;
    while (pows.back() < n) {
        pows.pb(2 * last);
        last = pows.back();
    }
    if (pows.back() > s.length()) pows.pop_back();
    while (n > s.length()) {
        // ll mod = n % pows.back() + 1;
        // n -= mod;
        while (pows.back() > n) pows.pop_back();
        n = n - pows.back() - 1;
        if (n == length + 1)
            n = length;
        else if (n == 0)
            n = pows.back();
        pows.pop_back();
        // cout << n << endl;
    }
    cout << s[n - 1];
    fout << s[n - 1];
    // cout << s << endl;
    //fout <<  << "\";

    return 0;
}