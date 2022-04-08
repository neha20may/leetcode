//
// Created by neha2 on 07-03-2022.
//

#ifndef LEETCODE_CREATELIST_H
#define LEETCODE_CREATELIST_H

#include <vector>
#include <iostream>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(std::vector<int> &v) {
    ListNode *head = nullptr, *current = nullptr;
    for (auto x: v) {
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

void printList(ListNode *pNode) {
    while (pNode != nullptr) {
        std::cout << pNode->val << " ";
        pNode = pNode->next;
    }
    std::cout << std::endl;

}

#endif //LEETCODE_CREATELIST_H
