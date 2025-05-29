class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (max(0LL, (long long)min(rec1[2], rec2[2]) - max(rec1[0], rec2[0])) * max(0LL, (long long)min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]))) > 0;
    }
};