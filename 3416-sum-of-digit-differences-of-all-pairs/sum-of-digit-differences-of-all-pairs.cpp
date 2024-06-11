class Solution {
public:
    using ll = long long;

    ll sumDigitDifferences(std::vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;

        for(int digit = 0; digit < 10; digit++) {
           unordered_map<ll, ll> m;
           int sum = 0 ;
            for(int j = 0; j < n; j++) {
                ll last = nums[j] % 10;
                nums[j] = nums[j] / 10;
                m[last]++;
                sum++;
            }
            for(auto it : m){
                ans +=(it.second)*(sum-it.second);
            }
            }

        return (ans)/2;
    }
};