// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis,int xco,
            int yco, vector<pair<int,int>>& corr,int i, int j){
        vector<int> xrel = {0,-1,0,+1};
        vector<int> yrel = {-1,0,+1,0};
        corr.push_back({xco-i,yco-j});
        int n = grid.size();
        int m = grid[0].size();
        vis[xco][yco] = true;
        for(int k=0;k<4;k++){
            int newx = xco + xrel[k];
            int newy = yco + yrel[k];
            if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && grid[newx][newy]==1){
                dfs(grid,vis,newx,newy,corr,i,j);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> corr;
                    dfs(grid,vis,i,j,corr,i,j);
                    st.insert(corr);
                }
            }
        }
        return st.size();
    }
};
