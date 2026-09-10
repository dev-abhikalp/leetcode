class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long MASS=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(MASS<asteroids[i]){
                return false;
            }
            else{
                MASS+=asteroids[i];
            }
        }
        return true;
    }
};