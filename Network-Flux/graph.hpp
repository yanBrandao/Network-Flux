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
    int weight;
    vector<node*> neighbors;
};

class Graph{
public:
    vector<node> nodes;
    void init();
    void show();
    void add(int v, int weight, int adj);
    int getAdjWeight(int v, int adj);
};

#endif /* graph_hpp */
