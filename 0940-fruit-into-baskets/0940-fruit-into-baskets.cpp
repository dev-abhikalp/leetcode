//Find the longest continuous sub array that has exactly 2 distinct elements
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int right=0;
        int left=0;
        int maxTree=0;
        unordered_map<int,int> mp; 
        while(right<fruits.size()){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                     mp.erase(fruits[left]);
                    }
                left++;
            }
            if(mp.size()<=2){
                int length=right-left+1;
                maxTree=max(maxTree,length);
            }
            right++;
        }
        return maxTree;
    }
};