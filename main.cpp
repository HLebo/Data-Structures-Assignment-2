#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char switchValue(char c){
    if(c == '0'){
        return '1';
    }
    else
        return '0';
}

string lights(string row, int n, string &solution){

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
        else if(row == "11"){
            row = "00";
            solution = "1";
        }
        else{
            solution = "NO SOLUTION";
        }
        return row;
    }

    else if(row.size() == 3){
        if(row[2] == '1'){
            row[0] = switchValue(row[0]);
            row[1] = switchValue(row[1]);
            row[2] = switchValue(row[2]);

            int x = n-1;
            std::ostringstream oss;
            oss << x;
            solution = oss.str();
        }
        return row;
    }

    else{
        string subRow = row.substr(1,row.size());
        string row_prev = lights(subRow, n, solution);
        row_prev = row[0] + row_prev;

        return row_prev;
    }

}

int main()
{

    string userRow;
    int rowLength;
    string output;

    do{

    cout << "Please enter the row length: ";
    cin >> rowLength;

    cout << "Please enter the light puzzle: ";
    cin >> userRow;

    cout << "Ending row " << lights(userRow, rowLength, output) << endl;

    cout << "The solution is " << output << endl;

    } while(rowLength != 0);

    return 0;
}
