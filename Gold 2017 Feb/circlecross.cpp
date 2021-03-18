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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
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
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

// SOLUTION
/* doesn't matter which one is entry/exit
Keep track of whether something has been seen or not.
If not seen --> Set that number to seen and add it to the vector v
If you come across a number that has already been seen,
  find its location in the vector v and how many cows came after it
  all those cows intersect with it because their endpoint is on the opposite
side of the current cow's segment so increase ans by how many cows come after in
the vector erase the number from the vector
*/
bool seen[50001];
int main() {
    ifstream cin("circlecross.in");
    ofstream fout("circlecross.out");

    int n;
    cin >> n;
    int ar[2 * n]; read(ar);
    n *= 2;
    vi v;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!seen[ar[i]]){
            seen[ar[i]] = 1;
            v.pb(ar[i]);
        }else{
            auto it = find(all(v), ar[i]);
            int onTop = v.end() - it-1;
            ans += onTop;
            v.erase(it);
        }
    }
    fout << ans << endl;
    return 0;
}
