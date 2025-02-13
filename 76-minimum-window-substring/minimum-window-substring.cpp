class Solution {
private:
    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0; i < 58; i++){
            if(a[i] < b[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> ft(128, 0);  // Frequency of characters in t
        vector<int> f(128, 0);   // Frequency of characters in window
        
        int required = 0;  // Count of unique characters in t
        for (char c : t) {
            if (ft[c] == 0) required++;  // Unique character requirement
            ft[c]++;
        }
        
        int l = 0, r = 0, formed = 0;
        int minLen = INT_MAX, start = 0;
        
        while (r < s.size()) {
            char c = s[r];
            f[c]++;
            
            if (f[c] == ft[c]) formed++;
            
            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                
                char leftChar = s[l];
                f[leftChar]--;
                if (f[leftChar] < ft[leftChar]) formed--;
                
                l++;
            }
            r++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};