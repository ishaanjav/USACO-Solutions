/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#include <string>
#include <vector>
#include <algorithm>
int main() {
    ifstream cin("cowcode.in");
    ofstream fout("cowcode.out");

    string s;
    ll n, k, mul;
    cin >> s >> k;
    mul = n = s.length();
    vector<ll> ar;
    ar.push_back(mul);
    while (mul < k) {ar.push_back(mul * 2); mul*=2;}
    while(k > n){
        ll a = *(lower_bound(all(ar), k) - 1);
        if(k == a + 1) k = a;
        else k -= a + 1;
    }
    fout << s[k-1] << endl;
    return 0;
}
