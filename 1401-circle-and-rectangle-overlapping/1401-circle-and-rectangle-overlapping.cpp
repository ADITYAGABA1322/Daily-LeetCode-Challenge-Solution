class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       int closestX = clamp(xCenter , x1 , x2);
       int closestY = clamp(yCenter , y1 , y2);
       //return sqrt(pow(closestX - xCenter, 2) + pow(closestY - yCenter, 2)) <= radius;
       return pow(closestX - xCenter, 2) + pow(closestY - yCenter, 2) <= radius*radius;
    }
};