#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if (argc == 1)
    {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    for (int i = 1; argv[i]; i++) 
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char) toupper(argv[i][j]);
        if (i < argc - 1)
            std::cout << ' ';
    }
    return (1);
}