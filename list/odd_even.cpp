//
// Created by neha2 on 07-03-2022.
//
#include <bits/stdc++.h>
#include "createList.h"

using namespace std;

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            return head;
        }
        typedef ListNode *node;
        node head2 = head->next;
        node pt1 = head;
        node pt2 = head2;
        while (pt2->next!= nullptr) {
            if(pt2->next->next== nullptr)
                break;
            pt1->next = pt1->next->next;

            pt2->next = pt2->next->next;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        if (pt2->next != nullptr) {
            pt1->next = pt2->next;
            pt2->next= nullptr;
            pt1 = pt1->next;
        }
        // cout<<pt1->val<<endl;
        // cout<<head2->val<<endl;
        // cout<<pt1->next<<endl;
        pt1->next = head2;
//        head->next= nullptr;
        return head;
    }
};

int main() {
    vector<int> v({1, 2});
    ListNode *head = createList(v);
    Solution s;
    printList(head);
    s.oddEvenList(head);
    printList(head);

}
