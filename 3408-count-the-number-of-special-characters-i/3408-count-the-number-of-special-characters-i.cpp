class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26]={};
        bool upper[26]={};
        int cnt=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                upper[word[i] - 'A'] = true;
            }
            else if(word[i]>='a' && word[i]<='z'){
                lower[word[i] - 'a'] = true;
            }
        }
        for(int i=0;i<26;i++){
            if(lower[i] && upper[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};