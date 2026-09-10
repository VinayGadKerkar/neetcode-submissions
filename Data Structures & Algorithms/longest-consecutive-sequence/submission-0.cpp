class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin() , nums.end());
        for(int num : s){
            if(s.find(num -1) == s.end()){
                int length = 1;
                while(s.find(num + length) != s.end())
                    length++;
                ans = max(length , ans);
            }
        }
        return ans;
    }
};
