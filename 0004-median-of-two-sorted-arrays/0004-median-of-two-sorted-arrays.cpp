class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
      
        vector<int> nums3;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        int k=nums3.size();
        if(k%2==0){
            return (nums3[k/2]+nums3[(k/2)-1])/2.0;
        }
        else{
            return nums3[(k/2)];
        }

    }
};