//
//  FileProcessor.cpp
//  Project3
//
//  Created by Yuqing Lin on 4/14/20.
//  Copyright © 2020 Yuqing Lin. All rights reserved.
//

#include "FileProcessor.hpp"
#include <iostream>
using namespace std;


void FileProcessor::phraseInput(string inputFileName){
    ifstream infile(inputFileName);
    string line;
    stringstream s(line);
    int start;int end;int value;
    while(getline(infile,line)){
        stringstream ss(line);
        ss>>start >> end >> value;
        startTime.push_back(start);
        endTime.push_back(end);
        this->profits.push_back(value);
    }
    infile.close();
}
