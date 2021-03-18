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

ll tree[800000], n;
ll sum(int pos) {
    ll s = 0; pos ++;
    for (; pos >= 1; pos -= pos & -pos) s += tree[pos];
    return s;
}
void update(int pos, int val) {
    pos++;
    for (; pos <= n * 5; pos += pos & -pos) {tree[pos] += val; }
}
ll query(int x, int y) { return sum(y) - sum(x - 1); }
unordered_map<ll, ll> freq;
int main() {
    ifstream cin("haircut.in");
    ofstream fout("haircut.out");
    
    cin >> n;
    ll ar[n]; read(ar);
    ll inversions = 0;
    for(int i = 0; i< n; i++){
        freq[ar[i]] += query(ar[i] + 1, n + 2);
        update(ar[i], 1);
    }

    ll pre[n + 2];
    pre[0] = 0;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + freq[i-1];
    for(int i = 0; i < n; i++) fout << pre[i] << endl;
    return 0;
}