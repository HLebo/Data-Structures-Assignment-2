#include <iostream>

using namespace std;

string lights(string row, int n){
    return "";
}

int main()
{
    string userRow;
    int rowLength;

    cout << "Please enter the row length: " << endl;
    cin >> rowLength;

    cout << "Please enter the light puzzle: " << endl;
    cin >> userRow;

    lights(userRow, rowLength);

    return 0;
}
