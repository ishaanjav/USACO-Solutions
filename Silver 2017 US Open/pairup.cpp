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
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")

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

int main() {
    ifstream cin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    cin >> n;
    vector<pair<ll, int> > cows;
    int c = 0;
    int m = n;
    while (m--) {
        int a;
        cin >> a;
        c += a;
        int b;
        cin >> b;
        cows.pb(mp(b, a));
    }

    sort(all(cows));

    ll worst = 0;
    int left = 0, right = n - 1;

    while (left <= right) {
        max_self(worst, cows[left].fi + cows[right].fi);
        int minTake = min(cows[left].se, cows[right].se);
        cows[left].se -= minTake;
        cows[right].se -= minTake;
        if (cows[right].se <= 0) right--;
        if (cows[left].se <= 0) left++;
        // cout << cows[left].se << "  | " << cows[right].se << endl;
        // cout << left << " " << right << endl;
    }
    fout << worst << endl;

    //fout <<  << "\";

    return 0;
}
