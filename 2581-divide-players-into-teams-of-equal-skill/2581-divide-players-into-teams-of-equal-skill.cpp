class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long totalChemistry = 0;

        // Calculate the target sum
        int targetTeamSkill = skill[0] + skill[n - 1];

        // Iterate through half of the array, pairing players from both ends
        for (int i = 0; i < n / 2; i++) {
            int currentTeamSkill = skill[i] + skill[n - i - 1];

            // If any team's skill doesn't match the target, return -1
            if (currentTeamSkill != targetTeamSkill) {
                return -1;
            }

            // Calculate and add the chemistry of the current team
            totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
        }

        return totalChemistry;
    }
};