//
// Created by neha2 on 12-03-2022.
//
#include <bits/stdc++.h>
using namespace  std;
#include "../list/createList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct comp{
        bool operator()(const  ListNode* a, const  ListNode* b){
            return (a->val>b->val);
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        if(lists.size()==1)
            return lists[0];
        int k=lists.size();
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        //fill heap
        int i=0;
        while(pq.size()<k){
            ListNode * ele=lists[i];
            pq.push(ele);
            i++;
        }
        cout<<"::pq size "<<pq.size()<<endl;
        vector<ListNode*> ans;
        while(pq.size()!=0){
            ListNode * t=pq.top();
            cout<<"top node val "<<t->val<<endl;
            ans.push_back(t);
            pq.pop();
            if(t->next!=nullptr)
                pq.push(t->next);
            cout<<"pq size "<<pq.size()<<endl;
        }
        for(int j=1;j<ans.size()-1;j++){
            ans[j-1]->next=ans[j];
        }
        ans[ans.size()-1]=nullptr;
        return ans[0];

    }
};
int main(){
    //[[1,4,5],[1,3,4],[2,6]]
    vector<int> a={1,4,5};
    vector<int> b={1,3,4};
    vector<int> c={2,6};
    vector<ListNode*> test;
    test.push_back(createList(a));
    test.push_back(createList(b));
    test.push_back(createList(c));
    Solution s;
    ListNode* h=s.mergeKLists(test);
    printList(h);
}