//
// Created by neha2 on 15-04-2022.
//

#ifndef LEETCODE_READER_H
#define LEETCODE_READER_H
#include <bits/stdc++.h>

using namespace std;
vector<int> read_input() {
    ifstream fin;
    fin.open("C:/Users/neha2/CLionProjects/leetcode/array/buy_sell/sample.txt");
    string line;
    while (fin) {
        getline(fin, line);
    }
    line.erase(0, 1);
    line.erase(line.size() - 1);
    stringstream ss(line);
    string ele;
    vector<int> result;
    while (getline(ss, ele, ',')) {
        result.push_back(stoi(ele));
    }
    return result;
}
#endif //LEETCODE_READER_H
