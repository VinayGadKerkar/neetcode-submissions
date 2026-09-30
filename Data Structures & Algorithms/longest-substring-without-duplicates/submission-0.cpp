class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char , int> mp;
        int ans = 0 , left = 0;
        for(int right = 0 ; right < n ; right++){
            char ch = s[right];
            mp[ch]++;
            while(left <= right && mp[ch] > 1){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};
