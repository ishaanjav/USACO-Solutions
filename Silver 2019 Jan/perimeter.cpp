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
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
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
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
#define read(ar) \
    for (auto& x : ar) cin >> x;
#define each(ar) for (auto i : ar)
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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int perim = 0;
vector<vector<char> > grid;
bool vis[1003][1003];
int rows, cols;
bool inBounds(int i, int j) {return i >= 0 && i < rows && j < cols && j >= 0;}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfs(int i, int j){
    if(vis[i][j]) return 0;
    vis[i][j] = 1;
    int ans = 1;
    for(int d = 0; d < 4; d++){
        int x = dx[d] + i, y = dy[d] + j;
        if(grid[x][y] == '#') ans += dfs(x, y);
        else perim ++;
    }
    return ans;
}
int main() {
    ifstream cin("perimeter.in");
    ofstream fout("perimeter.out");
    
    int n; cin >> n;
    grid.resize(n+2, vector<char>(n + 2));
    rows = cols = n + 2;
    for(int i = 0; i <= n + 1; i++)
        grid[i][0] = grid[0][i] = grid[n+1][i] = grid[i][n+1] = '.';
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= n; j++)
            grid[i][j] = s[j-1];
    }
    
    int p = 0, a = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!vis[i][j] && grid[i][j] == '#'){
                perim = 0;
                max_self(a, dfs(i, j));
                max_self(p, perim);
            }
    fout << a << " " << p << endl;
    return 0;
}

