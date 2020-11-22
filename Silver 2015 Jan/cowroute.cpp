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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int a, b, n;
#define MAXV 1010

bool visited[MAXV];
pair<long long, int> cost_a2u[MAXV];
pair<long long, int> cost[MAXV][MAXV];

int main() {
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");

    fin >> a >> b >> n;
    memset(cost, 0x3F, sizeof(cost));
    for (int i = 0; i < MAXV; i++) cost[i][i] = mp(0, 0);
    for (int i = 0; i < n; i++) {
        ll route_cost;
        int route_len;
        fin >> route_cost >> route_len;

        vector<int> route(route_len);
        for (int j = 0; j < route_len; j++) {
            fin >> route[j];
            for (int k = 0; k < j; k++) cost[route[k]][route[j]] = min(cost[route[k]][route[j]], make_pair(route_cost, j - k));
        }
    }

    memset(visited, false, sizeof(visited));
    memset(cost_a2u, 0x3F, sizeof(cost_a2u));

    cost_a2u[a] = mp(0, 0);
    for (int i = 0; i < MAXV; i++) {
        int u = -1;
        for (int j = 0; j < MAXV; j++) {
            if (visited[j]) continue;
            if (u == -1 || cost_a2u[j] < cost_a2u[u]) u = j;
        }
        visited[u] = true;
        for (int j = 0; j < MAXV; j++) {
            pair<ll, int> p = cost_a2u[u];
            p.first += cost[u][j].first;
            p.second += cost[u][j].second;
            cost_a2u[j] = min(cost_a2u[j], p);
        }
    }
    if (cost_a2u[b].second <= MAXV) {
        cout << cost_a2u[b].first << ' ' << cost_a2u[b].second << endl;
        fout << cost_a2u[b].first << ' ' << cost_a2u[b].second << endl;
    } else {
        cout << "-1 -1\n";
        fout << "-1 -1\n";
    }
    //fout <<  << "\";

    return 0;
}