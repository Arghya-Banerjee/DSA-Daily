class Solution {
public:
    int n;

    bool isPos(int k, vector<int> &nums, vector<vector<int>> &q){
        vector<int> arr(n+1, 0);
        for(int i = 0; i < k; i++){
            arr[q[i][0]] += q[i][2];
            arr[q[i][1] + 1] -= q[i][2];
        }
        long sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        int high = queries.size();
        int low = 0;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPos(mid, nums, queries)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};