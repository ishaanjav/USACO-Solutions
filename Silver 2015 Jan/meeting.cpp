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
#include <set>
//#include <unordered_map>
#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

struct Edge {
    int to;
    int bessie, sister;
};
int target;
set<int> bessies, sisters;

vector<vector<Edge> > adj;
void dfs(int v = 1, int time = 0, int sisTime = 0) {
    if (v == target) {
        bessies.insert(time);
        sisters.insert(sisTime);
        // cout << "inserting " << time << " and " << sisTime << "\n";
    }
    // cout << "AT: " << v << endl;
    for (Edge e : adj[v]) {
        dfs(e.to, time + e.bessie, sisTime + e.sister);
    }
}

int main() {
    ifstream fin("meeting.in");
    ofstream fout("meeting.out");

    int n;
    fin >> target >> n;
    adj.resize(n + 2);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        Edge e;
        fin >> a >> e.to >> e.bessie >> e.sister;
        adj[a].pb(e);
    }
    dfs();
    bool possible = false;
    int ans = -1;

    if (bessies.size() < sisters.size()) swap(sisters, bessies);
    /*  for (int i : bessies) cout << i << " ";
    cout << "\n";
    for (int i : sisters) cout << i << " ";
    cout << "\n"; */
    for (int i : sisters) {
        if (bessies.find(i) != bessies.end()) {
            ans = i;
            possible = true;
            break;
        }
    }

    fout << (possible ? to_string(ans) : "IMPOSSIBLE") << endl;
    cout << (possible ? to_string(ans) : "IMPOSSIBLE") << endl;

    return 0;
}