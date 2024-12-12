class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size(), vector<pair<int, int>>());
        for(int i = 0; i < points.size(); i++){
            vector<int> curr = points[i];
            for(int j = 0; j < points.size(); j++){
                if(j == i) continue;
                adj[i].push_back({abs(curr[0] - points[j][0]) + abs(curr[1] - points[j][1]), j});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(points.size(), 0);
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(pair<int, int> neigh: adj[node]){
                if(!vis[neigh.second]) pq.push({neigh});
            }  
        }
        return sum;
    }
};