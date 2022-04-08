//
// Created by neha2 on 08-03-2022.
//
#include <bits/stdc++.h>
using  namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto t: tasks){
            freq[t-'A']++;
        }
        sort(freq.begin(), freq.end());
        int fm=freq[25];
        int & cool_time=n;
        int slots_left=fm-1;
        int idle_time=slots_left*cool_time;
        for(int i=freq.size()-2; i>=0 && idle_time>0; i--){
            int next_max_freq=freq[i];
            int slots_that_can_be_filled=min(slots_that_can_be_filled,
                                             next_max_freq);
//            slots_left=slots_left-slots_that_can_be_filled;
            idle_time=idle_time-slots_that_can_be_filled;

        }
        idle_time=max(0, idle_time);
        return idle_time+tasks.size();
    }
};
int main(){
    vector<char> tasks={'A','A','A','B','B','B','C','D','E','F'};
    int n=2;
    Solution s;
    s.leastInterval(tasks, n);
}

