/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream cin("bcount.in");
    ofstream fout("bcount.out");
    
    int n, q;
    cin >> n >> q;
    int cows[n + 1][3];
    for(int i = 0; i < 3; i++) cows[0][i] = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(int j = 0; j < 3; j++) cows[i + 1][j] = cows[i][j];
        cows[i+1][a-1] ++;
    }
    while(q--){
        int a, b; cin >> a >> b;
        for(int i = 0; i < 3; i++) fout << cows[b][i] - cows[a-1][i] << (i != 2 ? " " : "");
        fout << endl;
    }
    return 0;
}
