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
    Graph G;
    
    string line, buff;
    ifstream file;
    
    file.open("/Users/yanbrandao/Developer/Fluxo-de-Redes/Fluxo-de-Redes/files/amazon0302.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> tokens;
            while (ss >> buff) {
                tokens.push_back(buff);
            }
            for (int i = 0; i < tokens.size(); i++) {
                cout << tokens.at(i) << " ";
            }
            cout << endl;
        }
        file.close();
    }else{
        cout << "File not opened" << endl;
    }
    
    return G;
}