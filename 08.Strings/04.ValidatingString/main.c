#include <stdio.h>

int validate(char* name)
{
    for (int i = 0; name[i] != '\0'; i++)
        if(!(name[i] >= 'A' && name[i] <= 'Z') &&
            !(name[i] >= 'a' && name[i] <= 'z') &&
            !(name[i] >= '0' && name[i] <= '9'))
            return 0;
    return 1;    
}

int main()
{
    char *name = "Ani?321";

    if(validate(name))
        printf("vaild string\n");
    else
        printf("Invaild string\n");


    return 0;
}
