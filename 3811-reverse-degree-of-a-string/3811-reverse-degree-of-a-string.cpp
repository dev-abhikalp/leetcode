class Solution {
public:
    int reverseDegree(string s) {
        long long  sum=0;
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            long long  prod=1;
            int revIndex=('z'-ch)+1;
            prod=(i+1)*revIndex;
            sum+=prod;
        }
        return sum;
    }
};