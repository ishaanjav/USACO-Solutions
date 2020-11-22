#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

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

int main() {
    ifstream cin("bcount.in");
    ofstream fout("bcount.out");

    int n, q;
    cin >> n >> q;

    int a[n + 1], b[n + 1], c[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = b[i] = c[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] += a[i - 1] + (x == 1);
        b[i] += b[i - 1] + (x == 2);
        c[i] += c[i - 1] + (x == 3);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        fout << a[r] - a[l] << " " << b[r] - b[l] << " " << c[r] - c[l] << "\n";
    }
    //fout <<  << "\";

    return 0;
}