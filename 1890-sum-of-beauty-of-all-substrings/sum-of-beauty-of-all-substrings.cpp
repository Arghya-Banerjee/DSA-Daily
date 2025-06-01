class Solution {
private:
    int getBeauty(vector<int> &f) {
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto it: f) {
            if(it != 0){
                maxi = max(maxi, it);
                mini = min(mini, it);
            }
        }
        return maxi - mini;
    }

public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> f(26, 0); 
            for(int j = i; j < n; j++) {
                f[s[j]-'a']++;
                ans += getBeauty(f);
            }
        }
        return ans;
    }
};