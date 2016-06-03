//
//  read_file.cpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#include "read_file.hpp"

using namespace std;

Graph ReadFile::read_file(){
    Graph G = *new Graph();
    
    string line, buff;
    ifstream file;
    
    file.open("/Users/yanbrandao/Developer/Network-Flux/Network-Flux/files/graph-products.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> tokens;
            while (ss >> buff) {
                tokens.push_back(buff);
            }
            G.add(stoi(tokens.at(0)), stoi(tokens.at(1)), stoi(tokens.at(2)));
        }
        file.close();
    }else{
        cout << "File not opened" << endl;
    }
    
    return G;
}