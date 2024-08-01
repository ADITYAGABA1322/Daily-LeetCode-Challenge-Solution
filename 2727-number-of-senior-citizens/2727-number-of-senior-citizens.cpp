class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (string& passengerInfo : details) {
            // Extract the digits of age
            int ageTens = passengerInfo[11] - '0';
            int ageOnes = passengerInfo[12] - '0';

            // Calculate the full age
            int age = ageTens * 10 + ageOnes;

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};