#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000

int main ()
{
    char **line_ptr = calloc(MAX_LINE_SIZE, sizeof(*line_ptr));
    char line[MAX_LINE_SIZE];     
    int length = 0, i = 0;

    printf("Enter a series of lines: ");
    while (fgets(line, MAX_LINE_SIZE, stdin))
    {
        length = strcspn(line, "\n");
        if(length == 0)
        {
            break;
        }
        
        line_ptr[i] = strndup(line, length);
            if (line_ptr[i] == NULL)
            {
                fprintf(stderr, "Error allocating memory for line %d\n", i);
                return 1;
            }
        i++;
    }
    printf("\n");

    for (int j = i - 1; j >= 0; j--)
    {
        printf(" %s\n", line_ptr[j]);
        free(line_ptr[j]);
    }
    free(line_ptr);

    return 0;
}
