#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    if (argc != 3) exit(1);
    std::string S1 = argv[1], S2 = argv[2];

    bool match = false;
    for (unsigned int i = 0; i < S1.size(); i++) {
        if (S1[i] == S2[0]) {
            std::string temp = S1.substr(i);
            if (S2.find(temp) == 0) {
                if (S2.find(S1.substr(0,i)) == temp.size()) { match = true; break; }
            }
        }
    }
    if (match) std::cout << " rotate match " << std::endl; 
    else std::cout << " no match " << std::endl;
}