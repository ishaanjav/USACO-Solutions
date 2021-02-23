#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a,c) memset(a,c,sizeof(a))
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
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("fairphoto.in");
    ofstream fout("fairphoto.out");
    
    int n;
    cin >> n;
    pair<ll, char> ar[n];
    for(int i = 0; i < n; i++){
        ll a; char c; cin >> a >> c;
        ar[i] = mp(a, c);
    }
    sort(ar, ar + n);
    unordered_map<ll, ll> first;
    ll prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + (ar[-1+i].se == 'W' ? 1 : -1);
    
    ll answer = 0;
    for(int i = 0; i < n; i++){
        ll pre = prefix[i + 1];
        if(pre >= 0){
            if(pre % 2 == 0){
                max_self(answer, ar[i].fi - ar[0].fi);
            }else{
                max_self(answer, ar[i].fi - ar[1].fi);
            }
        }else{
            if(first[pre] != 0){
                max_self(answer, ar[i].fi - ar[first[pre]].fi);
            }
        }
        if(first[pre] == 0){
            first[pre] = i + 1;
        }
    }
    fout << answer << endl;
    return 0;
}
