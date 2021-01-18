/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int moves[101][101];
bool canGet[1000];
int x, y, k, m;

void dfs(int a, int b, int amt) {
    if (amt == k) return;
    if (canGet[a + b] && moves[a][b] != -1 && moves[a][b] <= amt) return;
    moves[a][b] = amt;
    canGet[a + b] = 1;
    dfs(0, b, amt + 1);
    dfs(a, 0, amt + 1);
    int takeFromB = min(b, x - a);
    int takeFromA = min(a, y - b);
    dfs(a + takeFromB, b - takeFromB, amt + 1);
    dfs(a - takeFromA, b + takeFromB, amt + 1);
    dfs(x, b, amt + 1);
    dfs(a, y, amt + 1);
}

int main() {
    ifstream cin("pails.in");
    ofstream fout("pails.out");

    cin >> x >> y >> k >> m;
    SET(moves, -1);
    moves[x][y] = 2;
    moves[x][0] = 1;
    moves[y][0] = 1;
    moves[0][0] = 1;
    canGet[0] = 1;
    canGet[x] = canGet[y] = 1;

    dfs(0, 0, 0);
    int best = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (moves[i][j] == -1) continue;
            int cur = i + j;
            if (abs(cur - m) < abs(best - m))
                best = abs(cur - m);
            else if (abs(cur - m) == abs(m - best))
                min_self(best, cur);
        }
    }

    fout << best << endl;
    cout << best << endl;

    return 0;
}
