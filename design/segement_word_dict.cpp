//
// Created by neha2 on 18-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    class node {
    public:
        char value;
        vector<node *> children;
        node *parent;
        bool isAp;

        node() {}

        node(char v, vector<node *> cd, node *p, bool ap) : value(v), children(cd), parent(p), isAp(ap) {}
    };

    class Trie {
        node *head;
    public:
        node *getHead() {
            return head;
        }

        Trie(vector<string> words) {
            head = new node();
            head->value = '#';
            head->isAp = false;
            vector<node *> children = vector<node *>(26, nullptr);
            string s = "abcdefghijklmnopqrstuvwxyz";
            for (char c: s) {
                node *child = new node(c, vector<node *>(26, nullptr), nullptr, false);
                children[c - 'a'] = child;
            }
            head->children = children;
            head->parent = nullptr;
            for (auto w: words) {
                insert(w);
            }
        }

        void insert(string w) {
            node *cur = head;
            for (char c: w) {
                node *child = cur->children[c - 'a'];
                if (child == nullptr) {
                    child = new node(c, vector<node *>(26, nullptr), nullptr, false);
                    cur->children[c - 'a'] = child;
                }
                child->parent = cur;
                cur = child;
            }
            cur->isAp = true;
        }

        node *search(string w) {
            node *cur = head;
            for (char c: w) {
                if (cur != nullptr) {
                    node *child = cur->children[c - 'a'];
                    cur = child;
                } else {
                    break;
                }

            }
            return cur;
        }
    };

public:
    vector<int> mem;

    bool solve(string s, int index, Trie &trie) {
        if (index >= s.size()) {
            return true;
        }
        if (mem[index] != -1)
            return mem[index];
        bool ans = false;
        for (int i = index; i <= s.size(); i++) {
            int npos = i - index;
            string ss = s.substr(index, npos);
//            cout<<"checong substring "<<ss<<endl;
            node *cur = trie.search(ss);
            if (cur == nullptr || !cur->isAp) {
                continue;
            }
            bool a = solve(s, i, trie);
            ans = ans || a;
            if (ans == true) {
                mem[index] = 1;
                return mem[index];
            }
        }
        mem[index] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        Trie trie(wordDict);
        mem.resize(s.size() + 1, -1);
        bool ans = solve(s, 0, trie);
        return ans;

    }
};

int main() {
    Solution sl;
    //"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
    //["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
//    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
//    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> dict = {"leet", "code"};
    string s = "leetscode";
    cout << "word can be segmented ? = " << sl.wordBreak(s, dict);
}
