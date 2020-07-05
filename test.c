#include <stdio.h>
#include <string.h>

char strArr[6][10];

int main()
{
 char strvar[100] = " addi s1 t2 zero";

  printf ("Hello World!\n");

// fgets (strvar, 100, stdin);

  printf ("%s\n",strvar);
int i = 0;
 char * point;

 point = strtok(strvar," ");

 while( point != NULL){ //Go through string str and store each piece in strArr
    strncpy(strArr[i], point, 10);
    printf ("%s == %s\n",point, strArr[i]);
	point = strtok(NULL," ");
    i++;
	}

  return 0;
}
