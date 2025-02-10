#include<bits/stdc++.h>

class Solution {
public:
    string clearDigits(string s) {
        
        while (true) {
            int ind = s.find_first_of("0123456789");
            if (ind == string::npos) {
                break;
            }

            int ndInd = ind; 
            for (int i = ind; i > 0; i--) {
                if (!isdigit(s[i - 1])) {
                    ndInd = i - 1;
                    break;
                }
            }

            s.erase(ind, 1);
            s.erase(ndInd, 1);
        }
        return s;
    }
};