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
#include "graph.hpp"
#include "read_file.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Graph g = *new Graph();
    ReadFile rf = *new ReadFile();
    rf.read_file().show();
    
    return 0;
}
