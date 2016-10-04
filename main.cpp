#include <iostream>
#include <string>
#include <sstream>

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
string lights(string row, int n, string &solution){

    //base cases
    if(row.size() == 1){
        if(row[0] == '1'){
            row[0] = '0';
            solution = "1";
        }
        else{
            solution = "Already solved";
        }
        return row;
    }

    else if(row.size() == 2){
        if(row == "00"){
            solution = "Already solved";
        }
        else if(row[1] == '1'){
            row[0] = switchValue(row[0]);
            row[1] = switchValue(row[1]);

            std::ostringstream oss;
            oss << n;
            solution = oss.str();
        }
        else{
            solution = "NO SOLUTION";
        }
        return row;
    }

    else if(row.size() == 3){

        /*if(n == 4){
            string subRow = row.substr(1,row.size());
            string row_prev = lights(subRow, n, solution);
            row_prev = row[0] + row_prev;
        }

        else*/
        if(row[2] == '1'){
            //hitting the middle light
            row[0] = switchValue(row[0]);
            row[1] = switchValue(row[1]);
            row[2] = switchValue(row[2]);

            //recording the index of the one we hit
            int x = n-1;
            std::ostringstream oss;
            oss << x;
            solution = oss.str();
        }
        return row;
    }


    else{
        //removing first element from row to create smaller row
        string subRow = row.substr(1,row.size());

        //recursion
        subRow = lights(subRow, n, solution);

        //reconstructing the row
        string newRow = row[0] + subRow;

        if(newRow[2] == '1'){
            newRow[0] = switchValue(newRow[0]);
            newRow[1] = switchValue(newRow[1]);
            newRow[2] = switchValue(newRow[2]);

            //recording the index of the one we hit
            int x = n - newRow.size() + 2;
            std::ostringstream oss;
            oss << x;
            solution = oss.str() + ' ' + solution;
        }

        if(n == newRow.size()){
            if(newRow[1] == '1'){
                newRow[0] = switchValue(newRow[0]);
                newRow[1] = switchValue(newRow[1]);

                solution = "1 " + solution;
            }
        }

        return newRow;
    }

}

int main()
{

    string userRow;
    int rowLength;
    string output;

    do{

    //asking user for input
    cout << "Please enter the row length: ";
    cin >> rowLength;

    cout << "Please enter the light puzzle: ";
    cin >> userRow;

    //ensure output is empty before calling recursive function
    output = "";

    //printing output
    cout << "Ending row " << lights(userRow, rowLength, output) << endl;

    cout << "The solution is " << output << endl << endl;

    } while(rowLength != 0);

    return 0;
}
