class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int mid;
        int s=0;
        int e=col-1;
         while(s<row and e>=0)
        {
            if(matrix[s][e]==target)
                return true;
                
            if(matrix[s][e]>target)
                e--;
            else
                s++;
        }
        
        return false;
    }
    
};