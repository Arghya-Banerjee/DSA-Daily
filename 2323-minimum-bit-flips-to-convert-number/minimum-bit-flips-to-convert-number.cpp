class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int cnt = 0;
        while(temp) {
            cnt += (temp & 1);
            temp /= 2;
        }
        return cnt;
    }
};