#include <stdio.h>
#include <string.h>

int main()
{
 char strvar[100];

  printf ("Hello World!\n");

 fgets (strvar, 100, stdin);

  printf (strvar);
  return 0;
}