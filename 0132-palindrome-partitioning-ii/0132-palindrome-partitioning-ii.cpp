class Solution {
public:
 int t[2001][2001];
 bool palindrome(string &s,int i,int j){
     int n=s.size();
     while(i<j){
         if(s[i] != s[j]){
             return false;
         }
         i++;
         j--;
     }
     return true;
 }
  int solve(string&s , int i,int j){
      if(  palindrome(s, i, j)){
          return 0;
      }
      if(t[i][j]!=-1){
          return t[i][j];
      }
      int cnt=INT_MAX;
      for(int k=i;k<j;k++){
          if(palindrome(s,i,k)){
              int karan=1+solve(s,k+1,j);
              cnt=min(cnt,karan);
          }
      }
      return t[i][j]=cnt;
      
  }
    int minCut(string &s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.size()-1);

    }
};