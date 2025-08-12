class Solution {
public:

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while(q.size() > 0) {
            auto node = q.front();
            q.pop();
            int r = node.first, c = node.second;

            for(int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if(nr >= 0 && nc >= 0 && nr < grid.size()
                    && nc < grid[0].size() && grid[nr][nc] == '1') {
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;        
    }
};