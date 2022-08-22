//
// Created by Neha on 20/08/22.
//


#include <vector>
#include <iostream>
using namespace  std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

    }
};
int main(){
    vector<int> v={1,2,3, 4};
    cout<<"hi I am here after testing"<<endl;
    for (auto x: v){
        cout<<x<<endl;
    }
    int a[]={12,3};
    for(auto x:a){
        cout<<x<<" ";
    }
    string baby="abc";
    string baby2(baby);
    string baby3= baby2;
    string baby4="abc";
    cout<<endl;
    if(baby4==baby)
        cout<<"baby equal"<<endl;
    string* baby5= new string("abc");
    if(*baby5 == baby){
        cout<<"eq"<<endl;
    }
}
