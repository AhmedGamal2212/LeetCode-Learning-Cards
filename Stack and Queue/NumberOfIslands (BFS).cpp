class Solution {
public:
    
    vector<vector<bool>> vis;
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

    void bfs(int& i, int& j, vector<vector<char>>& grid){
        
        auto isValid = [&](int& x, int& y){
            return x >= 0 and x < grid.size() and y >= 0 and y < grid.front().size();
        };
        
        queue<pair<int, int>> q;
        
        vis[i][j] = true;
        q.push({i, j});
        while(not q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            
            for(int idx = 0; idx < 4; idx++){
                int currI = curr.first + dx[idx],
                currJ = curr.second + dy[idx];
                
                if(isValid(currI, currJ) and grid[currI][currJ] == '1' and not vis[currI][currJ]){
                    q.push({currI, currJ});
                    vis[currI][currJ] = true;
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vis.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(not vis[i][j] and grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid);
                }
            }
        }
        return cnt;
        
    }
};