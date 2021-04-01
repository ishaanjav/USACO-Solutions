/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;
#define max_self(a, b) a = max(a, b);

int n, k;
bool done[10001];
int ar[10001], dp[10001];
int recurse(int p = 0) {
    if (done[p]) return dp[p];
    if (p == n) return 0;
    int cur = ar[p], score = 0;
    for (int i = p; i < min(n, p + k); i++) {
        max_self(cur, ar[i]);
        max_self(score, cur * (i - p + 1) + recurse(i + 1));
    }
    done[p] = dp[p] = score;
    return score;
}
int main() {
    ifstream cin("teamwork.in");
    ofstream fout("teamwork.out");

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> ar[i];
    fout << recurse() << endl;
    return 0;
}
