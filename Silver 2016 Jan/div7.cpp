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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
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

int ar[7];
int maxSteps[6000006];
bool can[6000006];
int main() {
    ifstream cin("div7.in");
    ofstream fout("div7.out");

    int n;
    cin >> n;
    int first[7], last[7];
    int prefix = 0;
    for (int i = 0; i < 7; i++) first[i] = -1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefix += a;
        prefix %= 7;
        if (first[prefix] == -1)
            first[prefix] = i;
        last[prefix] = i;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        cout << first[i] << " ";
        if (first[i] != -1) max_self(ans, last[i] - first[i]);
    }
    cout << ans;
    fout << ans;

    return 0;
}
