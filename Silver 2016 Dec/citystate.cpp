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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("citystate.in");
    ofstream fout("citystate.out");

    int n;
    cin >> n;

    unordered_map<string, int> u;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (a.substr(0, 2) == b) continue;
        u[a.substr(0, 2) + b]++;
    }
    ll count = 0;
    for (pair<string, int> p : u) {
        string other = p.first.substr(2) + p.first.substr(0, 2);
        if (FOUND(u, other))
            count += p.second * u[other];
    }
    cout << (count / 2);
    fout << (count / 2);

    return 0;
}