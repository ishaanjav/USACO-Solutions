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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("buckets.in");
    ofstream fout("buckets.out");

    string ar[10];
    read(ar);
    int br, bc, rr, rc, lr, lc;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (ar[i][j] == 'B') br = i, bc = j;
            if (ar[i][j] == 'R') rr = i, rc = j;
            if (ar[i][j] == 'L') lr = i, lc = j;
        }
    }
    int dist_br = abs(br - rr) + abs(bc - rc);
    int dist_bl = abs(br - lr) + abs(bc - lc);
    int dist_rl = abs(rr - lr) + abs(rc - lc);

    // Check for special case where rock is between barn and lake
    if ((br == lr || bc == lc) && dist_bl == dist_br + dist_rl)
        fout << dist_bl + 1 << "\n";
    else
        fout << dist_bl - 1 << "\n";

    //fout <<  << "\n";

    return 0;
}
