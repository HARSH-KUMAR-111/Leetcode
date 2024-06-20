// Similar to Aggressive Cows problem
// Binary Search
// TC->O(nlog max(n))
// SC->O(1)
class Solution {
public:
    bool canPlace(vector<int> &arr,int force,int m){
        int coor=arr[0],cnt=1;

        for(int i=1;i<arr.size();i++){
            if(arr[i]-coor>=force){
                cnt++;
                coor=arr[i];
            }
        }
        cout<<cnt<<" ";
        return cnt>=m;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int s=1,e=1e9;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(canPlace(p,mid,m)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};