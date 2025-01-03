class Solution {
public:
bool solve(vector<string>&board,int row,int col,int n){
    int i,j;
    i=row;
    j=col;
    
    //upward
    while(i>=0 && j>=0 && i<n && j<n ){
        if(board[i][j]=='Q')
            return false;
        
        i--;
    }
    i=row;
    j=col;
    // downward
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
            i++;
        
    }
    i=row;
    j=col;
    //left
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        j--;
    }
    i=row;
    j=col;
    //right
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        j++;
    }
    i=row;
    j=col;
    // up right digaonal
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        i--;
        j++;
    }
    i=row;
    j=col;
    //up left diagonal
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        i--;
        j--;
    }
    i=row;
    j=col;
    //down right
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        i++;
        j++;
    }
    i=row;
    j=col;
    //down left
    while(i>=0 && j>=0 && i<n && j<n ){
         if(board[i][j]=='Q')
            return false;
        
        i++;
        j--;
    }
    return true;
}

void hello(vector<string>&board ,int row,int n,vector<vector<string>>&ans){
    if(row==n){
        ans.push_back({board});
        return;
    }
    for(int j=0;j<n;j++){
        if(solve(board,row,j,n)){
            board[row][j]='Q';
            hello(board,row+1,n,ans);
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        hello(board,0,n,ans);
        return ans;
        
    }
};