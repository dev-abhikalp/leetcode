// go from target to startValue and do '+1' and '/2' instead of '-1' & '*2' respectively 
// /2 only possible when number is even so make it even and then  divide by 2
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt=0;
        while(target > startValue){
            if(target % 2 == 1){
            target = target + 1  ;
            target  = target / 2;
            cnt=cnt+2;
            }
            else{
                target = target / 2 ;
                cnt++;
            }
            
        }
        if(target<=startValue){
            while(target!=startValue){
                target=target+1;
                cnt++;
            }
        }
        return cnt;
    }
};