// TC->O(nlogn)
// SC->O(n)
class Solution {
public:
    void merge(vector<int> &arr,int s,int mid,int e){
        vector<int> t1(mid-s+1);
        vector<int> t2(e-mid);

        for(int i=0;i<t1.size();i++){
            t1[i] = arr[i+s];
        }
        for(int i=0;i<t2.size();i++){
            t2[i] = arr[mid+1+i];
        }
        int i=0,j=0;
        int k = s;
        while(i< t1.size() && j<t2.size()){
            if(t1[i]<=t2[j]){
                arr[k] = t1[i++];
            }
            else{
                arr[k] = t2[j++];
            }
            k++;
        }
        while(i< t1.size()){
            arr[k++] = t1[i++];
        }
        while(j< t2.size()){
            arr[k++] = t2[j++];
        }

    }
    void mergeSort(vector<int> &arr,int s,int e){
        if(s>=e) return ;

        int mid = s+(e-s)/2;

        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};