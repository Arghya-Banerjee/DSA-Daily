class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> a;
        for(int i = 1; i <= 10000000; i*=3) a.push_back(i);
        int sz = a.size();
        int ind = sz-1;
        while(ind >= 0 && n != 0){
            if(a[ind] > n) ind--;
            else {
                n -= a[ind];
                ind--;
            }
        }
        if(n == 0) return true;
        else return false;
    }
};