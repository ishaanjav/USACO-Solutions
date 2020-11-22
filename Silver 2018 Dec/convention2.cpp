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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb  ////cout << (de ? "ASDFASDF\n" : "")
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
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>
unordered_map<int, int> cowLoc;

struct Cow {
    int rank;
    ll come;
    ll left;

    void toString() {
        //cout << rank << " | " << come << "-" << left << endl;
    }
    int loc() {
        return cowLoc[rank];
    }
};

bool comp(Cow a, Cow b) {
    if (a.come != b.come) return a.come < b.come;
    return a.rank < b.rank;
}
bool comp2(Cow a, Cow b) {
    return a.rank > b.rank;
}

int main() {
    ifstream cin("convention2.in");
    ofstream fout("convention2.out");

    int n;
    cin >> n;
    Cow ar[n];
    for (int i = 0; i < n; i++) {
        ar[i].rank = i;
        cin >> ar[i].come >> ar[i].left;
        ar[i].left += ar[i].come;
    }
    priority_queue<Cow, vector<Cow>, function<bool(Cow, Cow)> > pq(comp2);

    sort(ar, ar + n, comp);
    int counter = 0;
    for (Cow c : ar) {
        cowLoc[c.rank] = counter++;
        c.toString();
    }
    ll turn[n];
    SET(turn, 0);

    pq.push(ar[0]);

    bool finished[n], inside[n];
    SET(finished, 0);
    SET(inside, 0);

    int last = 0;
    int debu = 0;
    ll lastCow = -1;
    int j = 1;
    int beenTo = 0;
    while (last != n - 1 || pq.size() == 0) {
        Cow cow = pq.top();
        pq.pop();
        // deb;
        //cout << "At " << cow.rank << endl;
        beenTo++;

        if (lastCow == -1) {
            turn[cow.loc()] = 0;
            lastCow = cow.left;
        } else {
            turn[cow.loc()] = lastCow;
            lastCow += cow.left - cow.come;
        }
        if (beenTo == n) break;
        // if (++debu > 12) break;
        for (; j < n; j++) {
            if (ar[j].come > cow.left) break;
            //cout << "Adding ";
            ar[j].toString();
            pq.push(ar[j]);
        }
        if (j != n && pq.size() == 0) {
            lastCow = -1;
            // for (int j = last; j < n; j++) {
            //cout << "ASDFdas" << last;
            pq.push(ar[j]);
            // break;
            // }
        }
    }

    ll ans = 0;
    cout << "\nWaits:\n";
    for (int i = 0; i < n; i++) {
        cout << turn[i] - ar[i].come << " ";
        max_self(ans, turn[i] - ar[i].come);
    }
    fout << ans << endl;

    // fout << ans << endl;

    return 0;
}