class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool sign = x<0?false:true;
        if(x == INT_MAX or x == INT_MIN) return 0;
        if(!sign) x *= -1;
        
        while(x){
            if(res > (INT_MAX-x%10)/double(10)) return 0;
            res = res*10+x%10;
            x /= 10;
        }
        if(!sign) res *= -1;
        
        return res;
    }
};