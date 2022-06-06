#include <bits/stdc++.h>

using namespace std;

class subordinates {
public:
    vector<string> ans;

    int minimumRemoval(string s) {
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(')
                st.push(i);
            else if (c == ')') {
                if (st.empty()) {
                    st.push(i);
                } else if (s[st.top()] == '(') {
                    st.pop();

                } else {
                    st.push(i);

                }
            }
        }
        return st.size();
    }



    void dfs(int index, string s, int count, int open, string temp ) {
        if(count<0)
            return;

        //The below condition sucked my blood and last 5 test cases failed. ;-(
        //The condition says if the brackets to be removed are more than the string remaining, return;
        if(count> s.size()-index)
            return;
        if(index==s.size()){
            if(count==0 && open==0){
                ans.push_back(temp);
                return;
            }
            return;
        }



        char c=s[index];
        if(c=='('){
            //remove
            dfs(index+1, s, count-1, open, temp);
            //keep
            dfs(index+1, s, count, open+1, temp+c);


        }else if(c==')'){
            //only keep if open before it
            //remove
            dfs(index+1, s, count-1, open, temp); //? count+1
            if(open>0){
                dfs(index+1, s, count, open-1, temp+c);
            }

        }else{
            dfs(index+1, s, count, open, temp+c);
        }

    }

    vector<string> removeInvalidParentheses(string s) {
        int count = minimumRemoval(s);
        dfs(0, s, count, 0, "");
        unordered_set<string> final_ans(ans.begin(), ans.end());
        vector<string> vf(final_ans.begin(), final_ans.end());
        return vf;
    }
};

int main() {
    subordinates s;
    string s1 = "()())()";
    vector<string> ans = s.removeInvalidParentheses(s1);
    for (auto x: ans) {
        cout << x << endl;
    }
    return 0;
}