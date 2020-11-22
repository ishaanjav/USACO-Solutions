#include <fstream>
#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

#define HM 1000000007
#define HA 100000007
#define HB 101

//Nice hashing problem

int hnext(int h, int ch) {
    return (1ll * h * HA + ch + HB) % HM;
}

int main() {
    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string s;
    string t;
    fin >> s >> t;

    int tHash = 0;
    for (int i = 0; i < t.length(); i++) {
        tHash = hnext(tHash, t[i] - 'a');
    }

    string ans;
    vector<int> rHash(1, 0);
    vector<int> nextPow(1, 1);

    for (int i = 0; i < s.size(); i++) {
        ans += s[i];

        rHash.pb(hnext(rHash.back(), s[i] - 'a'));
        nextPow.pb((1ll * nextPow.back() * HA) % HM);

        if (ans.size() >= t.size()) {
            int hashSubstring = (1ll * rHash[ans.size() - t.size()] * nextPow[t.size()]) % HM;
            int hash = (HM + rHash.back() - hashSubstring) % HM;

            if (hash == tHash && ans.substr(ans.size() - t.size()) == t) {
                ans.resize(ans.size() - t.size());
                rHash.resize(rHash.size() - t.size());
                nextPow.resize(nextPow.size() - t.size());
            }
        }
    }

    fout << ans << endl;
    cout << ans << endl;
    return 0;
}