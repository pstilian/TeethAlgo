/* 
    COT4400.901 Project 2
    Peter Stilian, Emily Cardella, Sarah Shand, Johnathan Teav
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int> topTeeth;
vector<int> bottomTeeth;

void ToothRecursive(int x, int y, vector<vector<int>> &LT, int &min, vector<int> &topOut, vector<int> &bottomOut) {

	int rightMove = LT[x + 1][y];
	int downMove = LT[x][y + 1];
	int diagnalMove = LT[x + 1][y + 1];

	// add current value of corresponding teeth to return vetor
	topOut.push_back(topTeeth[y]);
	bottomOut.push_back(bottomTeeth[x]);
	cout << "ADDING THE FOLLOWING VALS : " << bottomTeeth[x] << "   " << topTeeth[y] << endl;

	cout << "minVal:     " << min << endl;
	cout << "Right Move: " << rightMove << endl;
	cout << "Diag Move:  " << diagnalMove << endl;
	cout << "Down Move:  " << downMove << endl;


	// if teeth aligned and at end of array 
	if (diagnalMove == -1 && rightMove == -1 && downMove == -1) {
		cout << "Teeth are aligned." << endl;
		return;
	}

	// if no need to grow teeth progress normally
	else if (diagnalMove <= min && diagnalMove != -1) {
		cout << "Making diagnal move " << endl;

		ToothRecursive(x + 1, y + 1, LT, min, topOut, bottomOut);
	}

	// if there are no teeth left on top row grow new top tooth
	else if (rightMove == -1 && downMove != -1) {
		cout << "Growing new top teeth." << endl;

		if (min < downMove) {
			min = downMove;
		}
		ToothRecursive(x, y + 1, LT, min, topOut, bottomOut);

	}

	// if there are no teeth left on bottom grow new bottom tooth
	else if (downMove == -1 && rightMove != -1) {
		cout << "Growing new bottom teeth." << endl;

		if (min < rightMove) {
			min = rightMove;
		}
		ToothRecursive(x + 1, y, LT, min, topOut, bottomOut);

	}

	/*	
	Find smallest value of rightMove, downMove, diagnalMove
	if smallest of the 3 values is greater than minVal make that new minVal
	and call recursive function that goes that direction
	*/
	else {
		//if right and down are both equal to the min
		if(rightMove == downMove){
			int tempMin1 = min;
			int tempMin2 = min;
			vector<int> tempTopOutput1;
			vector<int> tempBottomOutput1;
			vector<int> tempTopOutput2;
			vector<int> tempBottomOutput2;

			ToothRecursive(x + 1, y, LT, tempMin1, tempTopOutput1, tempBottomOutput1);
			ToothRecursive(x, y + 1, LT, tempMin2, tempTopOutput2, tempBottomOutput2);

			if(tempMin1 < tempMin2){
				min = tempMin1;
				topOut.insert(topOut.end(), tempTopOutput1.begin(), tempTopOutput1.end());
				bottomOut.insert(bottomOut.end(), tempBottomOutput1.begin(), tempBottomOutput1.end());
			}
			else{
				min = tempMin2;
				topOut.insert(topOut.end(), tempTopOutput2.begin(), tempTopOutput2.end());
				bottomOut.insert(bottomOut.end(), tempBottomOutput2.begin(), tempBottomOutput2.end());
			}
		}
		//if right value is the smallest
		else if(rightMove <= downMove && rightMove <= diagnalMove){
			//if a new min is required
			if(min < rightMove){
				min = rightMove;
			}

			cout << "Making Right Move" << endl;
			ToothRecursive(x + 1, y, LT, min, topOut, bottomOut);
		}
		//if down value is the smallest
		else if(downMove <= rightMove && downMove <= diagnalMove){
		//if a new min is required
			if(min < downMove){
				min = downMove;
			}

			cout << "Making Down Move" << endl;
			ToothRecursive(x, y + 1, LT, min, topOut, bottomOut);
		}
		//if diagnal value is smallest, or the values are equal
		else if(diagnalMove <= rightMove && diagnalMove <= downMove){
			//if a new min is required
			if(min < diagnalMove){
				min = diagnalMove;
			}

			cout << "Making Diagnal Move" << endl;
			ToothRecursive(x + 1, y + 1, LT, min, topOut, bottomOut);
		}
	}
}


int main(){
    int n,m,temp;

    ifstream file("input.txt");
    file >> n >> m;

    // Reads data from input file "input.txt" and initializes it to the arrays topTeeth and bottomTeeth
    if(file.is_open()){
        for(int i = 0 ; i < n ; i++){
            file >> temp;
            topTeeth.push_back(temp);
            cout << topTeeth.at(i) << " ";
        }
        cout << endl;
        for(int i = 0 ; i < m ; i++){
            file >> temp;
            bottomTeeth.push_back(temp);
            cout << bottomTeeth.at(i) << " ";
        }
		cout << endl;
        file.close();
    }
    
    // Initialize lookup table to -1 amd values of top and bottom teeth
    vector<vector<int>> LT(m+1, vector<int>(n+1, -1));

	// populate lookup table with sum of teeth sizes
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            LT[i][j] = topTeeth.at(j) + bottomTeeth.at(i);
			cout << LT[i][j] << '\t';
        }
		cout << endl;
    }

	// Find minVal base case
	int leftMolar = LT[0][0];
	int rightMolar = LT[n-1][m-1];
	int minVal;
	if (leftMolar > rightMolar) {
		minVal = leftMolar;
	}
	else {
		minVal = rightMolar;
	}
	
	// Call recursive function
	vector<int> topOutput;
	vector<int> bottomOutput;
	ToothRecursive(0, 0, LT, minVal, topOutput, bottomOutput);


    // output new data to file "output.txt"
	ofstream out_file("output.txt");
	
	out_file << minVal << endl;
	cout << "***OUTPUT***" << endl;
	cout << minVal << endl;

	// outputs all corresponding teeth values in order
	for (int i = 0 ; i < topOutput.size() ; i++) {
		out_file << topOutput[i] << " " << bottomOutput[i] << endl;
		cout << topOutput[i] << " " << bottomOutput[i] << endl;
	}

	out_file.close();
		 

    return 0;
}
