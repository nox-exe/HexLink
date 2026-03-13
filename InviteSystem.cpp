#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include <iterator>
#include <algorithm>
using namespace std;

void generateHex(char str[], int length)
{
    // hexadecimal characters
    char hexChar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    int i;
    for (i = 0; i < length; i++)
    {
        str[i] = hexChar[rand() % 16];
    }
    str[length] = 0;
}

string myGetline()
{
    string result;

    while (!getline(cin, result) || result.empty())
        ;

    return result;
}

int main()
{
    // organizer pre-existing file
    ofstream writeFile("6E053DFE.txt");
    writeFile << "6E053DFE" << endl;
    writeFile << "ORGANIZER" << endl;
    writeFile << "Kayden Break" << endl;
    writeFile.close();

    // start interface
    string code;
    char choice;
    string invite;

    cout << "Welcome!" << endl;

    cout << "What is your 8-digits hex code? ";
    cin >> code;

    string fileName = code + ".txt";

    // to check if it is code is valid
    ifstream readFile(fileName);
    if (readFile.is_open())
    {
        string tempCode;
        getline(readFile, tempCode);

        char charOne = tempCode.at(0);
        char charTwo = tempCode.at(1);
        char charThree = tempCode.at(2);
        char charFour = tempCode.at(3);

        string codeReference;
        codeReference += charOne;
        codeReference += charTwo;
        codeReference += charThree;
        codeReference += charFour;

        string tempRole;
        getline(readFile, tempRole);

        string tempName;
        getline(readFile, tempName);

        //outputs code file
        cout << endl;
        cout << tempCode << endl;
        cout << tempRole << endl;
        cout << tempName << endl;
        cout << endl;

        char firstChar = tempCode.at(4);
        char secondChar = tempCode.at(5);
        char thirdChar = tempCode.at(6);
        char fourthChar = tempCode.at(7);

        string refCode;
        refCode += firstChar;
        refCode += secondChar;
        refCode += thirdChar;
        refCode += fourthChar;

        ofstream writeFile(refCode + ".txt");
        writeFile << tempCode << endl;
        writeFile.close();

        ifstream readFile(codeReference + ".txt");
        if (readFile.is_open() && tempRole != "ORGANIZER")
        {
            cout << "You are invited! " << endl;
            cout << "Referal Code: " << codeReference << endl;
            cout << "Your code: " << code << endl;
            readFile.close();

            ofstream writeFile((codeReference + ".txt"), ios::app);
            writeFile << code << endl;
            writeFile.close();
        } else {
            cout << "You are the organizer." << endl << endl;
        }

        // invite and check list of inviters
        cout << "What would you like to do?" << endl;
        cout << "[Y] Invite 2 people" << endl;
        cout << "[E] Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 'Y':
        case 'y':
        {
            ofstream writeFile("6E05.txt", ios::app);
            writeFile << "6E053DFE" << endl;
            writeFile << "6E053DFE" << endl;
            writeFile.close();

            for (int i = 0; i < 2; i++)
            {
                ifstream readFile(codeReference + ".txt");
                if(readFile.is_open()){

                    readFile.unsetf(ios::skipws);

                    unsigned line_count = count(
                    istream_iterator<char>(readFile),
                    istream_iterator<char>(), '\n');

                    if (line_count < 3){
                        readFile.close();
                    } else if (line_count >= 3){
                        cout << "You've invited two persons already." << endl;
                        readFile.close();
                        return 0;
                    }
                } else {
                    cout << "CORRUPT FILE." << endl;
                }

                cout << "\nWho do you want to invite? ";
                invite = myGetline();

                int length = 4;
                char hex[30];

                srand(time(0));
                for (int i = 0; i < 1; i++)
                {
                    generateHex(hex, length);
                    cout << invite << "'s code is: " << refCode << hex << endl;

                    string newCode;
                    newCode += refCode;
                    newCode += hex;

                    string guestFile = newCode + ".txt";

                    ofstream writeFile(guestFile);
                    writeFile << newCode << endl;
                    writeFile << "INVITEE" << endl;
                    writeFile << invite << endl;
                    writeFile.close();
                }
            }
            readFile.close();
            break;
        }

        case 'E':
        case 'e':
        {
            cout << "Thank you for joining our event. If you ever want to invite 2 more people, please re-enter the system with your code." << endl;
            return 0;
        }

        default:
        {
            cout << "Invalid response!";
            break;
        }
        }
        readFile.close();
    }
    else
    {
        cout << "INVALID CODE. Please contact your organizer." << endl;
    }

    return 0;
}

