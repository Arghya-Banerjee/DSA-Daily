class Solution {
private:
    int f(vector<int> &nums, int k){
        if(k < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &it: nums) it = it%2;
        return f(nums, k) - f(nums, k-1);
    }
};