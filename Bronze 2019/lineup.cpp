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

// Just basically bruteforce it
// http://usaco.org/current/data/sol_lineup_bronze_dec19.html

class Node {
   public:
    Node *parent;
    Node *child;
    string s;
    Node(string st, Node *p, Node *c) {
        s = st;
        parent = p;
        child = c;
    }
    Node() {
    }
};

//3:16 PM
int main() {
    ifstream fin("lineup.in");

    int n;
    fin >> n;
    string names[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    Node *beat("Beatrice", &root, &root);
    Node *root;
    root->child = beat;

    unordered_map<string, bool> used;
    unordered_map<string, vector<string> > m;
    for (int x = 0; x < n; x++) {
        string a, b, extra;
        fin >> a;
        fin >> extra >> extra >> extra >> extra;
        fin >> b;
        m[a].push_back(b);
        m[b].push_back(a);
        if (b < a) swap(a, b);

        if (m[a].size() == 1) {
            if (m[b].size() == 1) {
                // Most basic
                //Both only have 1 connection - each other
                int aP = 0;
                int bP = 0;
                for (int i = 0; i < 8; i++) {
                    if (names[i] == a) aP = i;
                    if (names[i] == b) bP = i;
                }
                for (int i = bP; i > aP; i--) {
                    names[i] = names[i - 1];
                }
                names[aP + 1] = b;
            } else if (m[b].size() == 2) {
                //a is only connected to b,
                // but now b has two requirements.
                // So, b has to be in the middle. We put the smaller nieghbor first
                string neighbor = m[b][0];
                int aP, bP, nP;
                for (int i = 0; i < 8; i++) {
                    if (names[i] == a) aP = i;
                    if (names[i] == b) bP = i;
                    if (names[i] == neighbor) nP = i;
                }
                //Neighbor and b are already connected. It is just a.
                // a is smaller than b.
                // If neighbor is smaller than a:
                //  .... neighbor -> b -> a....
                // If a is smaller than neighbor:
                // ..... a -> b -> neighbor ...
                if (a < neighbor) {
                    if (aP < nP) {
                        for (int i = aP; i < bP;)
                    }
                }
            }
        } else {
            if (m[b].size() == 1) {
            } else if (m[b].size() == 2) {
            }
        }
    }

    ofstream fout("lineup.out");

    /* for (int i = 0; i < 8; i++) {
        vector<string> v = m[names[i]];
        if (used[names[i]]) continue;
        used[names[i]] = true;
        if (v.size() == 0) {
            fout << names[i] << endl;
        } else if (v.size() == 1) {
            string cur = names[i];
            string s = v[0];
            if (cur < s)
                fout << cur + "\n" + s + "\n";
            else
                fout << s + "\n" + cur + "\n";
        } else {
            string cur = names[i];
            string option1 = v[0];
            string option2 = v[1];
            if (option1 < option2)
                fout << option1 + "\n" + cur + "\n" + option2 + "\n";
            else
                fout << option2 + "\n" + cur + "\n" + option1 + "\n";
        }
    } */

    return 0;
}