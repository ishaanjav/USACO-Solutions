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
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
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
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");

    ll n, t;
    fin >> n >> t;
    ll ar[n];
    for (int i = 0; i < n; i++) {
        ll a, b;
        fin >> a >> b;
        ar[i] = a + b * t;
    }
    int counter = 0;
    ll first = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (first == -1 || first > ar[i]) {
            first = ar[i];
            counter++;
        }
    }

    fout << counter << "\n";
    cout << counter << "\n";

    return 0;
}
