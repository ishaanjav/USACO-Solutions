/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define SET(a, c) memset(a, c, sizeof(a))
#define fi first
#define se second
#include <vector>
typedef vector<int> vi;
#include <unordered_set>
#include <cstring>
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    pii ar[k];
    for (int i = 0; i < k; i++) {
        cin >> ar[i].fi >> ar[i].se;
    }
    unordered_set<int> cnt[n + 1];
    int loc[n + 1];      // loc[i] what is at position i
    int whereIs[n + 1];  // whereIs[i] wwhich position is i at
    for (int i = 0; i <= n; i++) {
        loc[i] = i;
        cnt[i].ins(i);
        whereIs[i] = i;
    }
    for (pii p : ar) {
        cnt[loc[p.fi]].ins(p.se);
        cnt[loc[p.se]].ins(p.fi);
        whereIs[loc[p.se]] = p.fi;
        whereIs[loc[p.fi]] = p.se;
        swap(loc[p.fi], loc[p.se]);
    }
    bool visited[n + 1];
    SET(visited, 0);
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        vi tracker;
        int o = whereIs[i];
        tracker.pb(i);
        visited[i] = 1;
        while (o != i) {
            visited[o] = 1;
            tracker.pb(o);
            o = whereIs[o];
            visited[o] = 1;
        }
        unordered_set<int> pnt;
        for (int t : tracker)
            for (int i : cnt[t]) pnt.ins(i);
        for (int t : tracker) ans[t] = pnt.size();
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}
