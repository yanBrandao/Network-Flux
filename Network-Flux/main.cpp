//
//  main.cpp
//  Fluxo-de-Redes
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

using namespace std;

int main(int argc, const char * argv[]) {
    
    Graph g = *new Graph();
    
    g.add(13, 2, 5);
    g.add(14, 2, 5);
    
    return 0;
}
