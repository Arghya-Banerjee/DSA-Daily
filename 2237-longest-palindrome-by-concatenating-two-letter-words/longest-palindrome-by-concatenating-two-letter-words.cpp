class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // 1 odd other even or all even
        unordered_map<string, int> mpp;
        int cnt = 0;
        for(string s: words) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(mpp[rev] > 0) {
                cnt+=4;
                mpp[rev]--;
            }
            else {
                mpp[s]++;
            }
        }
        int maxi = 0;
        for(auto it: mpp) {
            if(it.first[0] == it.first[1]) {
                maxi = max(maxi, it.second*2);
            }
        }
        return cnt + maxi;
    }
};