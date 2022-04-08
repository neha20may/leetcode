//
// Created by neha2 on 05-02-2022.
//
#include <bits/stdc++.h>
using namespace  std;
int main(){
    vector<int> x(10);
    int i=1;
    generate(x.begin(), x.end(), [&i]{return i++;});
    copy(x.begin(), x.end(), ostream_iterator<int>(cout," " ));
    cout<<endl;
}

