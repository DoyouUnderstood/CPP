#include <iostream>
#include <string>
#include <stdio.h>

#include <iostream>
#include <cctype>

#include <iostream>
#include <cctype>

// Main function
#include <iostream>
#include <cctype>

#include <iostream>
#include <cctype>

#include <iostream>
#include <cctype>

#include <iostream>
#include <cctype>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        bool last_was_space = false;
        for (int i = 1; i < argc; ++i) {
            for (int j = 0; argv[i][j] != '\0'; ++j) {
                char c = argv[i][j];
                if (std::isspace(c)) {
                    if (!last_was_space) {
                        std::cout << " ";
                        last_was_space = true;
                    }
                } else {
                    std::cout << (char)std::toupper(c);
                    last_was_space = false;
                }
            }
            if (i < argc - 1 && !last_was_space) {
                std::cout << " ";
                last_was_space = true;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}



