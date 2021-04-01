/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;

int tree[200000], n;
int sum(int pos) {
    int s = 0; for (; pos >= 1; pos -= pos & -pos) s += tree[pos];
    return s;
}
void update(int pos, int val) { for (; pos <= n; pos += pos & -pos) tree[pos] += val; }
int main() {
    ifstream cin("sleepy.in");
    ofstream fout("sleepy.out");
    
    cin >> n;
    int ar[n], i = n - 1; read(ar);
    for(int prev = ar[i]; i >= 0 && ar[i] <= prev; prev = ar[i], i--) {update(ar[i], 1);}

    fout << n - i + 1 << endl;
    for(int j = 0; j <= i ; j++){
        fout << sum(ar[j]) + i - j << (j != i ? " " : "");
        update(ar[j], 1);
    }
    return 0;
}
