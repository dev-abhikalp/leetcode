class Solution {
public:
    int minOperations(string s) {
       int n=s.size();
       if(is_sorted(begin(s),end(s))) {
        return 0;
       }

       if(n==2){ // if length of the string is 2 , it can't be sorted 
        return -1;
       }

       // finding min and max characters from the string 
       char min_char=*min_element(begin(s),end(s));
       char max_char=*max_element(begin(s),end(s));

       if(s[0]==min_char||s[n-1]==max_char){
        return 1;
       }

       // if  max and min in the  middle 
       char max_mid=*max_element(begin(s)+1,end(s)-1);
       char min_mid=*min_element(begin(s)+1,end(s)-1);

       if(s[0]>max_mid  && s[n-1]<min_mid){
        return 3;
       }
       return 2;   
    }
};