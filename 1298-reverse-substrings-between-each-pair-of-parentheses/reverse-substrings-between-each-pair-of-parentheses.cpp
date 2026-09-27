class Solution {
public:
    string reverseParentheses(string s) {
        string answer;
        vector<int> starts;

        for (char ch : s) {
            if (ch == '(') {
                starts.push_back(static_cast<int>(answer.size()));
            } else if (ch == ')') {
                int start = starts.back();
                starts.pop_back();

                reverse(answer.begin() + start, answer.end());
            } else {
                answer.push_back(ch);
            }
        }

        return answer;
    }
};