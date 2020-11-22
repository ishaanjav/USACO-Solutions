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

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
//#include <set>
#include <map>
//#include <unordered_set>
// #include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

struct entry {
    int id, change, day;
};

bool comp(entry a, entry b) {
    return a.day <= b.day;
}

int main() {
    ifstream cin("measurement.in");
    ofstream fout("measurement.out");

    int n, g;
    cin >> n >> g;
    entry ar[n];
    for (entry &x : ar) cin >> x.day >> x.id >> x.change;

    sort(ar, ar + n, comp);

    int highest = 0;
    map<int, int> cows;
    map<int, int, greater<int> > freq;
    int changes = 0;

    for (auto &e : ar) {
        int &value = cows[e.id];  //value of cow with id
        bool wasTop = (value == freq.begin()->fi);
        int wasCount = freq[value]--;

        // There was only one cow with this score/value
        // freq is <score, # of cows with that score>
        // so now we erase it from freq
        if (wasCount == 1)
            freq.erase(value);

        value += e.change;

        int isCount = ++freq[value];
        bool istop = (value == freq.begin()->fi);

        //2 cases for when leaderoard changes:
        // 1. Cow was at the top:
        //   a. Now they're not at the top OR
        //   b. There were x cows at the top and now there are only x - 1 (wasCount!=1) OR
        //   c. Cow was at the top and is still at the top, now with MORE COWS (not just them) (isCount != 1)
        // 2. Cow was not at the top, but now is at the top (else if(istop))
        if (wasTop) {
            if (!istop || wasCount != 1 || isCount != 1)
                changes++;
        } else if (istop)
            changes++;
    }
    fout << changes;

    return 0;
}