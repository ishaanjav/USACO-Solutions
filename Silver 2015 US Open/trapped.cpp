#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof a)
#define MOD 1000000007
#define enld endl

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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
#include <climits>

int B;
int n;
int binSearch(pair<int, int> ar[], int n, ll val) {
    int hi = n - 1;
    int lo = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ar[mid].fi == val) return mid;
        if (ar[mid].fi < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
int main() {
    ifstream cin("trapped.in");
    ofstream fout("trapped.out");

    cin >> n >> B;
    pair<int, int> ar[n + 1];
    for (int i = 0; i < n; i++) {
        int size, pos;
        cin >> size >> pos;
        ar[i] = mp(pos, size);
    }
    ar[n] = mp(B, 0);
    sort(ar, ar + n + 1);

    int position = binSearch(ar, n, B);

    int j = position + 1;
    int result = INT_MAX;
    for (int i = position - 1; i >= 0; i--) {
        cout << ar[i].first << " : \n";
        while (j < n && ar[j].first <= ar[i].first + ar[i].second) {
            result = min(result, ar[j].first - ar[i].first - ar[j].second);
            j++;
            cout << "\tResult: " << result << "  j: " << ar[j].first << endl;
        }
    }
    j = position - 1;
    for (int i = position + 1; i < n; i++) {
        cout << ar[i].first << " : \n";
        while (j >= 0 && ar[i].first - ar[i].second <= ar[j].first) {
            result = min(result, ar[i].first - ar[j].first - ar[j].second);
            cout << "\tResult: " << result << "  j: " << ar[j].first << endl;
            j--;
        }
    }
    if (result == INT_MAX) {
        cout << -1 << endl;
        fout << -1 << endl;
    } else {
        cout << max(result, 0) << endl;
        fout << max(result, 0) << endl;
    }

    return 0;
}