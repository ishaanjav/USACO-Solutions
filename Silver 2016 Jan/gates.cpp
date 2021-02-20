/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

#include <fstream>
#include <iostream>
using namespace std;
#include <queue>
const int nax = 4001;
bool grid[nax][nax];
int rows = 4001, cols = 4001;
bool inBounds(int i, int j) {
    return i >= 0 && i < rows && j < cols && j >= 0;}

int main() {
    ifstream cin("gates.in");
    ofstream fout("gates.out");
    
    int n;
    cin >> n;
    string s; cin >> s;
    rows = 4001;
    cols = 4001;
    int ar = nax/2, ac = nax/2;
    for(char c : s){
        grid[ar][ac] = 1;
        if(c == 'N'){
            ar += 2;
            grid[ar-1][ac] = 1;
        }else if(c == 'E'){
            ac += 2;
            grid[ar][ac-1] = 1;
        }else if(c == 'W'){
            ac -= 2;
            grid[ar][ac+1] = 1;
        }else{
            ar-=2;
            grid[ar+1][ac] = 1;
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    grid[ar][ac] = 1;
    int ans = 0;
    for (int i = 0; i < nax; i++) {
        for (int j = 0; j < nax; j++) {
            if(grid[i][j]) continue;
            queue<pii> q;
            q.push(mp(i, j));
            ans ++;
            grid[i][j] = 1;
            
            int visited = 0;
            while(!q.empty()){
                pii top = q.front();
                q.pop();
                visited++;
                for(int d = 0; d < 4; d++){
                    int x = dx[d] + top.fi, y = dy[d] + top.se;
                  
                    if(inBounds(x,y) && !grid[x][y]){
                        grid[x][y] = 1;
                        q.push(mp(x,y));
                    }
                }
            }
        }
    }
    fout << ans - 1<< endl;

    return 0;
}
