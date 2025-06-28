class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, -1);

        for(int i = 0; i < v; i++) {
            if(vis[i] == -1) {
                queue<pair<int, int>> q;
                q.push({i, 0});
                vis[i] = 0;

                while(!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    int node = it.first;
                    int color = it.second;

                    for(auto child : graph[node]) {
                        if(vis[child] != -1) {
                            if(vis[child] != 1 - color) 
                                return false;
                        } else {
                            vis[child] = 1 - color;
                            q.push({child, 1 - color});
                        }
                    }
                }
            }
        }
        return true;
    }
};
