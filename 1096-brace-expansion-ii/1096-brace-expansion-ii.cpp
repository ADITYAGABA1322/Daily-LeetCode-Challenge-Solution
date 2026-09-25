class Solution {
    string expression;
    int idx;

    // item -> letter | { expr }
    set<string> item() {
        set<string> ret;
        if (expression[idx] == '{') {
            idx++;
            ret = expr();
        } else {
            ret = {string(1, expression[idx])};
        }
        idx++;
        return move(ret);
    }

    // term -> item | item term
    set<string> term() {
        // Initialize an empty set and take its Cartesian product with
        // subsequent results
        set<string> ret = {""};
        // An item starts with { or a lowercase letter; continue matching only
        // when this condition is met
        while (idx < expression.size() &&
               (expression[idx] == '{' || isalpha(expression[idx]))) {
            auto sub = item();
            set<string> tmp;
            for (auto& left : ret) {
                for (auto& right : sub) {
                    tmp.insert(left + right);
                }
            }
            ret = move(tmp);
        }
        return move(ret);
    }

    // expr -> term | term, expr
    set<string> expr() {
        set<string> ret;
        while (true) {
            // Take the union with the result of term()
            ret.merge(term());
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < expression.size() && expression[idx] == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return move(ret);
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expression = expression;
        this->idx = 0;
        auto ret = expr();
        return {ret.begin(), ret.end()};
    }
};