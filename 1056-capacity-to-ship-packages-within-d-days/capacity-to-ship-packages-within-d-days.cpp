class Solution {
public:
    int daysNeed(vector<int>& weights,int load){
        int days = 1 , curr = 0 ;
        for(int i = 0 ; i < weights.size() ; i++){
            if(curr + weights[i] > load){
                days++;
                curr = weights[i];
            }
            else
                curr += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0); 
      
        while(low<=high){
            int mid = low + (high - low)/2;
            int day = daysNeed(weights,mid);
            if(day<=days)
                high = mid - 1 ; 
            else
                low = mid + 1 ;
        }
        return low ;
    }
};