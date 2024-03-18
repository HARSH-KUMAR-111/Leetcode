class Solution {
public:
    //Comparator Sort -to sort the values by index 1
    static bool compSort(vector<int> &A,vector<int> &B){
        return A[1]<B[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()==0) return 0;

        sort(points.begin(),points.end(),compSort);
        int arrows=1;
        int lastptn=points[0][1];

        for(int i=1;i<points.size();i++){
            if(points[i][0]>lastptn){
                lastptn=points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};