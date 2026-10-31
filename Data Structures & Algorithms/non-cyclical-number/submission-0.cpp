class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> seen;
        while(seen.find(n) == seen.end()){
            seen.insert(n);
            int temp = n , nextNum = 0;
            while(temp > 0){
                nextNum += (temp % 10) * (temp % 10) ;
                temp /= 10; 
            }
            n = nextNum;
            if(n == 1) return true;
        } 

        return false;
    }
};