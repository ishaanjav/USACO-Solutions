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

int main() {
    ifstream cin("pails.in");
    ofstream fout("pails.out");

    cin >> x >> y >> k >> m;

    bool can[x + 1][y + 1];
    SET(can, false);

    can[0][0] = true;
    for (int o = 1; o <= k; o++) {
        bool next[x + 1][y + 1];
        SET(next, false);
        for (int i = 0; i < x + 1; i++) {
            for (int j = 0; j < y + 1; j++) {
                if (!can[i][j]) continue;
                next[i][j] = 1;
                next[0][j] = 1;
                next[x][j] = 1;
                next[i][y] = 1;
                int moveRight = min(i, y - j);
                int moveLeft = min(x - i, j);
                next[i - moveRight][j + moveRight] = 1;
                next[i + moveLeft][j - moveLeft] = 1;
            }
        }
        memcpy(can, next, sizeof(can));
    }
    int ret = x + y;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (!can[i][j]) continue;
            ret = min(ret, abs(i + j - m));
        }
    }
    cout << ret << endl;
    fout << ret << endl;
}