class Solution {
public:
    long long rec(int num , long long rev){
        if(num == 0){
            return rev;
        }
        rev = rev * 10 + num % 10;
        return rec(num / 10 , rev);
    }

    int reverse(int x) {
        long long res = rec(abs(x) , 0) * (x > 0 ? 1 : -1);
        if(res < INT_MIN || res > INT_MAX)
            return 0;
        return res;    
    }
};
