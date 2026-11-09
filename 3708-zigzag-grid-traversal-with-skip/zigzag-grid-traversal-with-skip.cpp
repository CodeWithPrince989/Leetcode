#include <vector>

class Solution {
public:
    std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> result;
        bool take = true; // Flag to alternate between taking and skipping a cell
        
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                // Traverse left to right
                for (int j = 0; j < n; ++j) {
                    if (take) {
                        result.push_back(grid[i][j]);
                    }
                    take = !take; // Flip flag for the next cell
                }
            } else {
                // Traverse right to left
                for (int j = n - 1; j >= 0; --j) {
                    if (take) {
                        result.push_back(grid[i][j]);
                    }
                    take = !take; // Flip flag for the next cell
                }
            }
        }
        
        return result;
    }
};