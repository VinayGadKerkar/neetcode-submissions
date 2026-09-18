class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(int num : nums)
            mp[num]++;
        priority_queue<pair<int , int>> pq;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            pq.push({it -> second , it -> first});
        }

        vector<int> res;
        for(int i = 0 ; i < k ; i++){
            auto pr = pq.top();
            pq.pop();
            res.push_back(pr.second);
        }
        return res;
    }
};
