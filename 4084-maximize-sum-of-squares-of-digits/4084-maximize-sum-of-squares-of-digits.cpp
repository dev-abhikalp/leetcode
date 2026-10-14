class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9){
            return "";
        }
        int totalNine=sum/9;
        int remain=sum%9;
        string result(totalNine,'9');
        if(remain>0){
            result.push_back(remain+'0'); // +'0' is added to convert to character from int
        }
        result.append(num-result.length(),'0');// remaining digits are appended as 0
        return result;

    }
};