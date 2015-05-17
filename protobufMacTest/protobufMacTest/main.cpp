//
//  main.cpp
//  protobufMacTest
//
//  Created by 郑光龙 on 15/5/17.
//  Copyright (c) 2015年 郑光龙. All rights reserved.
//

#include <iostream>
#include "HelloWorld.pb.h"
#include <fstream>
void writer();
void reader();
std::string pStr;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    writer();
    reader();
    return 0;
}

void writer()
{
    lm::HelloWorld msg1;
    msg1.set_id(10);
    msg1.set_str("hello protobuf");
    msg1.set_opt(4);
    
    
    //    std::fstream output("./log", std::ios::out | std::ios::trunc | std::ios::binary);
    
    if (!msg1.SerializeToString(&pStr)) {
        std::cerr << "Faild to write msg" << std::endl;
        return ;
    }
    return ;
}

void reader()
{
    lm::HelloWorld msg2;
    
    //    std::fstream input("./log", std::ios::in | std::ios::binary);
    
    if (!msg2.ParseFromString( pStr )) {
        std::cerr << "Faild to parse msg" << std::endl;
        return ;
    }
    
    std::cout << msg2.id() << std::endl;
    std::cout << msg2.str() << std::endl;
}
