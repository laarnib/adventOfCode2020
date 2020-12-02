
// https://adventofcode.com/2020/day/2

#include<stdio.h>

int main(void)
{
    FILE * fp;
    int min, max, index, valid, invalid;
    char letter;
    char password[100]; 

    fp = fopen("puzzle2Input.txt", "r");
    if (fp == NULL)
    {
        printf("Not found\n");
    }
    
    invalid = 0;
    valid = 0;
    while(!feof(fp))
    {
        /*Reference  for fscanf format 
        https://stackoverflow.com/questions/17214026/ignoring-separating-character-using-scanf*/
        fscanf(fp,"%d-%d %c: %s", &min, &max, &letter, password);
        
        /* printf("min = %i\n", min);
        printf("max = %i\n", max);
        printf("letter = %c\n", letter);     
        printf("password = %s\n", password); 
        printf("password[%i] : %c\n", min-1, password[min-1]);
        printf("password[%i] : %c\n", max-1, password[max-1]);*/

        if (((password[min-1] == letter) && (password[max-1] != letter)) || ((password[min-1] != letter) && (password[max-1] == letter)))
        {
            //printf("inside if");
            valid++;
        }
    
    }
    printf("Valid = %i\n", valid);
    fclose(fp);

    return 0;
}