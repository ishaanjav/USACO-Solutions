/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

unordered_map<char, int> e;
void setUp() {
    int j = 0;
    for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") e[c] = j++;
}
int n, q;
string s;
int lt[100001][26], rt[100001][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    setUp();

    cin >> n >> q;
    cin >> s;

    for (int i = e[s[0]] + 1; i < 26; i++) lt[0][i] = 1;
    for (int i = 1; i < n; i++) {
        int p = e[s[i]];
        for (int row = 0; row <= p; row++) lt[i][row] = lt[i - 1][row];
        lt[i][e[s[i - 1]]] = 0;  // we just had the previous character before us. set it to 0
        for (int row = p + 1; row < 26; row++) lt[i][row] = 1;
    }
    for (int i = e[s[n - 1]] + 1; i < 26; i++) rt[n - 1][i] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int p = e[s[i]];
        for (int row = 0; row <= p; row++) rt[i][row] = rt[i + 1][row];
        rt[i][e[s[i + 1]]] = 0;  // we just had the right character before us. set it to 0
        for (int row = p + 1; row < 26; row++) rt[i][row] = 1;
    }
    while (q-- > 0) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = 0;
        unordered_map<char, int> s1, s2;
        for (int i = 0; i < a; i++) {
            ans += lt[i][e[s[i]]];
            if (s1[s[i]]) continue;
            s1[s[i]] = 1;
            if (lt[i][e[s[i]]] == 0) ans++;
        }
        for (int i = n - 1; i > b; i--) {
            ans += rt[i][e[s[i]]];
            if (s2[s[i]]) continue;
            s2[s[i]] = 1;
            if (rt[i][e[s[i]]] == 0) ans++;
        }

        cout << ans << endl;
    }
}
