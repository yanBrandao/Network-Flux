//
//  read_file.cpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#include "read_file.hpp"

using namespace std;

Graph ReadFile::read_file(string filePath, vector<pair<int, string>> *clientTranslate, vector<pair<pair<int,int>, string>> *clientVotes){
    Graph G = *new Graph();
    
    string line, buff;
    ifstream file;
    int id = 0;
    int verify = 0;
    int client_id = -1;
    int client_inc = -1;
    
    file.open(filePath);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> tokens;
            while (ss >> buff) {
                tokens.push_back(buff);
            }
            if (tokens.size() > 1) {
                if (tokens.at(0).find("Id:") != string::npos) {
                    id = stoi(tokens.at(1));
                }
                cout << "id: " << id << endl;
            }
            
            if (tokens.size() > 2) {
                
                if(tokens.at(1).find("cutomer") != string::npos){
                    pair<int, string> element = *new pair<int, string>(client_inc, tokens.at(2));
                    pair<pair<int, int>, string> votes = *new pair<pair<int, int>, string>(*new pair<int,int>(id, client_inc), tokens.at(6));
                    for (auto it = clientTranslate->begin(); it != clientTranslate->end(); it++) {
                        
                        if (!tokens.at(2).compare(it->second)) {
                            client_id = it->first;
                            votes.first.second = client_id;
                            verify = 1;
                        }
                        
                    }
                    if (verify == 0) {
                        client_id = client_inc;
                        votes.first.second = client_id;
                        clientTranslate->push_back(element);
                        clientVotes->push_back(votes);
                        client_inc--;
                    }
                    G.add(id, 1, client_id);
                    
                    verify = 0;
                }
                
            }
        }
        file.close();
    }else{
        cout << "File not opened" << endl;
    }
    
    return G;
}