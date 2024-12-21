class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int s=0;
        int e=n-1;
        char karan=letters[0];  // pehle character ko update krta rhega yeh
        while(s<=e){
            int mid=s+(e-s)/2;
            // if(letters[mid]==target){
            //     return mid;
            // }
            if(letters[mid]>target){
                e=mid-1;
                karan=letters[mid];

            }
            else{
                s=mid+1;
            }
        }
        return karan;
        
    }
};