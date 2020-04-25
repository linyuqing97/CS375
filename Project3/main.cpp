#include <iostream>
#include <vector>
#include <chrono>
#include "FileProcessor.hpp"
using namespace std;
using namespace chrono;

bool compare(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];
}

vector<vector<int> > sortInput(vector<int>startTimes,vector<int>endTimes,vector<int>profits){
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
    sort(sortedArray.begin(),sortedArray.end(),compare);// nlogn
    return sortedArray;
};

bool checkTimeOverlap(vector<int>v1, vector<int> v2){
    // if end time greater than start time return true;
    if(v1[1] > v2[0])return true;
    else return false;
}

void print(vector<int>res){
    for(auto a : res){
        cout<<a<<",";
    }
    cout<<endl;
}

int binarySearch(vector<vector<int> >& sortedArray,int startTime,int index){
    int left = 0;int right = index;
    while(left<= right){
        int mid = left+(right - left)/2;
        
        if(sortedArray[mid][1] <= startTime && (mid>= sortedArray.size() || sortedArray[mid+1][1] > startTime)){
            return mid;
        }
        else if(sortedArray[mid][1] > startTime){
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    return left;
}


int solution(vector<vector<int> >& sortedArray){
    vector<int>res(sortedArray.size(),0);
    int right = 1;
    
    while(right < res.size()){
        int bestBeforeOverlap = binarySearch(sortedArray,sortedArray[right][0],right);
        res[right] = max(res[right-1],sortedArray[right][2]+res[bestBeforeOverlap]);
        right++;
    }
    int result = res[res.size()-1];
  
    return result;
}

int main(int argc, const char * argv[]) {
    FileProcessor fileProcessor;
    fileProcessor.phraseInput(argv[1]);
    auto start = high_resolution_clock::now();
    vector<vector<int> >sortedArray = sortInput(fileProcessor.getStartTime(),fileProcessor.getEndTime(),fileProcessor.getProfits());
    int result = solution(sortedArray);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; 
    cout << "Reuslt is : "<<result<<endl;
    return 0;
}
