class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int firstrow=0;
        int lastrow=row-1;
        int firstcol=0;
        int lastcol=col-1;
        int count=0;
        vector<int> ans;
        while(count<total){
        for(int i=firstcol;i<=lastcol && count<total;i++){
            ans.push_back(matrix[firstrow][i]);
            count++;
        }
        firstrow++;
        for(int i=firstrow;i<=lastrow && count<total;i++){
            ans.push_back(matrix[i][lastcol]);
            count++;
        }
        lastcol--;
        for(int i=lastcol;i>=firstcol && count<total;i--){
            ans.push_back(matrix[lastrow][i]);
            count++;
        }
        lastrow--;
        for(int i=lastrow;i>=firstrow && count<total;i--){
            ans.push_back(matrix[i][firstcol]);
            count++;
        }
        firstcol++;
        
        
        }
        return ans;
    }
};