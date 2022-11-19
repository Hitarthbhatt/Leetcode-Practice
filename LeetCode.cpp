
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


int main() {

    vector<vector<int> > ans(5);
    int i = 0;

    for (int i = 0; i < ans.size(); i++) {
        ans[i].resize(2);
        cout << "[ ";
        for (int j = 0; j < 2; j++) {
            cout << ans[i][j];
        }
        cout << " ], ";
    }

    cout << endl;

    return 0;
}