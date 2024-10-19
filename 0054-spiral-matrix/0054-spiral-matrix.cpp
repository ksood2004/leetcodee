class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total=row*col;

        int firstrow=0;
        int lastrow=row-1;
        int firstcol=0;
        int lastcol=col-1;

        while(count<total){

            //pehli row ko print karana hai
            for(int index=firstcol;index<=lastcol && count<total;index++){
                ans.push_back(matrix[firstrow][index]);
                count++; // ki kitne element store ho gye bcz loop ke liye
            }
            firstrow++;

            //last coloun ko print kar rha hai yeh
            for(int index=firstrow;index<=lastrow && count<total;index++){
                ans.push_back(matrix[index][lastcol]);
                count++;
            }
            lastcol--;

            //last coloumn print karne ke liye 
            for(int index=lastcol;index>=firstcol && count<total;index--){
                ans.push_back(matrix[lastrow][index]);
                count++;
            }
            lastrow--;

            //first col use karne ke liye
            for(int index=lastrow;index>=firstrow && count<total;index--){
                ans.push_back(matrix[index][firstcol]);
                count++;
            }
            firstcol++;
        }
        return ans;

        
    }
};