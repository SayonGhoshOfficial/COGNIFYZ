#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;

    int count=1;
    //rows
    for (int i = 1; i <= n; ++i) {
        // columns
        for (int j =1; j <=i; ++j) {
            cout <<count<< " ";
            count++;
        }

        // Move to the next line
        cout << endl;
    }

    return 0;
}