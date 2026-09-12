class Solution {
public:
    int dx[4] = {1 , -1 , 0 , 0};
    int dy[4] = {0 , 0 , 1 , -1};
    void dfs(int x , int y , vector<vector<char>> &grid , vector<vector<bool>> &visited){
        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i++){
            int newX = dx[i] + x;
            int newY = dy[i] + y;
            if(newX >= grid.size() || newY >= grid[0].size() || newX < 0 || newY < 0 || visited[newX][newY])
                continue;
            if(grid[newX][newY] == '1')
                dfs(newX , newY , grid , visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(n , vector<bool> (m , false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i , j , grid , vis);
                    islands++;
                }
        }
        return islands;
    }
};
