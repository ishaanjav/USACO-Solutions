/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
#define min_self(a, b) a = min(a, b);
#define read(ar) for (auto& x : ar) cin >> x;

ll dp[100001]; // dp[i] - min cows to make i noise
int main() {
    ifstream cin("mooomoo.in");
    ofstream fout("mooomoo.out");
    
    int n, b; cin >> n >> b;
    int cows[b]; read(cows);
    int fields[n]; read(fields);
    for(int i = n - 1; i > 0; i--)
        if(fields[i-1] != 0) fields[i] -= fields[i-1] - 1;
    
    for(int i = 1; i <= 100001; i++) dp[i] = 1e6;
    for(int cow = 0; cow < b; cow++)
        for(int noise = cows[cow]; noise <= 100001; noise++)
            min_self(dp[noise], dp[noise - cows[cow]] + 1);
    ll ans = 0;
    for(int field : fields) ans += dp[field];
    fout << ans << endl;
    return 0;
}
