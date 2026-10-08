class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }

            // Closing bracket
            else {
                if (stk.empty())
                    return false;

                char topch = stk.top();

                if ((ch == ')' && topch == '(') ||
                    (ch == '}' && topch == '{') ||
                    (ch == ']' && topch == '[')) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};