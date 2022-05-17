//
// Created by neha2 on 05-05-2022.
//
/**
 * Good Question to revise.
 * I didnt know my linked list was weak as well.
 */

#include "createList.h"
#include <bits/stdc++.h>

using namespace std;
class Solution {
    int N;
public:
    ListNode *getKNode(ListNode *cur, int k) {
        ListNode *result = cur;
        int count = 1;
        while (count != k && cur->next) {
            cur = cur->next;
            count++;
        }
//        if (count != k) {
//            return result;
//        }
        result = cur;
        return result;
    }

    ListNode *reverseList(ListNode *begin, ListNode *end) {
        //prev--> cur--> next
        //prev <--cur <-- next
        ListNode *next = begin->next;
        ListNode *cur = begin;
        ListNode *prev = nullptr;

        while (cur != end) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
        }
        cur->next = prev;
        return cur;
    }

    void solveK(ListNode *kBegin, ListNode *prev, ListNode *&head, int k, int N) {
        cout << "k =" << k;
        cout << " prev=" << ((prev != nullptr) ? to_string(prev->val) : "prev null");
        int left = N;
        cout<<" left length="<<left<<endl;
        bool rFlag = !(k & 1);
        if (left >= k) {
            //usual case, take k lenth list and reverse them based on k and go ahead
        } else {
            //k is > left then check left is even or not
            rFlag = !(N & 1);
        }
        cout<<"rflag ="<<rFlag<<endl;
        if (kBegin == nullptr)
            return;
        cout << "begin of sublist =" << kBegin->val << " end of list =";
        ListNode *kEnd = getKNode(kBegin, k);
        cout << kEnd->val << endl;
        if (kBegin == kEnd && prev) {
            prev->next = kBegin;
            return;
        }

        ListNode *next = kEnd->next;
        cout << "next =" << ((next != nullptr) ? to_string(next->val) : "next null") << endl;
        ListNode *head_reverse_list;
        if (rFlag) {
            head_reverse_list = reverseList(kBegin, kEnd);
        } else {
            head_reverse_list = kBegin;
        }

        if (prev) {
            prev->next = head_reverse_list;
        }
        cout << "joining prev to this list(either reversed or not)" << endl;
        cout << "reversed linked list head=" << head_reverse_list->val << endl;
        cout << "chanign poiters for  next call::";
        if (rFlag)
            prev = kBegin; //kbegin begins end of list.
        else
            prev = kEnd;
        kBegin = next;
        cout << "prev=" << ((prev != nullptr) ? to_string(prev->val) : "null prev");
        cout << " kbegin=" << ((kBegin != nullptr) ? to_string(kBegin->val) : "next kbegin null") << endl;
        solveK(kBegin, prev, head, k + 1, N-k);

        head = head_reverse_list;
    }

    int getLength(ListNode *head) {
        int n = 0;
        while (head) {
            n+=1;
            head = head->next;
        }
        return n;
    }

    ListNode *reverseEvenLengthGroups(ListNode *head) {
        N = getLength(head);
        cout<<"length of list ="<<N<<endl;
        solveK(head, nullptr, head, 1, N);
        return head;
    }
};

int main() {
    vector<int> v = {1,1,0, 6};
    ListNode *l = createList(v);
    printList(l);
    Solution s;
//    l = s.swapPairs(l);
//    printList(l);
//    l = s.swapNodes(l, 7);
//    printList(l);
    l = s.reverseEvenLengthGroups(l);
    printList(l);
}