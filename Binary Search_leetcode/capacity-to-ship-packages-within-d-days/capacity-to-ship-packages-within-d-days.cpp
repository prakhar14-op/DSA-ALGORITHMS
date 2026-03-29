class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);

        while(l<h){
            int mid=(l+h)/2;// taking mid as the capacity of the ship
            int days_needed=1;
            int current_load=0;
            
            for(int i=0;i<n;i++){
                if(current_load+weights[i]>mid){
                    days_needed++;
                    current_load=weights[i];
                }
                else{
                    current_load+=weights[i];
                }
            }

            if(days_needed>days){
                l=mid+1;// capacity badani padegi  
            }
            else{
                h=mid;
            }
        }
        return l;
    }
};