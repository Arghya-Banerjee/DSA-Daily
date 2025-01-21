class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = -1;
        int n = nums.size()-1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, abs(nums[i]-nums[i+1]));
        }
        maxi = max(maxi, abs(nums[0]-nums[n]));
        return maxi;
    }
};