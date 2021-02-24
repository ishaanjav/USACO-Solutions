/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

priority_queue<int, vi, greater<int> > times, distances;
int main() {
    ifstream cin("slowdown.in");
    ofstream fout("slowdown.out");
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c; int a; cin >> c >> a;
        if (c == 'T'){
            times.push(a);
        }else distances.push(a);
    }
    distances.push(1000);
    double D = 0, T = 0;
    double speed = 1;
    
    int t = 0;
    while(!times.empty() || !distances.empty()){
        bool timeFirst = false;
        if(distances.empty()) timeFirst = true;
        else if(!distances.empty() && !times.empty() && times.top() < T + (distances.top() - D) * speed) timeFirst = true;
        if(timeFirst){
            D += (times.top() - T) / (speed+0.0);
            T = times.top();
            times.pop();
        }else{
            T += (distances.top() - D) * speed;
            D = distances.top();
            distances.pop();
        }
        speed++;
    }
    int time = (int) T;
    T -= time;
    if(T >= 0.5) time++;
    fout << time << endl;
    return 0;
}
