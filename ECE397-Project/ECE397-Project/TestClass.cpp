//
//  TestClass.cpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#include "TestClass.hpp"

TestClass::TestClass(int i) {
    _i = i;
}
int TestClass::GetVal() {
    return _i;
}
void TestClass::SetVal(int i) {
    _i = i;
}
