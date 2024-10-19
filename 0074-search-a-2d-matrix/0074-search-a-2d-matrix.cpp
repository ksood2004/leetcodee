class Solution {
public:
//     bool matrixx(vector<vector<int>>& matrix, int target,int row,int col){
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(matrix[i][j]==target){
//                     return true;
//                 }
//             }
//         }
//         return false;
// }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

       for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};