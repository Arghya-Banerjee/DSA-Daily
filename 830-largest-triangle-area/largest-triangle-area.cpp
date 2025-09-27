class Solution {
private: 
    double getArea(vector<int> &a, vector<int> &b, vector<int> &c){
        double ans = (double)(1.0/2.0) * abs((a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1])));
        return ans;
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = -1;
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    maxi = max(maxi, getArea(points[i], points[j], points[k]));
                }
            }
        }
        return maxi;
    }
};