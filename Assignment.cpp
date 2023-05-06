#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int n = towers.size();
    int bestX = -1, bestY = -1, bestQuality = -1;

    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int quality = 0;
            for (int i = 0; i < n; i++) {
                int xi = towers[i][0], yi = towers[i][1], qi = towers[i][2];
                double d = sqrt(pow(xi - x, 2) + pow(yi - y, 2));
                if (d <= radius) {
                    quality += floor(qi / (1 + d));
                }
            }
            if (quality > bestQuality) {
                bestQuality = quality;
                bestX = x;
                bestY = y;
            }
        }
    }

    return {bestX, bestY};
}

int main() {
    vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
    int radius = 2;
    vector<int> ans = bestCoordinate(towers, radius);
    cout << ans[0] << " " << ans[1] << endl; // Output: 2 1
    return 0;
}
