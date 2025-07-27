class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int u = a[0][0];
        int v = a[0][1];
        int n = a.size();
        for(int i = 1; i < n; i++){
            if(a[i][0] > v) {
                ans.push_back({u, v});
                u = a[i][0];
                v = a[i][1];
            }
            else{
                v = max(v, a[i][1]);
            }
        }
        ans.push_back({u, v});
        return ans;
    }
};