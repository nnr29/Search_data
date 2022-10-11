#include <stdio.h>                                                                             //Pre-processor directive
#include <stdlib.h>
#include <string.h>
void display_searched_data();
void display_file_word();

FILE *file_ptr;                                                                             //file pointer
int line_position = 1,line_search=0;
int main()
{
   display_searched_data();                                                                //function call
   return 0;
}
void display_searched_data()
{
    char store_The_Value[100];
    file_ptr = fopen("task.txt","r");                                                      //file opened in reading mode
    if (file_ptr == NULL)
    {
        printf("file does not exist\n");
    }
    printf("Enter line number to search :");
    scanf("%d",&line_search);                                                             //user enters the line number
    while(fgets(store_The_Value,100,file_ptr))
    {
        if(line_search == line_position)                                                 //comparing line search and line position
        {
            printf("line no. %d\nInformation : %s\n",line_search,store_The_Value);
        }
        line_position++;
    }
    display_file_word();
}

int countOccurrences(FILE *file,  char *word)
{
    char verifyThevalue[100];
    char *position;
    int index, count;
    count = 0;
    printf("Inside the Count the occourance function \n");
    while((fgets(verifyThevalue,100,file)) != NULL)
    {
        index = 0;
        while ((position=strstr(verifyThevalue+index,word)) != NULL)
        {
            index=(position - verifyThevalue)+1;
            count++;
        }
    }
    return count;
}
void display_file_word()
{
    char *word;                                                                          // character pointer
    int i=0;
    word = malloc(10*sizeof(char));                                                     //dynamically allocate memory
    if ((file_ptr = fopen("task.txt", "r"))==NULL)                                     // file opened in reading mode
    {
        printf("File not found. \n");
        exit(1);
    }
    else
    {
        printf("Enter the word to be searched : ");
        scanf("%s",word);                                                           // user enters the word to be searched
        i = countOccurrences(file_ptr,word);
    }
    if (i == 0)
        printf("Word not found   %s\n",word);
    else
        printf("Word found      %s\n",word);
    free(word);                                                                  //free function de-allocate the entered memory
    fclose(file_ptr);                                                           // file closed
}





