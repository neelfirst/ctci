#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    if (argc != 3) exit(1);
    std::string S1 = argv[1], S2 = argv[2];
    unsigned int i = 0, j = 0;
    int edit_counter = 0;
    while (i < S1.size() && j < S2.size()) {
        if (S1[i] != S2[j]) {
            if (++edit_counter > 1) break;
            if (S1[i+1] == S2[j]) i++;
            else if (S2[j+1] == S1[i]) j++;
            else if (S1[i+1] == S2[j+1]) { i++; j++; }
        }
        else { i++; j++; }
    }
    if (i - j > 1 || edit_counter > 1) std::cout << "> 1 edit" << std::endl;
    else std::cout << "<= 1 edit" << std::endl;
}