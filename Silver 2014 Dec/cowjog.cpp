/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;
#define ll long long


int main() {
    ifstream cin("cowjog.in");
    ofstream fout("cowjog.out");
    
    ll n, t;
    cin >> n >> t;
    ll goingTo[n];
    for(int i = 0; i < n; i++){
        ll x, s; cin >> x >> s;
        goingTo[i] = x + t * s;
    }
    int ans = 0;
    for(int i = n - 1; i >=0;){
        ans++;
        ll to = goingTo[i];
        while(i >= 0 && goingTo[i] >= to) i--;
    }
    fout << ans << endl;
    return 0;
}
