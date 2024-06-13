class Solution {
public:
//  1 2 3 4  (5 +6)
//  10 8 6 12 (7+4)
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans = 0 ;
        for(int i=0; i <seats.size(); i++){
            ans+=abs(seats[i]- students[i]);
        }
        return ans ;
    }
};