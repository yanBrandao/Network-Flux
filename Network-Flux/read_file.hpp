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
    Graph read_file();
};


#endif /* read_file_hpp */
