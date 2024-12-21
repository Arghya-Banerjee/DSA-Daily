class Solution {
private:
    int dfs(vector<vector<int>> &adj, int node, int parent, vector<int> &values, int k, int &cnt){
        long sum = values[node];
        for(int child: adj[node]){
            if(child != parent) sum += dfs(adj, child, node, values, k, cnt);
        }
        if(sum % k == 0) cnt++;
        return sum % k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        dfs(adj, 0, -1, values, k, cnt);
        return cnt;
    }
};