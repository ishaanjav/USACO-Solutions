/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
#include <string>
#include <unordered_map>
bool pref(string a, string pre){ return a.substr(0, pre.length()) == pre; }
bool suff(string a, string suf){ return a.substr(a.length() - suf.length(), suf.length()) == suf; }
unordered_map<string, bool> done;
unordered_map<string, ll> dp;
ll solve(string s){
    if(s.length() <= 2) return 0;
    if(done[s]) return dp[s];
    int len = s.length();
    ll cnt = 0;
    // This is for word|left
    //             ----|----
    for(int size = len/2 + 1; size < len; size++){
        string word = s.substr(0, size);
        string end = s.substr(size, len - size);
        ll cur = pref(word, end) + suff(word, end);
        ll brokenWays = solve(word); // how many ways to form word
        ll ways = cur + brokenWays * cur; // cur is just regular word - suffix or prefix. brokenWays*cur is taking into account the different ways to form regular word to begin with.
        cnt += ways;
    }
    // This is for left|word
    //             ----|----
    for(int size = len/2 + 1; size < len; size++){
        string word = s.substr(len-size, size);
        string end = s.substr(0, len - size);
        ll cur = pref(word, end) + suff(word, end);
        ll brokenWays = solve(word);
        ll ways = cur + brokenWays * cur;
        cnt += ways;
    }
    done[s] = 1;
    dp[s] = cnt % 2014;
    return cnt % 2014;
}

int main() {
    ifstream cin("scode.in");
    ofstream fout("scode.out");
    
    string s; cin >> s;
    fout << solve(s);

    return 0;
}
