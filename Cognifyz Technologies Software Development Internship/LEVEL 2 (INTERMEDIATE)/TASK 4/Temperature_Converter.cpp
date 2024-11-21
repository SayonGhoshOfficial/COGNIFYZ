#include <iostream>
using namespace std;

void celsiusToOther(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    double kelvin = celsius + 273.15;
    cout << celsius << " °C = " << fahrenheit << " °F" << endl;
    cout << celsius << " °C = " << kelvin << " K" << endl;
}

void fahrenheitToOther(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    double kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    cout << fahrenheit << " °F = " << celsius << " °C" << endl;
    cout << fahrenheit << " °F = " << kelvin << " K" << endl;
}

void kelvinToOther(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    cout << kelvin << " K = " << celsius << " °C" << endl;
    cout << kelvin << " K = " << fahrenheit << " °F" << endl;
}

int main() {
    int choice;
    double temperature;

    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit and Kelvin" << endl;
    cout << "2. Fahrenheit to Celsius and Kelvin" << endl;
    cout << "3. Kelvin to Celsius and Fahrenheit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter temperature value: ";
    cin >> temperature;

    switch (choice) {
        case 1:
            celsiusToOther(temperature);
            break;
        case 2:
            fahrenheitToOther(temperature);
            break;
        case 3:
            kelvinToOther(temperature);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
