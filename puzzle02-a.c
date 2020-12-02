#include<stdio.h>

int main(void)
{
    FILE * fp;
    int min, max, index, counter, valid;
    char letter;
    char password[100]; 

    fp = fopen("puzzle2Input.txt", "r");
    if (fp == NULL)
    {
        printf("Not found\n");
    }
    
    valid = 0;
    while(!feof(fp))
    {
        /*Reference  for fscanf format 
        https://stackoverflow.com/questions/17214026/ignoring-separating-character-using-scanf*/
        fscanf(fp,"%d-%d %c: %s", &min, &max, &letter, password);
        
        /* printf("min = %i\n", min);
        printf("max = %i\n", max);
        printf("letter = %c\n", letter);     
        printf("password = %s\n", password); */

        index = 0;
        counter = 0;

        while (password[index] != '\0')
        {
            if (password[index] == letter)
            {
                counter++;
            }
            index++;
        }   

        if (counter >= min && counter <= max)
        {
            valid++;
        }
    }
    printf("Valid = %i\n", valid);
    fclose(fp);

    return 0;
}
