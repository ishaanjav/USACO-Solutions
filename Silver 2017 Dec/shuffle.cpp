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
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

int main() {
    ifstream cin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    cin >> n;
    int parents[n], children[n];
    SET(children, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        parents[i] = a - 1;
        children[a - 1]++;
    }
    int count = n;
    queue<int> q;  // stores vertices that have nothing going into them (children is 0)
    for (int i = 0; i < n; i++) {
        if (children[i] == 0) {
            q.push(i);
            count--;
        }
    }
    // for each thing that has no children pointing to it, decrease the parent's inputs by 1
    // the parent can't rely on these children to give them infinite supply so that at every shuffle it has a cow
    //Because these children will run out: They don't have anything connected to them
    // so logic is to decrease number of actual children the parent has
    // If a parent's children # hits 0, that means all its "children" were positions that had nothing going to them
    //  so after 1 move, the children would have run out of cows
    //  after 2 moves, the parent would have run out of cows as well because those children wouldn't have any more to give
    // so once the parent hits 0, we add them to our queue as well because they're not getting an infinite supply of cows
    //   so we now have to check if their parent has other sources
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (--children[parents[top]] == 0) {
            count--;
            q.push(parents[top]);
        }
    }
    fout << count;

    //fout <<  << "\n";

    return 0;
}
