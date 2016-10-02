#include <iostream>

using namespace std;

string lights(string row, int n, string &solution){

    solution = "Testing";

    return "";
}

int main()
{
    string userRow;
    int rowLength;
    string output;

    cout << "Please enter the row length: " << endl;
    cin >> rowLength;

    cout << "Please enter the light puzzle: " << endl;
    cin >> userRow;

    lights(userRow, rowLength, output);

    cout << output;

    return 0;
}
