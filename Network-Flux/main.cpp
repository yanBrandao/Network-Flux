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

#define source 0
#define target 999999

void addProductVector(vector<pair<int, int> > *pv, int product, int weight){
    int verify = 0;
    for (int i = 0; i < pv->size(); i++) {
        if (product == pv->at(i).first) {
            pv->at(i).second += weight;
            verify = 1;
        }
    }
    if (!verify) {
        pv->push_back(*new pair<int, int>(product, weight));
    }
}



/*Returns true if there is a path from source 's' to sink 't' in
graph g. Also fills vector path to store the path */
bool breathSearch(Graph g, int begin, int end, vector<pair<int,int> > *path){
    bool rtn = false;
    vector<pair<bool, int> > *visited = new vector<pair<bool,int> >();
    for (int it = 0; it < g.nodes.size(); it++){
        visited->push_back(*new pair<bool, int> (false, g.nodes.at(it).value));
    }
    
    queue<int> q;
    q.push(begin);
    for (int i = 0; i < visited->size(); i++) {
        if (visited->at(i).second == begin) {
            visited->at(i).first = true;
            path->push_back(*new pair<int, int>(0, visited->at(i).second));
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it = g.nodes.begin(); it != g.nodes.end(); it++) {
            if (it->value == u) {
                for (int jt = 0; jt < it->neighbors.size(); jt++) {
                    for (int i = 0; i < visited->size(); i++) {
                        if (visited->at(i).second == it->neighbors.at(jt)->value) {
                            if (visited->at(i).first == false && (it->neighbors.at(jt)->weight > 0)) {
                                q.push(it->neighbors.at(jt)->value);
                                visited->at(i).first = true;
                                path->push_back(*new pair<int, int>(u, it->neighbors.at(jt)->value));
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < visited->size(); i++) {
        if (visited->at(i).second == end) {
            rtn = visited->at(i).first;
        }
    }
    return rtn;
}

/*Returns max_flow from Graph g, from source 's' to target 't'
 doing bfs to find the path while there's a edge more then 0. */
int fordFulkerson(Graph *g, int s, int t, float pLimit){
    int max_flow = 0;
    vector<pair<int, int> > *path = new vector<pair<int, int> >();
    
    for(auto it = g->nodes.begin(); it != g->nodes.end(); it ++){
        if (it->value == 0) {
            for (int i = 0; i < it->neighbors.size(); i++) {
                cout << it->value << "[ " << it->neighbors.at(i)->weight << " * " << pLimit << " ] = " << ceil(it->neighbors.at(i)->weight * pLimit) << endl;
                it->neighbors.at(i)->weight = ceil(it->neighbors.at(i)->weight * pLimit);
            }
        }
        
    }
    
    while(breathSearch((*g), source, target, path)){
        int path_flow = INT32_MAX;
        
        for (int i = 1; i < path->size(); i++) {
            for (auto it = g->nodes.begin(); it != g->nodes.end() ; it++) {
                if (path->at(i).first == it->value) {
                    for (int j = 0; j < it->neighbors.size(); j++){
                        if (path->at(i).second == it->neighbors.at(j)->value) {
                            path_flow = min(path_flow, it->neighbors.at(j)->weight);
                        }
                    }
                }
            }
        }
        
        for (int i = 1; i < path->size(); i++) {
            for (auto it = g->nodes.begin(); it != g->nodes.end() ; it++) {
                if (path->at(i).first == it->value) {
                    for (int j = 0; j < it->neighbors.size(); j++){
                        if (path->at(i).second == it->neighbors.at(j)->value) {
                            it->neighbors.at(j)->weight -= path_flow;
                        }
                    }
                }
            }
        }
        
        /*for (int i = 0; i < path->size(); i++) {
            cout << "[" << path->at(i).first << ", " << path->at(i).second  << "]";
        }
        cout << endl;*/
        max_flow += path_flow;
        path = new vector<pair<int, int> >();
    }
    return max_flow;
}

int main(int argc, const char * argv[]) {
    
    string pathFile = argv[1];
    //string pathFile = "/Users/yanbrandao/Developer/Network-Flux/Network-Flux/files/less_input.txt";
    vector<pair<int, string> > *clientTranslate = new vector<pair<int, string> >();
    vector<pair<pair<int,int>, string> > *clientVotes = new vector<pair<pair<int,int>, string> >();
    
    Graph g = *new Graph();
    ReadFile rf = *new ReadFile();
    
    g = rf.read_file(pathFile, clientTranslate, clientVotes);
    
    /*----------Adding vertex sourcing----------*/
    for (auto it = g.nodes.begin(); it != g.nodes.end(); it++) {
        int increment = 0;
        if (it->value == 0) {
            continue;
        }
        for (auto jt = clientVotes->begin(); jt != clientVotes->end(); jt++) {
            if (jt->first.first == it->value) {
                increment += stoi(jt->second);
            }
        }
        g.add(source, increment, it->value);
    }
    /*-----------------------------------------*/
    
    
    /*----------Adding vertex target----------*/
    vector<pair<int, int> > *productVector = new vector<pair<int, int> >();
    for (int k = 0; k < clientVotes->size(); k++) {
        addProductVector(productVector, clientVotes->at(k).first.second, stoi(clientVotes->at(k).second));
    }
    for (int i = 0; i < productVector->size(); i++) {
        g.add(productVector->at(i).first, productVector->at(i).second, target);
    }
    g.add(target, 0, source);
    /*----------------------------------------*/
    
    //g.show();
    
    
    cout << fordFulkerson(&g, source, target, atoi(argv[2])) << endl;
    
    g.show();

    
    return 0;
}
