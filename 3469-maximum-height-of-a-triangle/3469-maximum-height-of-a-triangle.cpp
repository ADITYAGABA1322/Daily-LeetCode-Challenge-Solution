class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // Helper function to calculate the maximum height starting with a specific color
        auto calcMaxHeight = [](int startColorBalls, int otherColorBalls) -> int {
            int level = 1, maxHeight = 0;
            while (true) {
                if (level % 2 == 1) { // If the level is odd, use startColorBalls
                    if (startColorBalls >= level) {
                        startColorBalls -= level;
                    } else {
                        break; // Not enough balls to fill this level
                    }
                } else { // If the level is even, use otherColorBalls
                    if (otherColorBalls >= level) {
                        otherColorBalls -= level;
                    } else {
                        break; // Not enough balls to fill this level
                    }
                }
                maxHeight = level; // Update maxHeight after successfully filling a level
                level++;
            }
            return maxHeight;
        };

        // Calculate the maximum height for both starting colors
        int maxHeightStartingWithRed = calcMaxHeight(red, blue);
        int maxHeightStartingWithBlue = calcMaxHeight(blue, red);

        // Return the maximum of the two heights
        return std::max(maxHeightStartingWithRed, maxHeightStartingWithBlue);
    }
};