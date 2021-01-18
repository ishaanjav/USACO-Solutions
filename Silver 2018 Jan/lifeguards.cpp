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
#include <algorithm>
#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
// #include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    cin >> n;
    pii ar[2 * n];
    bool closing[n];
    SET(closing, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar[i] = mp(a, i);
        ar[i + n] = mp(b, i);
    }
    sort(ar, ar + 2 * n);
    n *= 2;
    int lost[n];
    SET(lost, 0);

    set<int> guards;
    int alone;
    int count = 0;
    int prev;
    // 1     3     5
    //          4       7     9
    // Idea is for each cow, calculate how valuable they are
    // how valuable they are is how much time only they are working. EX: if cow's worktime always has another cow working, they're not valuable we can fire them
    // to do this have set of cows that are currently working
    // sweep line
    // when cow leaves, check if 1 cow is still remaining. We need to update their worth on next event
    // WHEN COW LEAVES AND NOW 1 COW LEFT OR COW COMES AND NOW 1 COW HERE,
    //    that is the start of alone time for the cow. So store that cow's # in prev along with when they started being alone
    // WHEN COW LEAVES and NOW 0 COW LEFT OR COW COMES AND 2 COW LEFT
    //    The last cow to leave/first cow who was here had alone time x - alone
    //    update their alone time.
    // Last step: find least alone time --> Remove that cow.
    ll covered = 0, left;
    for (int i = 0; i < n; i++) {
        int x = ar[i].fi, p = ar[i].se;
        if (closing[p]) {
            count--;
            guards.erase(guards.find(p));
            if (count == 1) alone = x, prev = *(guards.begin());
            if (count == 0) {
                covered += x - left;
                lost[p] += x - alone;
            }
        } else {
            closing[p] = 1;
            guards.ins(p);
            count++;
            if (count == 1) {
                alone = x, prev = p;
                left = x;
            } else if (count == 2) {
                lost[prev] += x - alone;
            }
        }
    }
    ll remove = covered;
    for (int j = 0; j < n / 2; j++) min_self(remove, (ll)lost[j]);
    fout << covered - remove;

    return 0;
}
