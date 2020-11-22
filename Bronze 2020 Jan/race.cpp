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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
#define read(ar) for (auto& x : ar) cin >> x;
#define each(ar) for(auto i: ar)
#define eachv(ar, i) for (auto i : ar)

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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ifstream cin("race.in");
    ofstream fout("race.out");
    
    int n, k;
    cin >> n >> k;


	while(k--){
		int q; cin >> q;
		int left = n, steps = 0, size = 0;
	//	cout << q << endl;
		while(left > 0){
			//cout << " " << left << endl;
			//if(left > 10) break;
			steps++;
			if(size < q){
				size++; left -= size;
				continue;
			}
			int upper = ((size + 1 + q) * (size + 2 - q))/2;
			int second = ((size + q)*(size-q+1))/2;
		//	cout << "  u: " << upper << " se: " << second << endl;
			if(upper <= left) size++;
			else if(second > left) size--;
			left -= size;
		}
		fout << steps << endl;
	}
	
    
    //fout <<  << "\n";

    return 0;
}
