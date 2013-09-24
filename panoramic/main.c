#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 3

char magicNumber(char *chaine, char *nameOfFile) //Function which catch the magic number of the file.
{
    FILE *file = NULL;
    file =fopen(nameOfFile,"r"); // we open the file

    if(file != NULL) // we test if we can reach the file
        {
        printf("Fichier readable \n"); // The file is readable
        fgets(chaine, TAILLE_MAX, file); // we assign in chaine the magic number of the file
        fclose(file); // we close the file for memory
        }
    else
        {
        printf("Fail! \n"); // the file is unreadable
        }
    return chaine;
}

int countlines(char *nameOfFile)
{
  // count the number of lines in the file
  FILE *file = NULL;
  file = fopen(nameOfFile,"r");

  int ch=0;
  int lines=0;

  if (file == NULL)  // If the file is unreachable we will return 1
    return 1;
    while(!feof(file))
    {
        ch = fgetc(file);
        if(ch == '\n')
        {
        lines++;
    }
    }
    fclose(file);
    return lines;
}


char heightAndWidth(char *nameOfFile, char *valueOfHeightAndWidth)
{
    int i;
    FILE *file = NULL;
    file = fopen(nameOfFile,"r");//counter
    for (i = 1 ; i < 3 ; i++)
        {
            fgets(valueOfHeightAndWidth, 256, file);
        }
    return valueOfHeightAndWidth;
}





/*bool commentaryVerification(char *chaine, int entier)
{
    File* fichier = NULL;
    fichier = fopn("picture.ppm","r");
    if(fichier != NULL) // we test if we can reach the file
        {

        fgets(chaine, TAILLE_MAX, fichier); // we assign in chaine the magic number of the file
        fclose(fichier); // we close the file for memory
        }
    else
        {
        printf("echec logistique (Bool function) \n"); // the file is unreadable
        }
    return chaine;
}*/

int main()
{
    int a;
    char nameOfYourFile[256];
    char image[256];
    char hAW[256] = "";
    char Pn[TAILLE_MAX] = ""; // Pn is the magic number
    printf("What is the name of the file you want to use? \n");
    scanf("%s", nameOfYourFile);
    magicNumber(Pn, nameOfYourFile);
    printf("Magic number: %s \n",Pn);
    //printf("What is the name of the file you want to use? \n");
    //scanf("%s", nameOfYourFile);
    a = countlines(nameOfYourFile);
    printf("Number of lines: %d \n", a);
    //printf("What is the name of the file you want to know its height and width? \n");
    //scanf("%s", nameOfYourFile);
    heightAndWidth(nameOfYourFile, hAW);
    printf("Height and width: %s", hAW);
    return 0;

}


