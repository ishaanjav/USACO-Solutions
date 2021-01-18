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
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("highcard.in");
    ofstream fout("highcard.out");

    int n;
    cin >> n;
    vi e, b;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int p1 = 0;
    sort(ar, ar + n);
    for (int i = 1; i <= n * 2; i++) {
        if (i == ar[p1]) {
            e.pb(i);
            p1++;
        } else {
            b.pb(i);
        }
    }
    int counter = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        cout << e[i] << " " << b[i] << endl;
        if (e[p] < b[i]) counter++, p++;
    }
    cout << counter;
    fout << counter;
    return 0;
}
