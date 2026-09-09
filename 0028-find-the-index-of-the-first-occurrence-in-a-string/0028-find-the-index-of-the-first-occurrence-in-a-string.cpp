class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=string::npos){
            int index=haystack.find(needle);
            return index;
        }
        else{
            return -1;
        }


    }
};