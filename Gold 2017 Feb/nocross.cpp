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
int n;
vi a, b;
bool done[1001][1001]; int dp[1001][1001];
int recurse(int p = 0, int p2 = 0){
    if(p == n || p2 == n){ return 0; }
    if(done[p][p2]) return dp[p][p2];
    int cnt = recurse(p + 1, p2);
    for(int i = p2; i < n -1; i++)
        if(abs(a[p] - b[i]) <= 4) max_self(cnt, 1 + recurse(p + 1, i + 1));
    done[p][p2] = 1; 
    return dp[p][p2] = cnt;
}
int main() {
    ifstream cin("nocross.in");
    ofstream fout("nocross.out");

    cin >> n; a.rs(n); b.rs(n);
    read(a); read(b);
    fout << recurse() << endl;
    return 0;
}
