class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 0;
                } 
                else vis[i][j] = INT_MAX;
            }
        }
        int d[5] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i = 0; i < 4; i++) {
                int nrow = row + d[i];
                int ncol = col + d[i+1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && mat[nrow][ncol] && vis[nrow][ncol] == INT_MAX){
                    vis[nrow][ncol] = vis[row][col]+1;
                    q.push({nrow, ncol});
                }
            }
        }
        return vis;
    }
};