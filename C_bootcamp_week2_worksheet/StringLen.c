#include <stdio.h>

int stringLength(char Input)
{
    for (int* i = 0; i < Input; i++)
    {
        if (Input[i] == "/0")
        {
            return i;
        }
    }
}

int main(){
    stringLength("Balls");
}