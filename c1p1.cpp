#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

bool check_unique (string S) {
    map<char,int> dict;
    for (char c: S) {
        if (dict.find(c) == dict.end()) dict.insert(pair<char,int>(c,1));
        else return false;
    }
    return true;
}

int main (int argc, char *argv[]) {
    if (argc != 2) exit(1);
    map<char, int> dict;
    string S = argv[1];
    cout << check_unique(S) << endl;
    return 0;
}