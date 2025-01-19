class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int row = 0; row < m; row++){
            for(int col: {0, n-1}){
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        } 

        for(int col = 0; col < n; col++){
            for(int row: {0, m-1}){
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        int water = 0;
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;
            for(vector<int> &dirs: directions){
                int nrow = i + dirs[0];
                int ncol = j + dirs[1];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                    water += max(height - heightMap[nrow][ncol], 0);
                    pq.push({max(height, heightMap[nrow][ncol]), {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }

        return water;
    }
};