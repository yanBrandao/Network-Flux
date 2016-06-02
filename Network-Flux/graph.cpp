//
//  graph.cpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#include "graph.hpp"

void Graph::init(){
    vector<node> newNodes = *new vector<node>();
    nodes = newNodes;
}

void Graph::add(int v, int weight, int adj){
    node nodeN = *new node();
    node nodeAdj = *new node();
    nodeAdj.value = adj;
    nodeN.value = v;
    nodeN.neighbors = *new vector<node*>();
    nodeN.neighbors.push_back(&nodeAdj);
    
    nodes.push_back(nodeN);
}

void Graph::show(){
    //iterator<<#class _Category#>, <#class _Tp#>>
}