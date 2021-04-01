/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

int t, a, b, ans = -1, can[5000001];
void dp(int a){ for (int i = a; i <= t; i++) can[i] |= can[i - a]; }
int main() {
    ifstream cin("feast.in");
    ofstream fout("feast.out");

    cin >> t >> a >> b;
    can[0] = 1;
    dp(a); dp(b);
    for (int i = 0; i <= t; i++) can[i / 2] |= can[i];
    dp(a); dp(b);

    for (int i = t; i >= 0 && ans == -1; i--) if (can[i]) ans = i;
    fout << ans << endl;
    return 0;
}
