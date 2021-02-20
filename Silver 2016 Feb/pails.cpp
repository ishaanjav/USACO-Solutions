/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define min_self(a, b) a = min(a, b);
int x, y, k, m;
bool dp[101][101][101], done[101][101];
void recurse(int p = 0, int a = 0, int b = 0){
    if(dp[a][b][p]) return;
    dp[a][b][p] = 1;
    if(p ++< k){
        recurse(p, x, b); // fill a to the top
        recurse(p, a, y); // fill b to the top
        // empty
        recurse(p, 0, b);
        recurse(p, a, 0);
        // pour
        int toB = min(y - b, a);
        recurse(p, a - toB, b + toB);
        int toA = min(x - a, b);
        recurse(p, a + toA, b - toA);
    }
}
int main() {
    ifstream cin("pails.in");
    ofstream fout("pails.out");
    
    cin >> x >> y >> k >> m;
    recurse();
    ll closest = m;
    for(int p = 0; p <= k; p ++)
        for(int i = 0; i <= x; i++)
            for(int j = 0; j <= y; j++)
                if(dp[i][j][p])
                    min_self(closest, (ll) abs(m - i - j));
    fout << closest << endl;
    return 0;
}
