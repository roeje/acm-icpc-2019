

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string readData(istream& input) {
    string c = "";
    int itr = 1;
    while (input >> c && c != "STOP") {
        if(itr != 1){
            cout << endl;
        }
        string originalOrder = c;
        cout << "Dataset #" << itr <<":  The initial order is " << originalOrder << "." << endl;
        int tests = 0;
        input >> tests;
        while (tests > 0) {
            string charToRemove = "";
            input >> charToRemove;
            int location = originalOrder.find(charToRemove);
//            cout << location << endl;

            if(location <= originalOrder.size()/2) {
                string tempCars = originalOrder.substr(0, location);
//                cout << tempCars << endl;
                originalOrder.erase(0,location + 1);
//                cout << originalOrder << endl;
                for (auto itr = tempCars.begin(); itr != tempCars.end(); ++itr) {
                    string s = "";
                    s +=(*itr);
                    originalOrder = s += originalOrder;
//                    cout << originalOrder << endl;
                }
            }
            else {
                string tempCars = originalOrder.substr(location + 1, originalOrder.size());
//                cout << tempCars << endl;
                originalOrder.erase(location, originalOrder.size());
//                cout << originalOrder << endl;
                for (auto itr = tempCars.rbegin(); itr != tempCars.rend(); ++itr) {
                    string s = "";
                    s +=(*itr);
                    originalOrder += s;
//                    cout << originalOrder << endl;
                }
            }
            if(tests != 1) {
                cout << "After " << charToRemove << " leaves, the order is " << originalOrder << "." << endl;
            }
            else {
                cout << "After " << charToRemove << " leaves, the order is " << originalOrder << ".";
            }
            tests--;
        }
        itr++;
//        cout << endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    string testData = "ABCDEFG\n"
            "3\n"
            "E\n"
            "C\n"
            "D\n"
            "HIWORLD\n"
            "1\n"
            "H\n"
            "STOP";
    istringstream data(testData);
#else
    istream& data = cin;
#endif
    readData(data);
    return 0;
}

//ABC
//3
//A
//B
//C
//HIWORLD
//1
//O
//H
//1
//H
//A
//0
//FDJK
//2
//D
//F
//HIWORLD
//1
//D
//HIWORLD
//1
//O
//STOP