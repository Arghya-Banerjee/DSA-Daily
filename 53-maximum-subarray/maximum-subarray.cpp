class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int i = 0;
        int n = nums.size();
        int temp = 0;
        while(i < n){
            if(temp < 0) temp = 0;
            temp += nums[i];
            maxi = max(maxi, temp);
            i++;
        }
        return maxi;
    }
};