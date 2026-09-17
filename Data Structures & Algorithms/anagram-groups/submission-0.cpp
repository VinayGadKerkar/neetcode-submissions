class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> anagrams;
        for(string &str : strs){
            string temp = str;
            sort(temp.begin() , temp.end());
            anagrams[temp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it = anagrams.begin() ; it != anagrams.end() ; it++){
            res.push_back(it -> second);
        }
        return res;
    }
};
