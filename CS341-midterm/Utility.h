
//
//  Utility.h
//  CS431-assignment02
//
//  Created by Jason Lu on 9/23/13.
//  Copyright (c) 2013 Lu Jason. All rights reserved.
//

#ifndef __CS431_assignment02__Utility__
#define __CS431_assignment02__Utility__

#include <iostream>

using namespace std;

class Utility {

private:
    static const string QUIT_STR;
    
public:
    static bool readAsBool(string promt);
    static long readAsLong(string promt);
    static int readAsInt(string promt);
    static double readAsDouble(string promt);
    static float readAsFloat(string promt) ;
    static string readAsString(string promt);
    int randInt(int limit, int notThisOne);
    int randInt(int limit);
};
#endif /* defined(__CS431_assignment02__Utility__) */
