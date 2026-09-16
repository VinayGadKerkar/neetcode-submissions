class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = n - 1;
        while(i < j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            
            char start = (char)tolower(s[i]);
            char end = (char)tolower(s[j]);
            if(start != end)
                return false;
            i++;
            j--;            
        }
        return true;
    }
};
