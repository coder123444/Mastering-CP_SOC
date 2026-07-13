// CSES 1194 - Monsters
// Technique: Multi-source BFS from all monsters to compute the time each cell
// becomes reachable by a monster, then BFS from player - a move is valid only
// if the player reaches that cell strictly before any monster could.
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n);
    for (auto &row : grid) cin >> row;

    vector<vector<int>> monsterDist(n, vector<int>(m, INF));
    queue<pair<int,int>> mq;
    int pr = -1, pc = -1;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'M') { monsterDist[r][c] = 0; mq.push({r, c}); }
            if (grid[r][c] == 'A') { pr = r; pc = c; }
        }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dirName[] = {'U', 'D', 'L', 'R'};

    while (!mq.empty()) {
        auto [r, c] = mq.front(); mq.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || monsterDist[nr][nc] != INF) continue;
            monsterDist[nr][nc] = monsterDist[r][c] + 1;
            mq.push({nr, nc});
        }
    }

    vector<vector<int>> playerDist(n, vector<int>(m, INF));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveChar(n, vector<char>(m, '?'));
    queue<pair<int,int>> pq;
    playerDist[pr][pc] = 0;
    pq.push({pr, pc});

    pair<int,int> exitCell = {-1, -1};

    while (!pq.empty()) {
        auto [r, c] = pq.front(); pq.pop();
        // Check if this cell is on the boundary -> can escape
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            exitCell = {r, c};
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || playerDist[nr][nc] != INF) continue;
            int newDist = playerDist[r][c] + 1;
            if (newDist >= monsterDist[nr][nc]) continue; // monster reaches at same time or earlier
            playerDist[nr][nc] = newDist;
            parent[nr][nc] = {r, c};
            moveChar[nr][nc] = dirName[d];
            pq.push({nr, nc});
        }
    }

    if (exitCell.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string path;
    int r = exitCell.first, c = exitCell.second;
    while (!(r == pr && c == pc)) {
        path += moveChar[r][c];
        auto [ppr, ppc] = parent[r][c];
        r = ppr; c = ppc;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}
