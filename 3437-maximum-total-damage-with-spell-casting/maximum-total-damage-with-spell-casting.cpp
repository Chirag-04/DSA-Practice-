class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> freq;
        map<int,long long> dp;
        for(int p : power){
            freq[p]++;
        }
        vector<int> unique_power;
        for(const auto & kv : freq){
            unique_power.push_back(kv.first);
        }
        sort(unique_power.begin(), unique_power.end());
        dp[-2] = 0;
        for(int dmg : unique_power){
            dp[dmg] = dp.rbegin()->second;
            auto it = dp.lower_bound(dmg-2);
            --it;          
            long long include = (long long) freq[dmg] * dmg + (*it).second; // this will be the best solution saw from idx 0 -> to dmg-2
            dp[dmg] = max(dp[dmg],include);
        }
        return dp.rbegin()->second;
    }
};