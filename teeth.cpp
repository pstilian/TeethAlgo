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
#include <algorithm>
#include <map>

using namespace std;
vector<int> topOutput;
vector<int> bottomOutput;

void ToothRecursive(int x, int y, int minVal, vector<vector<int>> LT) {

	int rightMove = LT[x + 1][y];
	int downMove = LT[x][y + 1];
	int diagnalMove = LT[x + 1][y + 1];

	// add current value of LT[x][y] to return vetor
	topOutput.push_back(LT[x][1]);
	bottomOutput.push_back(LT[1][y]);

	// if teeth aligned and at end of array 
	if (diagnalMove == -1 && rightMove == -1 && downMove == -1) {
		return;
	}

	// if no need to grow teeth progress normally
	else if (diagnalMove <= minVal && diagnalMove != -1) {
		ToothRecursive(x + 1, y + 1, minVal, LT);
	}

	// if there are no teeth left on top row grow new top tooth
	else if (rightMove == -1 && downMove != -1) {
		ToothRecursive(x, y + 1, minVal, LT);
	}

	// if there are no teeth left on bottom grow new bottom tooth
	else if (downMove == -1 && rightMove != -1) {
		ToothRecursive(x + 1, y, minVal, LT);
	}

	else {
			//if right value is the smallest
			if(rightMove < downMove && rightMove < diagnalMove){
				//if a new min is required
				if(minVal < rightMove){
					minVal = rightMove;
				}
				ToothRecursive(x + 1, y, minVal, LT);
			}
			//if down value is the smallest
			else if(downMove < rightMove && downMove < diagnalMove){
				//if a new min is required
				if(minVal < downMove){
					minVal = downMove;
				}
				ToothRecursive(x, y + 1, minVal, LT);
			}
			//if diagnal value is smallest, or the values are equal
			else if(diagnalMove <= rightMove && diagnalMove <= downMove){
				//if a new min is required
				if(minVal < diagnalMove){
					minVal = diagnalMove;
				}
				ToothRecursive(x + 1, y + 1, minVal, LT);
			}

		}

		// find smallest value of rightMove, downMove, diagnalMove 
		// if smallest of the 3 values is greater than minVal make that new minVal
		// Call recursive function that goes that direction
	}
return // something?
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
    
    // Initialize lookup table to -1 amd values of top and bottom teeth
    int minVal;
    vector<vector<int>> LT(m+1, vector<int>(n+1, -1));

	// populate lookup table with sum of teeth sizes
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            LT[i][j] = topTeeth.at(j) + bottomTeeth.at(i);
        }
    }

	// Find minVal base case
	int leftMolar = LT[1][1];
	int rightMolar = LT[n][m];
	if (leftMolar < rightMolar) {
		minVal = leftMolar;
	}
	else {
		minVal = rightMolar;
	}
	
	// Call recursive function
	map<int,int> output = ToothRecursive(1, 1, minVal, LT);


    // output new data to file "output.txt"


    return 0;
}
