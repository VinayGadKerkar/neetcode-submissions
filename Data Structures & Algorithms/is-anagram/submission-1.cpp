class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i = 0 ; i < s.size() ; i++){
            int idx1 = s[i] - 'a';
            int idx2 = t[i] - 'a';
            count[idx1]++;
            count[idx2]--;
        }
        for(int i = 0 ; i < 26 ; i++)
            if(count[i] != 0)
                return false;
        return true;
    }
};
