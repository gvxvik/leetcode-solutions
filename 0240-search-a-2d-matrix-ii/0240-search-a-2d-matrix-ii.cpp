class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(),
        rowIndex = 0, colIndex = cols-1,
        current = 0;

        while(colIndex+1 && rowIndex-rows){
            current = matrix[rowIndex][colIndex];
            if(current == target) return true;
            else if(current > target) --colIndex;
            else ++rowIndex;
        }
        
        return false;
    }
};