#include <bits/stdc++.h>
using namespace std;

// Directions for moving in the 6 possible directions (left, right, up, down, forward, backward)
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

bool isValid(int x, int y, int z, int X, int Y, int Z, vector<vector<vector<int>>>& grid, vector<vector<vector<bool>>>& vis) {
    return (x >= 0 && x < X && y >= 0 && y < Y && z >= 0 && z < Z && !vis[x][y][z] && grid[x][y][z] == 0);
}

int shortestPath(vector<vector<vector<int>>>& grid, Point src, Point dest) {
    int X = grid.size();
    int Y = grid[0].size();
    int Z = grid[0][0].size();

    vector<vector<vector<bool>>> vis(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));

    // BFS queue
    queue<pair<Point, int>> q;
    q.push({src, 0});
    vis[src.x][src.y][src.z] = true;

    while (!q.empty()) {
        Point p = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (p.x == dest.x && p.y == dest.y && p.z == dest.z) {
            return dist;
        }

        for (int i = 0; i < 6; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];

            if (isValid(nx, ny, nz, X, Y, Z, grid, vis)) {
                vis[nx][ny][nz] = true;
                q.push({Point(nx, ny, nz), dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int X,Y,Z; cin>>X>>Y>>Z;

    int x,y,z,x1,y1,z1; cin >> x >> y >> z >> x1 >> y1 >> z1;
    Point src(x,y,z);
    Point dest(x1,y1,z1);

    vector<vector<vector<int>>> grid(X, vector<vector<int>>(Y, vector<int>(Z)));
    for(int i = 0; i < X; i++)
        for(int j = 0; j < Y; j++)
            for(int k = 0; k < Z; k++)
                cin >> grid[i][j][k];
            

    int result = shortestPath(grid, src, dest);

    if (result != -1) {
        cout << "Shortest path length is: " << result << endl;
    } else {
        cout << "No path exists between the source and destination." << endl;
    }

    return 0;
}
