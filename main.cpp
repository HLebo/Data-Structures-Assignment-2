#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//changing the value of a character from 0 to 1 or 1 to 0
char switchValue(char c){
    if(c == '0'){
        return '1';
    }
    else
        return '0';
}

//recursive lights function
string lights(string row, int n, int solution[40], int &state){

    //base cases
    if(row.size() == 1){
        if(row[0] == '1'){
            row[0] = '0';
            solution[0] = 1;
        }
        else{
            //already solved
            state = 3;
        }
        return row;
    }

    else if(row.size() == 2){
        if(row == "00"){
            //already solved
            state = 3;
        }
        else if(row == "11"){
            row[0] = switchValue(row[0]);
            row[1] = switchValue(row[1]);

            solution[0] = 1;
        }
        else{
            //no solution
            state = 2;
        }
        return row;
    }

    else if(row.size() == 3){

        if(row[2] == '1'){
            //hitting the middle light
            row[0] = switchValue(row[0]);
            row[1] = switchValue(row[1]);
            row[2] = switchValue(row[2]);

            //recording the index of the one we hit
            int i = 0;
            while(i < 40 && solution[i] != 0){
                i++;
            }

            solution[i] = n-1;
        }
        return row;
    }


    else{
        //removing first element from row to create smaller row
        string subRow = row.substr(1,row.size());

        //recursion
        subRow = lights(subRow, n, solution, state);

        //reconstructing the row
        string newRow = row[0] + subRow;

        if(newRow[2] == '1'){
            newRow[0] = switchValue(newRow[0]);
            newRow[1] = switchValue(newRow[1]);
            newRow[2] = switchValue(newRow[2]);

            //recording the index of the one we hit
            int x = n - newRow.size() + 2;
            int i = 0;
            while(i < 40 && solution[i] != 0){
                i++;
            }
            solution[i] = x;
        }

        //once row is back to original length
        if(n == newRow.size()){
            if(newRow[1] == '1'){
                newRow[0] = switchValue(newRow[0]);
                newRow[1] = switchValue(newRow[1]);

                //searching for last element of solution
                int i = 0;
                while(i < 40 && solution[i] != 0){
                    i++;
                }

                //add last result to solution
                solution[i] = 1;
            }

            if(newRow[0] == '1'){
                if((n-1)%3 == 1){
                    //no solution
                    state = 2;
                }
                else{
                    newRow[n-1] = switchValue(newRow[n-1]);
                    newRow[n-2] = switchValue(newRow[n-2]);

                    //recording the index of the one we hit
                    int i = 0;
                    while(i < 40 && solution[i] != 0){
                        i++;
                    }
                    solution[i] = n;

                    //run recursive algorithm again attempting to remove the single leftover 1 located on left end
                    newRow = lights(newRow, n, solution, state);

                    //removing duplicates from solution
                    for(int i = 0; i < 40; i++){
                        for(int k = i+1; k < 40; k++){
                            if(solution[i] == solution[k]){
                                solution[i] = 0;
                                solution[k] = 0;
                            }
                        }
                    }
                }
            }
        }

        return newRow;
    }

}

int main()
{

    //user input variables
    string userRow;
    int rowLength;

    do{

        //asking user for input
        cout << "Please enter the row length: ";
        cin >> rowLength;

        cout << "Please enter the light puzzle: ";
        cin >> userRow;

        //assume is solvable
        int state = 1;

        //ensure output is empty before calling recursive function
        int output[40] = {0};

        //calling recursive function
        lights(userRow, rowLength, output, state);

        //sorting output
        sort(output, output + 40);

        //printing output
        if(state == 2){
            cout << "NO SOLUTION" << endl << endl;
        }

        else if(state == 3 || output[39] == 0){
            cout << "Already solved" << endl << endl;
        }

        else{
            cout << "The solution is ";

            for(int i = 0; i < 40; i++){
                if(output[i] != 0){
                    std::ostringstream oss;
                    oss << output[i];
                    cout << oss.str() << " ";
                }

            }
            cout << endl << endl;
        }

    } while(rowLength != 0);

    return 0;
}
