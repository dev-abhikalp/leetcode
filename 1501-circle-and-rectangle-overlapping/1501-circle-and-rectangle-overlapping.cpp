class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX;
        int closestY;
 
        closestX=max(x1, min(xCenter, x2));
        closestY=max(y1, min(yCenter, y2));

        int dx=abs(xCenter-closestX);
        int dy=abs(yCenter-closestY);
        if((dx*dx+dy*dy)<=radius*radius) {
            return true;
        }
        return false;
    }
};