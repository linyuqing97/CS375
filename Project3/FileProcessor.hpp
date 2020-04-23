//
//  FileProcessor.hpp
//  Project3
//
//  Created by Yuqing Lin on 4/14/20.
//  Copyright © 2020 Yuqing Lin. All rights reserved.
//

#ifndef FileProcessor_hpp
#define FileProcessor_hpp

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <vector>

class FileProcessor{
private:
    std::vector<int> startTime;
    std::vector<int> endTime;
    std::vector<int> profits;
public:
    std::vector<int> getStartTime(){return startTime;};
    std::vector<int> getEndTime(){return endTime;};
    std::vector<int>getProfits(){return profits;};
    void phraseInput(std::string);
};
#endif /* FileProcessor_hpp */
