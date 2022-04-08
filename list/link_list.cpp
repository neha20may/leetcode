#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * for addition from left, push them in stack and then add.
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *current = nullptr;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int a = l1->val;
            int b = l2->val;
            int c = a + b + carry;
            //get the first digit
            int n_digits = (int) log10(c);
            if (n_digits != 0)
                carry = c / pow(10, n_digits);
            else
                carry = 0;
            if (head == nullptr) {
                head = new ListNode(c % 10, nullptr);
                current = head;
            } else {
                current->next = new ListNode(c % 10, nullptr);
                current = current->next;
            }
            l1 = l1->next;
            l2 = l2->next;

        }
        while (l1 != nullptr) {
            int a = l1->val;
            int sum = a + carry;
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
            current->next = new ListNode(sum % 10, nullptr);
            current = current->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int a = l1->val;
            int sum = a + carry;
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
            current->next = new ListNode(sum % 10, nullptr);
            current = current->next;
            l2 = l2->next;
        }
        if(carry!=0)
            current->next = new ListNode(1, nullptr);
        return head;

    }
};

void print_list(ListNode *pNode);

pair<int *, int *> test_Pointer() {
    int *a = new int(10);
    int *b = new int(20);
    return make_pair(a, b);
}

pair<ListNode *, ListNode *> make_list(vector<int> a, vector<int> b) {
    ListNode *l1 = nullptr, *l2 = nullptr, *current = nullptr;
    for (auto x: a) {
        if (l1 == nullptr) {
            l1 = new ListNode(x, nullptr);
            current = l1;
        } else {
            current->next = new ListNode(x, nullptr);
            current = current->next;
        }

    }
    current = nullptr;
    for (auto x: b) {
        if (l2 == nullptr) {
            l2 = new ListNode(x, nullptr);
            current = l2;
        } else {
            current->next = new ListNode(x, nullptr);
            current = current->next;
        }

    }
    //Note: I forgot to return, there is nothing magical happenign here
    return make_pair(l1, l2);

}

int main() {
    pair<int *, int *> p = test_Pointer();
    cout << *p.first << endl;
    cout << *p.second << endl;
    vector<int> a = {9, 9, 5, 9};
    vector<int> b = {5, 6, 4};
    pair<ListNode *, ListNode *> lists = make_list(a, b);
    print_list(lists.first);
    print_list(lists.second);
    Solution s;
    print_list(s.addTwoNumbers(lists.first, lists.second));
    return 0;
}

void print_list(ListNode *pNode) {
    while (pNode != nullptr) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

}




