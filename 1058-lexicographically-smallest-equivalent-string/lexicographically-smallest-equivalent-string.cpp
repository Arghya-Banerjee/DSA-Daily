class Solution {
private:
    char dfs(char node, unordered_map<char, vector<char>> &adj, vector<int> &vis){
        vis[node-'a'] = 1;
        char minCh = node;
        for(char &child: adj[node]){
            if(!vis[child - 'a']){
                minCh = min(minCh, dfs(child, adj, vis));
            }
        }
        return minCh;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        unordered_map<char, vector<char>> adj;
        for(int i = 0; i < n; i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        for(int i = 0; i < m; i++){
            char ch = baseStr[i];
            vector<int> vis(26, 0);
            char chMin = dfs(ch, adj, vis);
            result.push_back(chMin);
        }
        return result;
    }
};