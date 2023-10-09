#include <stdio.h>

int main() {
    char name[15];
    char newName;
    for (int i = 1; i <= len(name); i++)
    {
        newName += name[-i];
    }
    printf("%s", &newName);

    return 0;
}