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
vi ar;
int n, k;
int main() {
    ifstream cin("hps.in");
    ofstream fout("hps.out");
    
    cin >> n >> k;
    if(n == 1){
        fout << "2\n";
        return 0;
    }
    bool game[3][3] = {{0, 0, 1},
                       {0, 1, 0},
                       {1, 0, 0}};
    ar.rs(n);
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        if(c == 'H') ar[i] = 0;
        else ar[i] = 1+ (c == 'S');
    }
    ll dp[3][k+1][n + 1]; // games won with [color][changes][position]
    for(int i = 0; i < 3; i++){
        dp[i][0][0] = 0;
        for(int j = 1; j <= n; j++) dp[i][0][j] = dp[i][0][j-1] + game[i][ar[j-1]];
    }
    for(int changes = 1; changes <= k; changes ++)
        for(int pos = 1; pos <= n; pos++){
            for(int i = 0; i < 3; i++) dp[i][changes][0] = dp[i][changes-1][0];
            for (int col = 0; col < 3; col++) {
                // no changes. Just from previous position
                dp[col][changes][pos] = dp[col][changes][pos - 1] + game[col][ar[pos-1]];
                for(int oCol = 0; oCol < 3; oCol++)
                if(oCol != col)max_self(dp[col][changes][pos], game[oCol][ar[pos-1]] + dp[oCol][changes-1][pos-1]);
            }
        }
    ll ans = 0;
    for(int i = 0; i < 3; i++) for(int j = 0; j <= k; j++) max_self(ans, dp[i][j][n]);
    fout << ans << endl;
    return 0;
}
