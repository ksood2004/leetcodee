class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=n*m-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            
            int ele=matrix[mid/m][mid%m];
            if(ele==target){
                return true;
            }
            else if(ele>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};