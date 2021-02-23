/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#include <string>
#include <vector>
#include <algorithm>

vector<pair<string, int> > words;
bool match(string pref, string word) {
    return (pref.size() <= word.size()) && word.substr(0, pref.size()) == pref;
}
int main() {
    ifstream cin("auto.in");
    ofstream fout("auto.out");
    
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        words.pb(mp(s, i + 1));
    }
    sort(all(words));
    while(q--){
        int p; string s; cin >> p >> s;
        int pos = lower_bound(all(words), mp(s, 0)) - words.begin();
        pos += p-1;
        if(pos < words.size() && match(s, words[pos].fi)) fout << words[pos].se << endl;
        else fout << "-1\n";
    }

    return 0;
}
