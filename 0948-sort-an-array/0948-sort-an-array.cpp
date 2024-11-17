class Solution {
public:
    void mergesort(vector<int>&arr,int s,int e){
        int mid=s+(e-s)/2;
        int len1=mid-s+1;
        int len2=e-mid;

        int *arr1=new int[len1];
        int *arr2=new int[len2];

        int index=s;
        for(int i=0;i<len1;i++){
            arr1[i]=arr[index++];
        }

        index=mid+1;
        for(int i=0;i<len2;i++){
            arr2[i]=arr[index++];
        }

        int ind1=0;
        int ind2=0;
        index=s;

        while(ind1<len1 && ind2<len2){
            if(arr1[ind1]<=arr2[ind2]){
                arr[index++]=arr1[ind1++];
            }
            else{
                arr[index++]=arr2[ind2++];
            }

        }

        while(ind1<len1){
            arr[index++]=arr1[ind1++];
        }
        while(ind2<len2){
             arr[index++]=arr2[ind2++];
        } 
        delete[] arr1;
        delete[] arr2;       
}

void ms(vector<int>&arr,int s,int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;

    ms(arr,s,mid);
    ms(arr,mid+1,e);
    mergesort(arr,s,e);
}
    vector<int> sortArray(vector<int>& nums) {

        ms(nums,0,nums.size()-1);
        return nums;
        
    }
};