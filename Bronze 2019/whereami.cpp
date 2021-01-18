/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

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
#include <unordered_map>
//#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

//First try
int main() {
    ifstream fin("whereami.in");

    int n;
    fin >> n;

    string s;
    fin >> s;
    int k;

    for (int size = 1; size <= n; size++) {
        bool good = true;
        unordered_map<string, int> parts;
        for (int j = 0; j <= n - size; j++) {
            parts[s.substr(j, size)]++;
            if (parts[s.substr(j, size)] > 1) {
                good = false;
                break;
            }
        }
        if (good) {
            k = size;
            break;
        }
    }

    ofstream fout("whereami.out");
    fout << k << "\n";

    return 0;
}
