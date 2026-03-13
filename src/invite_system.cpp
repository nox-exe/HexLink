#include "invite_system.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

int countInvitees(string inviterCode) {
    string trackFile = "data/users/" + inviterCode + "_track.txt"; 
    ifstream file(trackFile);
    if (!file.is_open()) return 0;

    return count(istream_iterator<char>(file >> noskipws), istream_iterator<char>(), '\n');
}

string generateHex(int length) {
    char hexChar[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string result;
    for(int i=0; i<length; i++) result += hexChar[rand() % 16];
    return result;
}

bool validateCode(string code) {
    ifstream file("data/users/" + code + ".txt");
    return file.is_open();
}

void createUser(string code, string role, string name) {
    ofstream file("data/users/" + code + ".txt");
    file << code << "\n" << role << "\n" << name << endl;
    file.close();
}

vector<string> generateInviteCodes(string inviterCode) {
    vector<string> codes;
    
    if (countInvitees(inviterCode) >= 2) {
        return codes; 
    }

    string newPrefix = inviterCode.substr(4, 4); 
    string trackFile = "data/users/" + inviterCode + "_track.txt";
    ofstream writeFile(trackFile, ios::app);

    for(int i = 0; i < 2; i++) {
        string newCode = newPrefix + generateHex(4);
        codes.push_back(newCode);
        createUser(newCode, "INVITEE", "Guest");
        writeFile << newCode << endl; 
    }
    
    writeFile.close();
    return codes;
}

string getInviterInfo(string code) {
    string prefix = code.substr(0, 4);
    return prefix; 
}