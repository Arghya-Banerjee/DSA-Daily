class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i: nums) mpp[i]++;
        vector<vector<int>> freq(nums.size()+1);
        for(auto it: mpp) freq[it.second].push_back(it.first);
        vector<int> ans;
        for(int i = freq.size()-1; i > 0; i--){
            for(int it: freq[i]){
                ans.push_back(it);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};