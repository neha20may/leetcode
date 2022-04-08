//
// Created by neha2 on 08-02-2022.
//

#include <bits/stdc++.h>

using namespace std;
//
// Created by neha2 on 08-02-2022.
//
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
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void addToResult(ListNode * &head, ListNode *&current, int sum, int &carry) {
        cout << "check 2 ";
        if (sum > 9) carry = 1;
        else carry = 0;
        auto node = new ListNode(sum % 10, nullptr);
        if (head == nullptr) {
            head = node;
            current = head;
        } else {
            current->next = node;
            current = current->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *head = nullptr, *current = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            cout << "check1 ";
            addToResult(head, current, sum, carry);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr) {
            while (l2 != nullptr) {
                addToResult(head, current, l2->val, carry);
                l2 = l2->next;
            }

        } else if (l2 == nullptr) {
            while (l1 != nullptr) {
                addToResult(head, current, l1->val, carry);
                l1 = l1->next;
            }
        }
        if (carry == 1)
            addToResult(head, current, 1, carry);
        return head;

    }
};

ListNode *make_list(vector<int> vector1);

int main() {
//    [2,4,3]
    ListNode *l1 = make_list(vector<int>{2, 4, 3});
    ListNode *l2= make_list(vector<int>{5,6,4});
    Solution s;
    auto r=s.addTwoNumbers(l1,l2);
    while(r!= nullptr){
        cout<<r->val<<" ";
        r=r->next;
    }
//    [5,6,4]
}

ListNode *make_list(vector<int> vector1) {
    ListNode *head = nullptr, *current = nullptr;
    for (auto x: vector1) {
        auto n = new ListNode(x, nullptr);
        if (head == nullptr) {
            head = n;
            current = head;
        } else {
            current->next = n;
            current = current->next;
        }
    }
    return head;
}

