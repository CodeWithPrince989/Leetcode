class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse Left to Right along the top row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++; // Move top boundary down

            // 2. Traverse Top to Bottom along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            // 3. Traverse Right to Left along the bottom row (if row exists)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--; // Move bottom boundary up
            }

            // 4. Traverse Bottom to Top along the left column (if column exists)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }

        return ans;
    }
};