class Solution {
public:
void rev(vector<char>& s,int i,int n){
        if(i>= n/2){
            return;
        }
        swap(s[i],s[n-i-1]);
	

        rev(s,i+1,n);

}
    void reverseString(vector<char>& s) {
        rev(s,0,s.size());
        
    }
};