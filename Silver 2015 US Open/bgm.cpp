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
#include <unordered_map>
//#include <unordered_set>
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
#include <climits>
ll MOD = LLONG_MAX+ 1;

unordered_map<char, vi> um;
unordered_map<char, ll> counts;
ll badPart1 = 0, badPart2 = 0, badPart3 = 0;
//badPart1 is # of ways to get BESSIe so that it is not mode 7
// To find total bad ways, we will need to multiply all 3
ll& whichOne(int id) {
    if (id == 0)
        return badPart1;
    else if (id == 1)
        return badPart2;
    return badPart3;
}
vector<ll> v;
void recurse(int id, string s, int pos = 0, int sum = 0) {
    if (pos == s.length()) {
        if (sum % 7 == 0) return;
        ll& var = whichOne(id);
        // TODO
        // - Multiply all the numbers in vector v (these are frequencies for each of the letters)
        // Once you get this product, mod it, add to var, mod var, and then return
        ll prod = 1;
        for (ll a : v) prod = ((prod * a) % MOD);
        // cout << id << ": " << prod << endl;
        var += prod;
        var = (var % MOD);
        return;
    }
    for (int mod = 0; mod < 7; mod++) {
        char c = s[pos];
        ll frequencyOfThisMod = um[c][mod];
        if (frequencyOfThisMod == 0) continue;
        cout << s << " trying " << pos << " , (" << mod << "," << frequencyOfThisMod << endl;
        v.pb(frequencyOfThisMod);
        ll newSum = sum;
        newSum += mod;
        if (id == 0 && (pos >= 2)) newSum += mod;
        if (id == 2 && pos == 1) newSum += mod;
        recurse(id, s, pos + 1, newSum);
        v.erase(v.end() - 1);
    }
}
int main() {
    ifstream cin("bgm.in");
    ofstream fout("bgm.out");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a;
        ll b;
        cin >> a >> b;
        b += 70000000ll;
        b %= 7;
        if (um.find(a) == um.end()) um[a].resize(7);
        um[a][b]++;
        counts[a]++;
    }
    ll totalWays = 1;
    /* 
     totalWays = (totalWays * counts['B']) % MOD;
    cout << " " << counts['B'] << endl;
    totalWays = (totalWays * (ll)pow(counts['E'], 1)) % MOD;
    cout << " " << counts['E'] << endl;
    totalWays = (totalWays * (ll)pow(counts['S'], 1)) % MOD;
    cout << " " << counts['S'] << endl;
    totalWays = (totalWays * (ll)pow(counts['I'], 1)) % MOD;
    cout << " " << counts['I'] << endl;
    totalWays = (totalWays * (ll)pow(counts['G'], 1)) % MOD;
    cout << " " << counts['G'] << endl;
    totalWays = (totalWays * (ll)pow(counts['O'], 1)) % MOD;
    cout << " " << counts['O'] << endl;
    totalWays = (totalWays * (ll)pow(counts['M'], 1)) % MOD;
    cout << " " << counts['M'] << endl;
     */
    totalWays = (totalWays * counts['B']) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['E'], 1)) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['S'], 1)) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['I'], 1)) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['G'], 1)) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['O'], 1)) % MOD;
    cout << " " << totalWays << endl;
    totalWays = (totalWays * (ll)pow(counts['M'], 1)) % MOD;
    cout << " " << totalWays << endl;
    vector<ll> v;
    string a = "BESI", b = "GOES", c = "MO";
    // recurse(0, a);
    // recurse(1, b);
    // recurse(2, c);
    // cout << badPart1 << " | " << badPart2 << " | " << badPart3 << endl;
    // ll answer = ((totalWays % MOD) - ((badPart1 * ((badPart2 * badPart3) % MOD)) % MOD) + 2 * MOD) % MOD;
    ll answer = 0;
    ll badWays = 0;
    for (int b = 0; b < 7; b++) {
        if (um['B'][b] == 0) continue;
        for (int e = 0; e < 7; e++) {
            if (um['E'][e] == 0) continue;
            for (int s = 0; s < 7; s++) {
                if (um['S'][s] == 0) continue;
                for (int i = 0; i < 7; i++) {
                    if (um['I'][i] == 0) continue;
                    for (int g = 0; g < 7; g++) {
                        if (um['G'][g] == 0) continue;
                        for (int o = 0; o < 7; o++) {
                            if (um['O'][o] == 0) continue;
                            for (int m = 0; m < 7; m++) {
                                if (um['M'][m] == 0) continue;
                                if ((b + 2 * e + 2 * s + i) % 7 == 0) continue;
                                if ((g + o + e + s) % 7 == 0) continue;
                                if ((m + 2 * o) % 7 == 0) continue;
                                ll temp = 1;
                                temp *= um['B'][b];
                                temp *= um['E'][e];
                                temp = (temp * um['S'][s]) % MOD;
                                temp = (temp * um['I'][i]) % MOD;
                                temp = (temp * um['G'][g]) % MOD;
                                temp = (temp * um['O'][o]) % MOD;
                                temp = (temp * um['M'][m]) % MOD;
                                badWays = (((temp) % MOD) + badWays) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Total ways: " << totalWays << " bad: " << badWays << endl;
    answer = ((totalWays % MOD) - badWays + 2 * MOD) % MOD;
    fout << answer << "\n";
    cout << answer << "\n";

    return 0;
}