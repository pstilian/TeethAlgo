#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

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