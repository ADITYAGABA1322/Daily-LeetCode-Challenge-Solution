class Solution {
public:
    bool canBeValid(string s, string locked) {
        //. base case if s.size() <= 1  return false or empty string return
        //false and we ned to find the the given s is valid or not acc to
        //perform op. ofr make vlaid the given  s is evne i fnot reutn flase ok
        //it even then gp and check where is 0 and find if like in even half of
        //this ( and half this ) if already reutn true and then not check for
        //acc to locaked check where is 0 and change it to make vliad ok its ok
        if (s.size() % 2 != 0)
            return false;
        if (s.size() <= 1)
            return false;
        // now we create a pass from left to right and right to left ok
        int open = 0, flex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                flex++;
            } else if (s[i] == '(') {
                open++;
            } else
                open--;
            if (open < 0) {
                if (flex > 0) {
                    flex--;
                    open++;
                } else
                    return false;
            }
        }

        //    Condition open < 0:

        // This condition checks if the balance of opening parentheses ( has
        // become negative. This means we have encountered more closing
        // parentheses ) than opening parentheses ( up to this point. Handling
        // Negative Balance:

        // If open < 0, it indicates an imbalance. We need to correct this
        // imbalance to maintain a valid sequence. We have two options: Use a
        // Flexible Character: If there are flexible characters available
        // (flexible > 0), we can use one of them to balance the parentheses.
        // This is done by decrementing flexible and incrementing open. No
        // Flexible Characters: If there are no flexible characters available
        // (flexible == 0), it is impossible to balance the parentheses, so we
        // return false.

        int close = 0;
        flex = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                flex++;
            } else if (s[i] == ')') {
                close++;
            } else
                close--;
            if (close < 0) {
                if (flex > 0) {
                    flex--;
                    close++;
                } else
                    return false;
            }
        }

        return true;
    }
};