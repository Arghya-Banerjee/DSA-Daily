class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int area2 = abs(bx1 - bx2) * abs(by1 - by2);
        int overlapX = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapY = max(0, min(ay2, by2) - max(ay1, by1));
        int area = area1 + area2 - (overlapX * overlapY);
        return area;
    }
};