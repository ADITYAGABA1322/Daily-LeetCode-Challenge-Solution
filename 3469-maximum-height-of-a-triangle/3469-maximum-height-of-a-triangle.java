class Solution {
    int calcMaxHeight (int startColorBalls , int otherColorBalls){
        int level = 1 , maxHeight = 0;
        while(true){
            if(level % 2 == 1){
                if(startColorBalls >= level) startColorBalls -= level;
                else break;
            }
            else{
                if(otherColorBalls >= level) otherColorBalls -= level;
                else break;
            }
            maxHeight = level;
            level++;
        }
        return maxHeight;
    }
    public int maxHeightOfTriangle(int red, int blue) {
        int maxHeightStartingWithRed =  calcMaxHeight(red , blue);
        int maxHeightStartingWithBlue = calcMaxHeight(blue , red);
        return Math.max(maxHeightStartingWithRed , maxHeightStartingWithBlue);
    }
}