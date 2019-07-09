/* 
    COT4400.901 Project 2
    Peter Stilian, Emily Cardella, Sarah Shand, Johnathan Teav
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
vector<int> topOutput;
vector<int> bottomOutput;

void ToothRecursive(int x, int y, int minVal, vector<vector<int>> LT) {

	// add current value of LT[x][y] to return vetor

	if (LT[x + 1][y + 1] == -1 && LT[x + 1][y] == -1 && LT[x][y + 1] == -1) {
		return;
	}
	
	return 
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
    
    //use vectors to fill look-up table
    int minVal;
    vector<vector<int>> LT(m+1, vector<int>(n+1, -1));

	// Initialize lookup table to -1 amd values of top and bottom teeth
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            LT[i][j] = topTeeth.at(j) + bottomTeeth.at(i);
        }
    }

	int leftMolar = LT[1][1];
	int rightMolar = LT[n][m];
	if (leftMolar < rightMolar) {
		minVal = leftMolar;
	}
	else {
		minVal = rightMolar;
	}
	
	map<int,int> output = ToothRecursive(1, 1, minVal, LT);

    // need to find best minimum height aka optimal substructure

    // sort algorithm and re-arrange teeth

    // output new data to file "output.txt"


    return 0;
}
