class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int mid = 0 ;mid<n ; mid++){
            // lets search for the left small
            int left_ct = 0;
            for(int left = 0 ; left<mid ; left++){
                if(rating[left] < rating[mid]) left_ct++;
            }
            int right_ct = 0;
            for(int right = mid+1 ; right<n; right++){
                if(rating[right] > rating[mid]) right_ct++;
            }
            ans+=(left_ct * right_ct);
        }


        for(int mid = 0 ;mid<n ; mid++){
            // lets search for the left small
            int left_ct = 0;
            for(int left = 0 ; left<mid ; left++){
                if(rating[left] > rating[mid]) left_ct++;
            }
            int right_ct = 0;
            for(int right = mid+1 ; right<n; right++){
                if(rating[right] < rating[mid]) right_ct++;
            }
            ans+=(left_ct * right_ct);
        }
        return ans ;
    }
};