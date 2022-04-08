//
// Created by neha2 on 01-04-2022.
//
#include <bits/stdc++.h>
using namespace  std;
int main(){
    //concept 1
    vector<int> * v= new vector<int>(2,10);
    cout<<v[0][0]<<" " <<v[0][1]<<" "<<endl;
//    cout<<v[1][0]<<endl;  //segmentation
    vector<int> * v2=new vector<int>[2];//used in graph
    v2[0]= vector<int>(1,0);
    v2[1]= vector<int>(2,3);
    cout<<v2[0][0]<<" "<<v2[1][0]<<" "<<v2[1][1]<<endl;
    /**
     * Do you see both v and v2 has same left side vector<nt>* , one is normal vector and another is array!
     * Thats why I got confused!
     */
     //concept 2
     int a=5;
     int* b=new int(5);
     cout<<a<<" "<<*b<<endl; //cout<<b ==> its address
     int * c=&a;
     cout<<*c<<endl;

}
