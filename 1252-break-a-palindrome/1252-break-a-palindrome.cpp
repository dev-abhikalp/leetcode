class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length=palindrome.length();
        if(length==1){
            return "";
        }

        bool changed = false;

        for(int i=0;i<length/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                changed = true;
                break;
            }
        }
        if(!changed){
            palindrome[length-1]='b';
        }
        return palindrome;
    }
};