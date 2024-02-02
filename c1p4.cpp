#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {
    if (argc != 2) exit(1);
    std::string S = argv[1];

    std::map<char,int> dict;
    for (char c: S) {
        if (dict.find(c) == dict.end()) dict.insert(std::pair<char,int>(c,1));
        else dict[c]++;
    }

    int odds = 0;
    for (std::pair<char,int> p: dict) {
        if (p.second % 2) odds++;
    }
    if (S.size() % 2 && odds == 1) std::cout << "true" << std::endl;
    else if (S.size() % 2 == 0 && odds == 0) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}