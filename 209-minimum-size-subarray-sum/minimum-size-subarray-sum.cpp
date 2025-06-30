class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int temp = 0;
        int mini = INT_MAX;
        while(l <= r && r < n){
            temp += nums[r];
            while(temp >= target){
                mini = min(mini, r - l + 1);
                temp -= nums[l];
                l++;
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};