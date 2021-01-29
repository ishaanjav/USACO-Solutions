/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
using namespace std;
#define read(ar) \
    for (auto& x : ar) cin >> x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++) read(grid[i]);

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        int sum[2], sum2[2];
        sum[0] = sum[1] = sum2[0] = sum2[1] = 0;
        for (int j = 0; j < n; j++)
            sum[j % 2] += grid[i][j], sum2[j%2] += grid[j][i];
        ans1 += max(sum[0], sum[1]);
        ans2 += max(sum2[0], sum2[1]);
    }
    cout << max(ans1, ans2) << endl;
}
