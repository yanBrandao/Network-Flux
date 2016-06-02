//
//  graph.hpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class node{
public:
    int value;
    vector<node*> neighbors;
};

class Graph{
    vector<node> nodes;
public:
    void init();
    void show();
    void add(int v, int weight, int adj);
};

#endif /* graph_hpp */
