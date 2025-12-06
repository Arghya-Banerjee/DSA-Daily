class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int ans = 0;
        int temp = 0;
        mpp[0] = 1;
        for(int i = 0; i < n; i++){
            temp += nums[i];
            if(mpp.count(temp - k) > 0) ans += mpp[temp-k];
            mpp[temp]++;
        }
        return ans;
    }
};