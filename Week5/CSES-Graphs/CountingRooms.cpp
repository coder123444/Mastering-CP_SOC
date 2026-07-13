// CSES 1192 - Counting Rooms
// Technique: Grid BFS/DFS flood fill to count connected components of '.' cells
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

void bfs(int sr, int sc) {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (visited[nr][nc] || grid[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n);
    for (auto &row : grid) cin >> row;
    visited.assign(n, vector<bool>(m, false));

    int rooms = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == '.' && !visited[r][c]) {
                rooms++;
                bfs(r, c);
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}
