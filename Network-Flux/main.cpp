//
//  main.cpp
//  Network-Flux
//
//  Created by Yan Brandão Diniz on 5/30/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <math.h>
#include <queue>
#include "graph.hpp"
#include "read_file.hpp"

using namespace std;

bool breathSearch(Graph g, int begin, int end, vector<int> *path){
    vector<bool> visited = *new vector<bool>();
    for (int it = 0; it < g.nodes.size(); it++)
        visited.push_back(false);
    
    queue<int> q;
    q.push(begin);
    visited.at(begin) = true;
    path->at(begin) = -1;
    
    while (!q.empty()) {
        int u = q.front();
        int uv = u;
        q.pop();
        cout << u << endl;
        for (int v = 0; v < g.nodes.size(); v++) {
            if (visited.at(v) == false && (g.getAdjWeight(uv, (v+10)) > 0)) {
                q.push(v);
                cout << "[ "<< u << " ]";
                path->at(v) = u;
                visited.at(v) = true;
            }
        }
        cout << endl;
    }
    return visited.at(end);
}

int main(int argc, const char * argv[]) {
    
    vector<int> *path = new vector<int>();
    Graph g = *new Graph();
    ReadFile rf = *new ReadFile();
    g = rf.read_file();
    
    g.show();
    for (int i ; i < g.nodes.size(); i++) {
        path->push_back(0);
    }
    cout << "Path size: " << path->size() << endl;
    cout << "Weight from 7 to 12: " << g.getAdjWeight(7, 12) << endl;
    cout << "BreathSearch: " << breathSearch(g, 0, 9, path) << endl;
    for (int i = 0; i < path->size(); i++) {
        cout << "[" << path->at(i) << "]";
    }
    cout << endl;
    return 0;
}
