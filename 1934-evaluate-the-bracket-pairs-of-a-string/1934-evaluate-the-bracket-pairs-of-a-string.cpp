class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto &it : knowledge){
            mp[it[0]] = it[1];
        }
        string result="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                auto it = mp.find(temp);
                if(it != mp.end()){
                    result += it->second;
                }
                else{
                    result+="?";
                }
            }
            else{
                result+=s[i];
            }
        }
        return result;
    }
};