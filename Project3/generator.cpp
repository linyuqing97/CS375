#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "FileProcessor.hpp"

using namespace std;

bool compareend(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];
}

bool comparestart(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0];
}

vector<vector<int> > sortInput(vector<int>startTimes,vector<int>endTimes,vector<int>profits, string order){
    vector<vector<int> >sortedArray;
    
    if(startTimes.size()!=endTimes.size()){
        cerr<<"Input error"<<endl;
    }
    
    for(int i = 0;i<startTimes.size();i++){
        vector<int>temp;
        temp.push_back(startTimes[i]);
        temp.push_back(endTimes[i]);
        temp.push_back(profits[i]);
        sortedArray.push_back(temp);
    }
	if(order == "start"){
		sort(sortedArray.begin(),sortedArray.end(),comparestart);// nlogn
	}else{
		sort(sortedArray.begin(),sortedArray.end(),compareend);
	}
    return sortedArray;
};

int main(int argc, const char * argv[]) {
	if(argc != 4){
		cout <<"Please input the correct format: ./main <input.txt> <outputfile.txt> start/end"<< endl;
		return 0;
	}
	string inputorder = argv[3];
	if(inputorder.compare("start") && inputorder.compare("end")){
		cout <<"argv[3] can only be start or end"<< endl;
		return 0;
	}
    FileProcessor fileProcessor;
    fileProcessor.phraseInput(argv[1]);
    vector<vector<int> >sortedArray = sortInput(fileProcessor.getStartTime(),fileProcessor.getEndTime(),fileProcessor.getProfits(),argv[3]);
	ofstream myfile;
	myfile.open(argv[2]);
	for(int i = 0; i<sortedArray.size(); i++){
		myfile <<sortedArray[i][0]<<" "<<sortedArray[i][1]<<" "<<sortedArray[i][2]<<"\n";
	}
	myfile.close();
    return 0;
}