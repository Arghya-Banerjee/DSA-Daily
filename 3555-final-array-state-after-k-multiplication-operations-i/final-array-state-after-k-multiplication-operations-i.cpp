class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) pq.push({nums[i], i});
        while(k--){
            auto [val, ind] = pq.top();
            pq.pop();
            nums[ind] *= m;
            pq.push({val*m, ind});
        }
        return nums;
    }
};