class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(dist[adjNode] > dis + adjWt){
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis + adjWt, adjNode});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1, dist.end());
        if(maxi == INT_MAX) return -1;
        else return maxi;
    }
};