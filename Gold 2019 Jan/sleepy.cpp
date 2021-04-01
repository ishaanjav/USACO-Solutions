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
// #include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
int tree[200000];
int n;

// Solution. The minimum # of moves is n - the size of the largest increasing suffix
// For each value at the front, it needs to pass the other "bad" cows that were in the original prefix
//   and then go into its correct position in the sorted end of the array
//   to count which index it goes into in the sorted array (how many additional cows must be passed), we use a BIT

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}
void update(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k & -k;
    }
}
int main() {
    ifstream cin("sleepy.in");
    ofstream fout("sleepy.out");

    cin >> n;
    int ar[n];
    read(ar);
    int req = n;
    int prev = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ar[i] < prev) req--, prev = ar[i];
        else break;
    }
    for(int i = req; i < n; i++) update(ar[i], 1);
    fout << req << endl;
    if (req) {
        vi ans;
        for (int i = 0; i < req; i++) {
            int skipOver = req - i - 1;
            ans.pb(skipOver + sum(ar[i]));
            update(ar[i], 1);
        }
        for (int i = 0; i < ans.size(); i++) {
            fout << ans[i];
            if (i < ans.size() - 1) fout << " ";
        }
        fout << endl;
    }

    return 0;
}
