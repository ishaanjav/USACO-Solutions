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
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

bool comp(pii a, pii b) {
    return a.fi < b.fi;
}

int main() {
    ifstream cin("balancing.in");
    ofstream fout("balancing.out");

    int n;
    cin >> n;
    pair<int, int> ar[n];
    for (pii &p : ar) cin >> p.fi >> p.se;
    sort(ar, ar + n, comp);
    int xs[] = {1, -1, -1, 1};
    int ys[] = {1, -1, 1, -1};
    int lowest = n;
    int v[] = {1, -1};
    for (pii point : ar) {
        for (int d = 0; d < 2; d++) {
            int horizontalLine = point.se + v[d];
            int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
            for (pii p : ar) {
                if (p.se > horizontalLine)
                    a1++;
                else
                    a2++;
            }
            // a1 is above and to the right
            // a2 is below and to the right

            for (int p = 0; p < n;) {
                if (ar[p].se > horizontalLine)
                    a3++, a1--;
                else
                    a4++, a2--;
                while (p < n - 1 && ar[p].fi == ar[p + 1].fi) {
                    p++;
                    if (ar[p].se > horizontalLine)
                        a3++, a1--;
                    else
                        a4++, a2--;
                }
                // if (horizontalLine == 4) cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
                min_self(lowest, max(max(a1, a2), max(a3, a4)));
                p++;
            }
        }
        // for (int d = 0; d < 4; d++) {
        //     int x = point.fi + xs[d], y = point.se + ys[d];
        //     int a1, a2, a3, a4;
        //     a1 = a2 = a3 = a4 = 0;
        //     // cout << x << " " << y << endl;
        //     for (pii every : ar) {
        //         // if (x == 4 && y == 2)
        //         // cout << "A\n";
        //         if (x > every.fi) {
        //             if (y > every.se)
        //                 a1++;
        //             else
        //                 a2++;
        //         } else {
        //             if (y > every.se)
        //                 a3++;
        //             else
        //                 a4++;
        //         }
        //     }
        //     int cur = max(a1, max(a2, max(a3, a4)));
        //     cout << x << " " << y << " :  " << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        //     /*  if (x == 6 && y == 4) {
        //         cout << cur << endl;
        //         cout << "WASASDFASDFASD";
        //         cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        //     } */
        //     min_self(lowest, cur);
        // }
    }

    fout << lowest << "\n";
    cout << lowest << "\n";

    return 0;
}