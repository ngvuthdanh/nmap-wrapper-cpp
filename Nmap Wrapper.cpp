#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

void runNmapCommand(const string &target, const string &options, const string &outputFile) {
    string command = "nmap " + options + " " + target + " -oN " + outputFile;
    cout << "Running command: " << command << endl;

    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Failed to execute Nmap command!" << endl;
        exit(1);
    }
}

void parseNmapOutput(const string &outputFile) {
    ifstream file(outputFile);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << outputFile << endl;
        exit(1);
    }

    string line;
    cout << "\n--- Nmap Scan Results ---\n" << endl;
    while (getline(file, line)) {
        if (line.find("/tcp") != string::npos || line.find("/udp") != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

int main() {
    string target, options, outputFile;

    cout << "Enter the target IP or domain: ";
    cin >> target;

    cout << "Enter Nmap options (e.g., -sS for SYN scan): ";
    cin.ignore();
    getline(cin, options);

    cout << "Enter output file name (e.g., scan_results.txt): ";
    cin >> outputFile;

    runNmapCommand(target, options, outputFile);


    parseNmapOutput(outputFile);

}
