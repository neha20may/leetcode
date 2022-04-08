//
// Created by neha2 on 01-03-2022.
//
#include <bits/stdc++.h>
using namespace  std;
class Solution {
    typedef vector<int> meeting;
public:
    struct meeting_comp{
        bool operator()(const meeting &a, const meeting &b){
            return a[1]>b[1];
        };
    };
    void update(priority_queue<meeting, vector<meeting>, meeting_comp> &active_meetings, meeting &m){
        if(active_meetings.empty())
        {
            cout<<"updated active meeting size"<<active_meetings.size()<<endl;
            return;
        }
        while(!active_meetings.empty()){
            meeting am=active_meetings.top();
            if(am[1]<=m[0])
                active_meetings.pop();
            else
                break;
        }
        cout<<"updated active meeting size"<<active_meetings.size()<<endl;

    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
            return 1;
        sort(intervals.begin(), intervals.end(),
             [](const meeting &i, const meeting &j){return i[0]<j[0];});

        priority_queue<meeting, vector<meeting>, meeting_comp> active_meetings;
        int rooms=0;
        for(auto m: intervals){
            cout<<"meeting ["<<m[0] <<" ,"<<m[1]<<"]"<<endl;
            update(active_meetings, m);
            active_meetings.push(m);
            rooms=max(rooms, static_cast<int>(active_meetings.size()));
        }
        return rooms;
    }
};
int main(){
    vector<vector<int>> meetings={
            {13,15},
            {1,13}
    };
    Solution s;
    cout<<s.minMeetingRooms(meetings)<<endl;
}