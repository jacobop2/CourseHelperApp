//
//  TestClass.hpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#ifndef TestClass_hpp
#define TestClass_hpp


#include <stdio.h>


class TestClass {
public:
    TestClass(int i);
    int GetVal();
    void SetVal(int i);
private:
    int _i;
};

#endif /* TestClass_hpp */
