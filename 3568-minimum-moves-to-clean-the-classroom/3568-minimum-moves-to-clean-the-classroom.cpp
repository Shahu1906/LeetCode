class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        vector<pair<int, int>> litter;

        // Find start and litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

        // Assign every litter a bit index
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            litterId[litter[i].first][litter[i].second] = i;
        }

        // best[x][y][mask] = maximum energy remaining
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        // {x, y, mask, remainingEnergy}
        queue<array<int, 4>> q;

        q.push({sx, sy, 0, energy});
        best[sx][sy][0] = energy;

        int moves = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, mask, currEnergy] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask) {
                    return moves;
                }

                // No energy -> cannot move
                if (currEnergy == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Out of bounds
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        int id = litterId[nx][ny];
                        newMask |= (1 << id);
                    }

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Only continue if this state has MORE energy
                    // than any previously seen version
                    if (newEnergy > best[nx][ny][newMask]) {
                        best[nx][ny][newMask] = newEnergy;
                        q.push({nx, ny, newMask, newEnergy});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};