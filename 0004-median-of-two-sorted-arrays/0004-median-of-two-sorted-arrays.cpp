class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int k=n+m;
        vector<int> nums3(k);
        nums3.insert(nums1.begin(),nums1.end(),nums3.begin());
        nums3.insert(nums2.begin(),nums2.end(),nums3.begin());
        if(k%2==0){
            return (nums3[k/2]-1)/2.0;
        }
        else{
            return (nums3[n/2]);
        }

    }
};