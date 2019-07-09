#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


void ToothRecursive(int x, int y, int LT[][], int minVal) {

	// add current value of LT[x][y] to return vetor

	if (LT[x + 1][y + 1] == -1 && LT[x + 1][y] == -1 && LT[x][y + 1] == -1) {
		return;
	}
	
	
	
}




vector<int> ToothWrapper(int n,int m) {
	int minVal;
	int LookupTable[n + 1][m + 1];
	// Initialize lookup table to -1 amd values of top and bottom teeth

	leftMolar = LookupTable[1][1];
	rightMolar = LookupTable[n][m];
	if (leftMolar < rightMolar) {
		minVal = leftMolar;
	}
	else {
		minVal = rightMolar;
	}
	
	return ToothRecursive(1, 1, LookupTable, minVal);
}


int main(){
    int n,m,temp;

    ifstream file("input.txt");
    file >> n >> m;
    vector<int> topTeeth;
    vector<int> bottomTeeth;

    // Reads data from input file "input.txt" and initializes it to the arrays topTeeth and bottomTeeth
    if(file.is_open()){
        for(int i = 0 ; i < n ; i++){
            file >> temp;
            topTeeth.push_back(temp);
            cout << topTeeth.at(i);
        }
        cout << endl;
        for(int i = 0 ; i < m ; i++){
            file >> temp;
            bottomTeeth.push_back(temp);
            cout << bottomTeeth.at(i);
        }
        file.close();
    }

    // need to find best minimum height aka optimal substructure

    // sort algorithm and re-arrange teeth

    // output new data to file "output.txt"


    return 0;
}
