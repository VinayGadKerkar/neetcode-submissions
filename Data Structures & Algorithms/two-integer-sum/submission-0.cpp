class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> targets;
        for(int i = 0 ; i < nums.size() ; i++){
            if(targets.count(nums[i])){
                return {targets[nums[i]] , i};
            }
            targets[target - nums[i]] = i;
        }
        return {};
    }
};
