class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2){
            return num;
        }

        unsigned int l = 0,
        r = num,
        m = 0;

        while(l+1 < r){
            m = (l+r) >> 1;
            if((float)m > (float)num/m) r = m;
            else l = m;
        }
        return l*l==num;
    }
};