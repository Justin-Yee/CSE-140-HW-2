#include <stdio.h>
#include <string.h>

char strArr[6][10];

int function(int i){
 char* regName;
 int regNum;

  //printf ("%s\n",strArr[1]);

  regName = strArr[1];

  if(strncmp(regName,"t",1) == 0)
    printf ("a:%s\n",regName);
  if(strncmp(regName,"r",1) == 0)
    printf ("b:%s\n",regName);
  if(strncmp(regName,"a",1) == 0)
    printf ("c:%s\n",regName);
  if(strncmp(regName,"s",1) == 0)
    printf ("d:%s\n",regName);

 regNum = strArr[1][1];
 regNum = (int)regNum - 48;
  printf ("%d\n",regNum);

  return 0;
}

int main()
{
 char strvar[100] = " add s1 t2 zero";

  printf ("Hello World!\n");

// fgets (strvar, 100, stdin);

  printf ("%s\n",strvar);
int i = 0;
 char * point;

 point = strtok(strvar," ");

 while( point != NULL){ //Go through string str and store each piece in strArr
    strncpy(strArr[i], point, 10);
    //printf ("%s == %s\n",point, strArr[i]);
	point = strtok(NULL," ");
    i++;
	}

 int tempInt = 10;
 char tempStr[10];
 function(tempInt);

// // strcpy(tempStr, (char)tempInt+"\n");
//  sprintf(strArr[2], "%d", function(tempInt));
//   printf ("Int to Char: %s\n",strArr[2]);

//  tempInt = 0;
//  tempInt = strArr[2][1] ;

//  //sprintf(tempInt, "%s", strArr[2]);
//   printf ("Char to Int: %d\n",tempInt);

//  tempInt = strArr[2][0] ;

//  //sprintf(tempInt, "%s", strArr[2]);
//   printf ("Char to Int2: %d\n",tempInt);


// //  strcpy(strArr[2], (char)function(3)+"\n");
// //   printf ("strcopy: %s\n",strArr[2]);

  printf ("End test\n");
  return 0;
}
