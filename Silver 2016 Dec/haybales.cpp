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
    ifstream cin("haybales.in");
    ofstream fout("haybales.out");

    int n, q;
    cin >> n >> q;
    int ar[n];
    int smallest = 1000000009;
    int biggest = -1;
    for (int &x : ar) {
        cin >> x;
        min_self(smallest, x);
        max_self(biggest, x);
    }

    sort(ar, ar + n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > biggest || b < smallest) {
            cout << 0 << endl;
            fout << 0 << endl;
            continue;
        }
        //binary search
        // - search for smallest >= a
        // - search for biggest <= b
        int lo = 0, hi = n - 1;
        int b1 = n - 1, b2 = 0;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            int v = ar[mid];
            if (v >= a) {
                min_self(b1, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            int v = ar[mid];
            if (v > b) {
                hi = mid - 1;
            } else {
                max_self(b2, mid);
                lo = mid + 1;
            }
        }
        cout << b2 - b1 + 1 << endl;
        fout << b2 - b1 + 1 << endl;
    }

    return 0;
}