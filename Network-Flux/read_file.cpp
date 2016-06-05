//
//  Data type: (Where only working products will be added to graph)
//
//
// # Full information about Amazon Share the Love products
// Total items: 548552
// Id:   0
// ASIN: 0771044445
// discontinued product
//
// Id:   1
// ASIN: 0827229534
// title: Patterns of Preaching: A Sermon Sampler
// group: Book
// salesrank: 396585
// similar: 5  0804215715  156101074X  0687023955  0687074231  082721619X
// categories: 2
// |Books[283155]|Subjects[1000]|Religion & Spirituality[22]|Christianity[12290]|Clergy[12360]|Preaching[12368]
// |Books[283155]|Subjects[1000]|Religion & Spirituality[22]|Christianity[12290]|Clergy[12360]|Sermons[12370]
// reviews: total: 2  downloaded: 2  avg rating: 5
// 2000-7-28  cutomer: A2JW67OY8U6HHK  rating: 5  votes:  10  helpful:   9
// 2003-12-14  cutomer: A2VE83MZF98ITY  rating: 5  votes:   6  helpful:   5
//
//  We will only read:
//      id
//      cutomer
//      votes
//
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
            }
            
            if (tokens.size() > 2) {
                
                if(tokens.at(1).find("cutomer") != string::npos){
                    pair<int, string> element = *new pair<int, string>(client_inc, tokens.at(2));
                    pair<pair<int, int>, string> votes = *new pair<pair<int, int>, string>(*new pair<int,int>(client_inc, id), tokens.at(6));
                    for (auto it = clientTranslate->begin(); it != clientTranslate->end(); it++) {
                        if (!tokens.at(2).compare(it->second)) {
                            client_id = it->first;
                            votes.first.second = client_id;
                            verify = 1;
                        }
                    }
                    if (verify == 0) {
                        client_id = client_inc;
                        votes.first.first = client_id;
                        clientTranslate->push_back(element);
                        clientVotes->push_back(votes);
                        client_inc--;
                    }
                    G.add(client_id, 1, id);
                    
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