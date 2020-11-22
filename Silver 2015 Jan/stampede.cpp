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
#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream fin("stampede.in");
    ofstream fout("stampede.out");

    int n;
    fin >> n;
    vector<pair<int, int> > events;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        fin >> x >> y >> r;
        x *= -r;
        events.pb(mp(x - r, y));
        events.pb(mp(x, -y));
    }
    sort(all(events));
    set<int> seen, active;
    for (int i = 0; i < events.size();) {
        int j;
        for (j = i; j < events.size() && events[i].first == events[j].first; j++) {
            int y = events[j].second;
            if (y > 0)
                active.insert(y);
            else
                active.erase(-y);
        }

        if (!active.empty()) seen.insert(*active.begin());
        i = j;
    }

    fout << seen.size() << "\n";
    cout << seen.size() << "\n";
    for (int i : seen) cout << " " << i << "\n";

    return 0;
}