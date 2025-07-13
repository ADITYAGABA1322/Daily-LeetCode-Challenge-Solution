class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // The problem is seems to be a simple, but how should we solve this? The problem is based on the when I read through the question is a greedy or sorting, and the two pointer base approach but these things are help me in this question let's find out the way we want to first sold the trainers and the players in between we match the players according to the trainers and we want to match similar as like taking the players as the Hyatt and Jay for the trainers, we want to match the player based on the maximum size like if we say we want to reverse the trainers sorting and players in the sort, and we want to match the pairs for the first three elements like in which like taking example one in history elements we want to match for seven is less than equal to eight and we return that number of count
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());
        int matches = 0 , trainerIndex = 0 , playerIndex = 0;
        while(playerIndex < players.size() && trainerIndex < trainers.size()){
            if(players[playerIndex] <= trainers[trainerIndex]){
                matches++;
                playerIndex++;
                trainerIndex++;
            } else{
                trainerIndex++;
            }
        }
        return matches;
    }
};