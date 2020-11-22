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

//2:46 PM
//First try
int main() {
    ifstream fin("gymnastics.in");

    int k, n;
    fin >> k >> n;
    pair<bool, int> order[n + 1][n + 1];  //valid pairing, which one comes first
    for (int x = 0; x < k; x++) {
        vi v(n);
        for (int i = 0; i < n; i++) fin >> v[i];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = v[i];
                int b = v[j];
                cout << a << " " << b << endl;
                if (x == 0) {
                    order[a][b] = make_pair(true, a);
                    order[b][a] = make_pair(true, a);
                } else {
                    //Not a valid pairing, don't even need to process
                    if (order[a][b].first == false) continue;
                    int firstN = order[a][b].second;
                    if (firstN == a)
                        continue;  //All good since the first number is still correct
                    else {
                        order[a][b] = make_pair(false, -1);
                        order[b][a] = make_pair(false, -1);
                    }
                }
            }
        }
    }

    int counter = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (order[i][j].first)
                counter++;
        }
    }

    counter /= 2;

    ofstream fout("gymnastics.out");
    fout << counter << "\n";

    return 0;
}