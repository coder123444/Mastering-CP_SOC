// CSES 1193 - Labyrinth
// Technique: BFS shortest path on grid + path reconstruction via parent pointers
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n);
    for (auto &row : grid) cin >> row;

    int sr, sc, er, ec;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'A') { sr = r; sc = c; }
            if (grid[r][c] == 'B') { er = r; ec = c; }
        }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveChar(n, vector<char>(m, '?'));

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dirName[] = {'U', 'D', 'L', 'R'};

    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    bool found = false;
    while (!q.empty() && !found) {
        auto [r, c] = q.front(); q.pop();
        if (r == er && c == ec) { found = true; break; }
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (visited[nr][nc] || grid[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            parent[nr][nc] = {r, c};
            moveChar[nr][nc] = dirName[d];
            q.push({nr, nc});
        }
    }

    if (!visited[er][ec]) {
        cout << "NO\n";
        return 0;
    }

    string path;
    int r = er, c = ec;
    while (!(r == sr && c == sc)) {
        path += moveChar[r][c];
        auto [pr, pc] = parent[r][c];
        r = pr; c = pc;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}
