#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
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
    ifstream cin("superbull.in");
    ofstream fout("superbull.out");

    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    ll ans = 0;
    vector<bool> visited(n, false);
    vi dist(n, 0);
    for (int i = 0; i < n; i++) {
        int j = -1;
        for (int k = 0; k < n; k++)
            if (!visited[k] && (j == -1 || dist[k] > dist[j])) j = k;

        ans += dist[j];
        visited[j] = true;
        for (int k = 0; k < n; k++)
            dist[k] = max(dist[k], ar[j] ^ ar[k]);
    }

    fout << ans << "\n";
    cout << ans << "\n";

    return 0;
}