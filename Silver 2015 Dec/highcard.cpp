/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;
#define all(v) v.begin(), v.end()
#include <vector>
typedef vector<int> vi;
#include <algorithm>

bool cards[100001];
int main() {
    ifstream cin("highcard.in");
    ofstream fout("highcard.out");
    
    int n;
    cin >> n;
    vi elsie, bessie;
    for(int i =0 ; i < n; i++){
        int a; cin >> a;
        cards[a] = 1;
        elsie.pb(a);
    }
    sort(all(elsie));
    for(int i = 1; i <= 2 *n; i++)
        if(!cards[i]) bessie.pb(i);
    int answer = 0;
    for(int i = 0; i < n; i++)
        if(bessie[i] > elsie[answer]) answer++;
    fout << answer << endl;
    return 0;
}
