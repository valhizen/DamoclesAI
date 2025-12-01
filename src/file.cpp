#include <iostream>
#include <fstream>
//#include <filesystem>
#include <string>
using namespace std;

int main() {
    //cout<< "CWD: "<<filesystem::current_path() << "\n";
    ifstream file("../Data/test.txt");  // Replace with your filename
    string line;

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
