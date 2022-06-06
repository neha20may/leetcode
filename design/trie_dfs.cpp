//
// Created by neha2 on 01-04-2022.
//
/**
 * What a question! seriously!
 */
#include <bits/stdc++.h>

using namespace std;

class subordinates {
    class Node{
    public:
        char value;
        vector<Node*> children;
        Node * parent;
        bool isAp;
        Node(){}
        Node(char v, vector<Node*> cd, Node *p, bool isAp):value(v), children(cd), parent(p), isAp(isAp){}

    };
    class Trie{
        Node * head;
    public:
        Node * getHead(){
            return head;
        }
        Trie(vector<string> &words){
            head=new Node();
            head->value='#';
            head->isAp=false;
            vector<Node*> children=vector<Node*>(26, nullptr);
            string s= "abcdefghijklmnopqrstuvwxyz";
            for(char c : s){
                Node * child= new Node(c, vector<Node*>(26, nullptr), nullptr, false);
                children[c-'a']=child;
            }
            head->children=children;
            head->parent=nullptr;
            for(auto word:words){
                insert(word);
            }
        }

        void insert(string word){
            Node * cur=head;
            for(char c: word){
                Node * child=cur->children[c-'a'];
                if(child==nullptr){
                    child=new Node(c, vector<Node*>(26, nullptr), nullptr, false);
                    cur->children[c-'a']=child;
                }
                child->parent=cur;
                cur=child;
            }
            cur->isAp=true;
        }
    };

public:
    vector<vector<char>> board;
    vector<vector<bool>> visited;

    void dfs(int i, int j, string &op, Node * cur, vector<string> &ans){
        if(cur==nullptr){
            ans.push_back(op);
            return;
        }

        int m=board.size();
        int n=board[0].size();
        char c=board[i][j];

        if(cur->value==c){
            op.push_back(c);
            visited[i][j]=true;
            for(int k=-1; k<2;k++){
                int dx=i+k, dy=j+k;
                if(dx>=0 and dx<m and !visited[dx][j])
                {
                    Node * next=cur->children[board[dx][j]-'a'];
                    if(next!=nullptr)
                        dfs(dx,j,op,next, ans);
                }
                if(dy>=0 and dy<n and !visited[i][dy])
                {
                    Node * next=cur->children[board[i][dy]-'a'];
                    if(next!=nullptr)
                        dfs(i,dy,op,next, ans);
                }
            }
        }

        if(cur->isAp==true)
        {
            ans.push_back(op);
            cur->isAp=false; //this one line if now written gives TLE error
        }
        visited[i][j]=false;
        op.pop_back();

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t(words);
        int m=board.size();
        int n=board[0].size();
        this->board=board;
        visited=vector<vector<bool>> (m, vector<bool>(n, false));
        Node * head= t.getHead();
        set<string> fans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<string> ans;
                string op="";
                Node * next=head->children[board[i][j]-'a'];
                if(next != nullptr)
                {
                    dfs(i,j,op, next, ans);
                    fans.insert(ans.begin(), ans.end());
                    ans.clear();
                }
            }
        }
        return vector<string>(fans.begin(), fans.end());

    }
};

int main() {
    vector<vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"eat", "oath", "oat", "oa"};
    subordinates s;
    auto ans = s.findWords(board, words);
    for (string a: ans) {
        cout << " " << a;
    }
}