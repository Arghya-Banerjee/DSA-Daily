class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        int temp = values[0] + 0;
        for(int j = 1; j < n; j++){
            ans = max(ans, temp + values[j] - j);
            temp = max(temp, values[j] + j);
        }
        return ans;
    }
};