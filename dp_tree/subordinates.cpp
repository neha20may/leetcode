class Solution {
public:
    bool valid(string s) {
        int comb1 = stoi(s);
        return (1 <= comb1 and comb1 <= 26);
    }

    int numDecodings(string s) {
        unordered_map<char, char> dict = {{'0', '#'}};
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 1; i <= 26; i++) {
            dict[i] = alphabets[i];
        }
        if (s.size() == 1) {
            char c = dict[s[0]];
            if (c != '#')
                return 1;
            else
                return 0;
        }
        int N = s.size();
        vector<int> dp(N + 1, 0);
        dp[N] = 1;
        if (s[N - 1] != '0') {
            dp[N - 1] = 1;
        }
        cout << "dp table ";
        copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        // cout<<"loop starting "<<endl;
        for (int i = N - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            int way1 = 0, way2 = 0;
            way1 = dp[i + 1];
            // cout<<"ans1= "<<ans1<<endl;
            //combine (i i+1) and if combination is valid then take i+2
            string comb = s.substr(i, 2);
            if (valid(comb)) {
                way2 = dp[i + 2];
            }
            dp[i] = way1 + way2;
            cout << "dp table after iteration= ";
            copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
        return dp[0];
    }
};