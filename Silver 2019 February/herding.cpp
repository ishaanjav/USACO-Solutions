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
#define FOUnD(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "arSDFarSDF\n"
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

#include <algorithm>

int main() {
    ifstream cin("herding.in");
    ofstream fout("herding.out");

    int n;
    cin >> n;
    int ar[n];
    read(ar);
    sort(ar, ar + n);

    int best = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && ar[j] <= ar[i] + n) j++;
        max_self(best, j - i);
    }
    if (ar[n - 2] - ar[0] == n - 2 && ar[n - 1] - ar[n - 2] > 2) fout << 2;
    else if (ar[n - 1] - ar[1] == n - 2 && ar[1] - ar[0] > 2) fout << 2;
    else fout << n - best;
    fout << endl;
    fout << max(ar[n - 2] - ar[0], ar[n - 1] - ar[1]) - (n - 2) << endl;

    return 0;
}
