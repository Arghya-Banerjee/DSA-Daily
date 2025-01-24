class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, int vis[], int pathvis[], int check[]){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto child : adj[node]){
            if(!vis[child]){
                if(dfs(child, adj, vis, pathvis, check)) return true;
            }
            else if(pathvis[child]) return true;
        }

        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[10008] = {0};
        int pathvis[10008] = {0};
        int check[10008] = {0};
        for(int i = 0; i < n; i++){
            dfs(i, adj, vis, pathvis, check);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};