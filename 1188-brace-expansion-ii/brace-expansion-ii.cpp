class Solution {
public:
    string solve(string a, string b) {
        string ans = "";
        int i = 0;

        while (i < a.length()) {
            if (a[i] == ',' || a[i] == ' ') {
                i++;
                continue;
            }

            string s = "";

            while (i < a.length()) {
                if (a[i] == ',' || a[i] == ' ')
                    break;

                s += a[i];
                i++;
            }

            int j = 0;

            while (j < b.length()) {
                if (b[j] == ',' || b[j] == ' ') {
                    j++;
                    continue;
                }

                string l = "";

                while (j < b.length()) {
                    if (b[j] == ',' || b[j] == ' ')
                        break;

                    l += b[j];
                    j++;
                }

                if (l.length() == 0)
                    continue;

                string kk = s;
                kk += l;

                ans += kk + ',';
            }
        }

        return ans;
    }

    vector<string> braceExpansionII(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '}') {

                string k = "";

                while (!st.empty() && st.top() != "{") {
                    k = st.top() + k;
                    st.pop();
                }

                st.pop();

                if (!st.empty() && st.top() == ",") {
                    st.push(k);
                }
                else if (!st.empty() && st.top() != "{") {

                    string kk = st.top();
                    st.pop();

                    string sol = solve(kk, k);
                    st.push(sol);
                }
                else {
                    st.push(k);
                }
            }
            else {

                string k = "";
                k += s[i];

                if (k != "," && k != "{" &&
                    !st.empty() &&
                    st.top() != "," &&
                    st.top() != "{") {

                    string kk = st.top();
                    st.pop();

                    string sol = solve(kk, k);
                    st.push(sol);
                }
                else {
                    st.push(k);
                }
            }
        }

        set<string> ss;

        while (!st.empty()) {

            string kk = st.top();
            st.pop();

            int i = 0;
            string s = "";

            while (i < kk.length()) {

                if (kk[i] == ',' || kk[i] == ' ') {

                    if (s.length() != 0)
                        ss.insert(s);

                    s = "";
                }
                else {
                    s += kk[i];
                }

                i++;
            }

            if (s.length() != 0)
                ss.insert(s);
        }

        vector<string> ans;

        for (auto x : ss)
            ans.push_back(x);

        return ans;
    }
};