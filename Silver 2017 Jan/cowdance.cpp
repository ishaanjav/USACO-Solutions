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
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
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
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

bool canDo(int ar[], int n, int k, int time) {
    priority_queue<int, vi, greater<int> > pq;
    int p = 0;
    for (; p < k; p++) {
        pq.push(ar[p]);
        // cout << "  start " << ar[p] << Endl;
    }
    int cur = 0;
    while (p != n) {
        int top = pq.top();
        pq.pop();
        pq.push(top + ar[p]);
        // cout << "  +ing " << top + ar[p] << Endl;
        p++;
    }
    int worst = 0;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        max_self(worst, top);
    }
    // cout << "Worst: " << worst << endl;
    return worst <= time;
}

int main() {
    ifstream cin("cowdance.in");
    ofstream fout("cowdance.out");

    int n, t;
    cin >> n >> t;

    int ar[n];
    for (int& x : ar) cin >> x;

    int best = n;
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // Need to check whether canDo with n
        // cout << "Trying " << mid << endl;
        bool can = canDo(ar, n, mid, t);
        if (can) {
            hi = mid - 1;
            best = mid;
        } else
            lo = mid + 1;
    }

    cout << best << endl;
    fout << best << endl;

    return 0;
}
