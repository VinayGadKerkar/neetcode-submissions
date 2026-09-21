class Solution {
public:
    bool isValid(int i , int j , int n , int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int , int >> movements = {{1 , 0} , {0 , 1} , {-1 ,0} , {0 , -1}};
        vector<vector<int>> lev(n + 1 , vector<int>(m + 1 , INT_MAX));
        queue<pair<int , int>> q;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                    lev[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto cur_v = q.front();
            int cur_x = cur_v.first;
            int cur_y = cur_v.second;
            q.pop();
            for(auto movement : movements){
                int child_x = movement.first + cur_x;
                int child_y = movement.second + cur_y;
                if(!isValid(child_x , child_y , n , m)) continue;
                if(grid[child_x][child_y] == 0 || grid[child_x][child_y] == 2 ) continue;
                q.push({child_x , child_y});
                lev[child_x][child_y] = lev[cur_x][cur_y] + 1;
                grid[child_x][child_y] = 2;
                ans = max(ans ,lev[child_x][child_y]);
            }
        }

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m; j++)
                if(grid[i][j] == 1) return -1;
        
        return ans;

    }
};