#include <iostream>

using namespace std;

string lights(string row, int n, string &solution){

    if(n == 1){
        if(row[0] == '1'){
            row[0] = '0';
            solution = "1";
        }
        return solution;
    }

    else if(n == 2){
        return "";
    }

    else if(n == 3){
        return "";
    }

    else{

        return "";
    }

}

int main()
{
    string userRow;
    int rowLength;
    string output;

    cout << "Please enter the row length: ";
    cin >> rowLength;

    cout << "Please enter the light puzzle: ";
    cin >> userRow;

    lights(userRow, rowLength, output);

    cout << "The solution is " << output << endl;

    return 0;
}
