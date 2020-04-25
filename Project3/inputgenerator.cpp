#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#define TIMERANGE 10
#define WEIGHTRANGE 10

using namespace std;

int main (int argc, const char * argv[]) {
	if(argc != 3){
		cout <<"Please input the correct format: ./main <numbers of inputs> <outputfile.txt>"<< endl;
	}
	srand(time(NULL));
	ofstream myfile;
	myfile.open(argv[2]);
	
	for(int i = 0; i<stoi(argv[1]); i++){
		int start = rand()%TIMERANGE + 1;
		while(start == TIMERANGE){
			start = rand()%TIMERANGE + 1;
		}
		int end = rand()%TIMERANGE + 1;
		while(end <= start){
			end = rand()%TIMERANGE + 1;
		}
		int weight = rand()%WEIGHTRANGE + 1;
		myfile <<start<<" "<<end<<" "<<weight<<"\n";
	}
	
  myfile.close();
  return 0;
}

