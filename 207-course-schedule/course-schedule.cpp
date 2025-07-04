class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto child: adj[node]){
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }
        }
        return cnt == n ? true : false;
    }
};