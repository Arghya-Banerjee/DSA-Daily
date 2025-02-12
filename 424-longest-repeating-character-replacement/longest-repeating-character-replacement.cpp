class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26, 0);
        int maxi = -1;
        int maxf = 0;
        int l = 0, r = 0;
        while(r < s.size()){
            f[s[r]-'A']++;
            maxf = max(maxf, f[s[r]-'A']);
            if(r - l + 1 - maxf > k){
                f[s[l]-'A']--;
                l++;
                maxf = max(maxf, *max_element(f.begin(), f.end()));
            }
            if(r - l + 1 - maxf <= k){
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }
        return maxi;
    }
};