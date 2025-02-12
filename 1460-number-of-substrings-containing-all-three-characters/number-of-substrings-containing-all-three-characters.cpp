class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> f(3, -1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            f[c-'a'] = i;
            if(min({f[0], f[1], f[2]}) != -1) ans += min({f[0], f[1], f[2]}) + 1;
        }
        return ans;
    }
};