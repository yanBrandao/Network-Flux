//
//  read_file.hpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#ifndef read_file_hpp
#define read_file_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include "graph.hpp"

class ReadFile{
public:
    Graph read_file(string filePath, vector<pair<int, string>> *clientTranslate, vector<pair<pair<int,int>, string>> *clientVotes);
};


#endif /* read_file_hpp */
