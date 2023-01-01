class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &token: tokens) {
            if(token == "+" || token=="-" || token == "/" || token =="*") {
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();

                int res;
                if(token == "+") {
                    res = top1 + top2;
                } else if(token == "-") {
                    res = top1 - top2;
                } else if(token == "*") {
                    res = top1 * top2;
                } else {
                    res = top1 / top2;
                }
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};