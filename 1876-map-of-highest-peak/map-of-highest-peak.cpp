class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    // cout << i << " " << j << endl;
                    q.push({0, {i, j}});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int height = it.first;
            int i = it.second.first;
            int j = it.second.second;

            // 0 0
            // 0 0
            
            if(!vis[i][j]){
                vis[i][j] = 1;
                isWater[i][j] = height;
                // cout << i << " " << j << " " << height << endl;
                for(auto dir: dirs){
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]){
                        // cout << ni << " " << nj << " " << height +1 << endl;
                        q.push({height+1, {ni, nj}});
                    }
                }
            }
        }
        return isWater;
    }
};