#include <fstream>
#include <iostream>
using namespace std;

int grid[1001][1001];

int main() {
    ifstream cin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (; b < d; b++) {
            grid[b][a]++;
            grid[b][c]--;
        }
    }
    int count = 0, running = 0;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++) {
            running += grid[i][j];
            count += running == k;
        }
    fout << count << endl;
    return 0;
}
