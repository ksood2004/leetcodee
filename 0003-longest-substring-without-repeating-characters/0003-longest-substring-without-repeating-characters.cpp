class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          int left=0,right=0,ans=0;
        int n=s.size();
        map<char,int>freq;
        int count=0;
        while(right<n){
            freq[s[right]]++;
            count++;
            
            if(freq.size()==count){
                ans=max(ans,right-left+1);
            }
            else{
                while(freq.size()<count){
                    freq[s[left]]--;
                    count--;
                    if(freq[s[left]]==0){
                        freq.erase(s[left]);
                    }
                    left++;
                }
            }
            right++;
        }
        
        return ans;
        
    }
    
};