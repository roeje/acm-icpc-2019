//
// Created by Jesse on 12/2/2015.
//

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/*Main logic method*/
string readData(istream& input) {
    string c = "";
    int itr = 1;

    /*Loop over each test case*/
    while (input >> c && c != "STOP") {

        /*Unique case for spacing between individual tests*/
        if(itr != 1){
            cout << endl;
        }
        string originalOrder = c;
        cout << "Dataset #" << itr <<":  The initial order is " << originalOrder << "." << endl;
        int tests = 0;
        input >> tests;

        /*loop through each character removal*/
        while (tests > 0) {
            string charToRemove = "";
            input >> charToRemove;
            int location = originalOrder.find(charToRemove);
            string before = originalOrder.substr(0, location);
            string after = originalOrder.substr(location + 1, originalOrder.length());
            if(before.length() <= after.length()) {
                originalOrder.erase(0,location + 1);
                for (auto itr = before.begin(); itr != before.end(); ++itr) {
                    string s = "";
                    s += (*itr);
                    originalOrder = s += originalOrder;
                }
            }
            else {
                originalOrder.erase(location, originalOrder.size());
                for (auto itr = after.rbegin(); itr != after.rend(); ++itr) {
                    string s = "";
                    s +=(*itr);
                    originalOrder += s;
                }
            }

            /*Output after each removal*/
            cout << "After " << charToRemove << " leaves, the order is " << originalOrder << "." << endl;
            tests--;
        }
        itr++;
    }
}

int main(){
#ifndef ONLINE_JUDGE

    /*Test data with edge cases*/
    string testData = "ABCDEFG\n"
            "3\n"
            "E\n"
            "C\n"
            "D\n"
            "HIWORLD\n"
            "1\n"
            "H\n"
            "ABC\n"
            "3\n"
            "A\n"
            "B\n"
            "C\n"
            "HIWORLD\n"
            "1\n"
            "O\n"
            "H\n"
            "1\n"
            "H\n"
            "A\n"
            "0\n"
            "FDJK\n"
            "2\n"
            "D\n"
            "F\n"
            "FDJK\n"
            "2\n"
            "D\n"
            "F\n"
            "FDJK\n"
            "2\n"
            "J\n"
            "K\n"
            "FDJK\n"
            "2\n"
            "K\n"
            "J\n"
            "HIWORLD\n"
            "1\n"
            "D\n"
            "HIWORLD\n"
            "1\n"
            "O\n"
            "STOP";

    istringstream data(testData);
#else
    istream& data = cin;
#endif
    readData(data);
}