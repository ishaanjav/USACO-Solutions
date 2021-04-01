/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

// Solution:
// Use the N/2 biggest numbers than Bessie has in the first half, then the remaining smallest in the second half.
// 1st half: Greedily use Bessie's smallest possible card that is > than Elsie's smallest card.
// 2nd half: Greedily use Elsie's smallest possible card that is > than Bessie's smallest card.

#include <iostream>
#include <fstream>
using namespace std;
#include <algorithm>
int main() {
    ifstream cin("cardgame.in");
    ofstream fout("cardgame.out");
    
    int n, ans = 0;
    cin >> n;
    int vals[n], ef[n/2], b[n], el[n/2], bf[n/2], bl[n/2];
    for(int i = 0; i < n; i++){ cin >> vals[i]; if(i < n/2){ef[i] = vals[i];} else {el[i - n/2] = vals[i];} }
    sort(vals, vals + n);
    for(int i = 1, p = 0, j = 0; i <= n*2; i++){
        while(p < n && i == vals[p]) p++,i++;
        if(i <= n * 2) b[j++] = i;
    }
    for(int i = 0; i < n; i++) if(i < n/2) bl[i] = b[i]; else bf[i-n/2] = b[i];
    sort(el, el + n/2); sort(ef, ef + n/2);
    for(int i = 0, p = 0; i < n/2; i++)
        if(bf[i] > ef[p]) p++, ans ++;
    for (int i = 0, p = 0; i < n / 2; i++)
        if (el[i] > bl[p]) p++, ans++;
    fout << ans << endl;
    return 0;
}
