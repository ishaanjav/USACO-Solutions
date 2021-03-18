/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a,c) memset(a,c,sizeof(a))
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
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
#define eachv(ar, i) for (auto i : ar)

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
//#include <set>
// #include <map>
//#include <unordered_set>
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int tree[200000], n;
unordered_map<int, int> u;
int sum(int pos) {
    int s = 0;
    for (; pos >= 1; pos -= pos & -pos) s += tree[pos];
    return s;
}
void update(int pos, int val) {
    for (; pos <= n; pos += pos & -pos) tree[pos] += val;
}
int query(int x, int y) { return sum(y) - sum(x - 1); }
void set(int pos, int val) { update(pos, val - query(pos, pos)); }

void initialize(int ar[]) {
    for (int i = 1; i <= n; i++) {
        tree[i] += ar[i - 1];
        if (i + (i & -i) <= n) tree[i + (i & -i)] += tree[i];
    }
}
int main() {
    ifstream cin("bphoto.in");
    ofstream fout("bphoto.out");
    
    cin >> n;
    int l[n], r[n], ans = 0, cnt = 0, ar[n], cp[n]; read(ar);
    for(int i = 0; i < n; i++) cp[i] = ar[i];
    sort(cp, cp + n);

    for(int i = 0; i < n; i++){
        if (u[cp[i]]) continue;
        u[cp[i]] = ++cnt;
    }
    for(int i = 0; i < n; i++){
        update(u[ar[i]], 1);
        l[i] = query(u[ar[i]] + 1, n);
    }
    for(int i = 0; i <= n + 2; i++) tree[i] = 0;
    for (int i = n-1; i >= 0; i--) {
        int r = query(u[ar[i]] + 1, n);
        if(((r == 0 && l[i] != 0) || (l[i] == 0 && r != 0)) || (r != 0 && l[i] != 0 && ((l[i] * 2 < r) || (r * 2 < l[i]))))
            ans++;
        update(u[ar[i]], 1);
    }
    fout << ans << endl;
    return 0;
}
