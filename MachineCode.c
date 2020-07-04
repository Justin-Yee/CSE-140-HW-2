
/*
Created by: 
William Breytberg
Irma Gonzalez Padilla
Justin Yee
*/

//Libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Global Variable
char parsedArr[6][6]; //Holds the original string as segments
char foundArr[6][6];  //Holds the decimal value of the string
char binStr[32];       //Holds the binary as a string

//Functions

bool FindOp () { // Determines which OpCode it is
//return bool, 1 is successful, 0 is fail
if(strcmp(parsedArr[0],"add")){
        strcpy(foundArr[5], "32");
        strcpy(binStr,"100000");
        return 1;}
    else if( strcmp(parsedArr[0], "addu")) {
        strcpy(foundArr[5], "33");
        strcpy(binStr, "100001");
        return 1;}
    else if( strcmp(parsedArr[0], "and")) {
        strcpy(foundArr[5], "36");
        strcpy(binStr, "100100");
        return 1;}
    else if( strcmp(parsedArr[0], "jr")) {
        strcpy(foundArr[5], "8");
        strcpy(binStr, "001000");
        return 1;}
    else if( strcmp(parsedArr[0], "nor")) {
        strcpy(foundArr[5], "39");
        strcpy(binStr, "100111");
        return 1;}
    else if( strcmp(parsedArr[0], "or")) {
        strcpy(foundArr[5], "37");
        strcpy(binStr, "100101");
        return 1;}
    else if( strcmp(parsedArr[0], "slt")) {
        strcpy(foundArr[5], "42");
        strcpy(binStr, "101010");
        return 1;}
    else if( strcmp(parsedArr[0], "sltu")) {
        strcpy(foundArr[5], "43");
        strcpy(binStr, "101011");
        return 1;}
    else if( strcmp(parsedArr[0], "sll")) {
        strcpy(foundArr[5], "0");
        strcpy(binStr, "000000");
        return 1;}
    else if( strcmp(parsedArr[0], "srl")) {
        strcpy(foundArr[5], "2");
        strcpy(binStr, "000010");
        return 1;}
    else if( strcmp(parsedArr[0], "sub")) {
        strcpy(foundArr[5], "34");
        strcpy(binStr, "100010");
        return 1;}
    else if( strcmp(parsedArr[0], "subu")) {
        strcpy(foundArr[5], "35");
        strcpy(binStr, "100011");
        return 1;}
    else{
        strcpy(foundArr[5], "-1");
        strcpy(binStr, "222222");
        return 0;
    }
}

int FindR(int i){ // Determines the registers

 char regName; //Contains letter values of registar
 char regNum;  //Contains the numbers

 if( strcmp(parsedArr[i], "zero")) {
        return 0;} 
    else if( strcmp(parsedArr[i], "at")) {
        return 1;}
    else if( strcmp(parsedArr[i], "gp")) {
        return 28;}
    else if( strcmp(parsedArr[i], "sp")) {
        return 29;}
    else if( strcmp(parsedArr[i], "fp")) {
        return 30;}
    else if( strcmp(parsedArr[i], "ra")) {
        return 31; }
    
// regName = parsedArr[i][0]; 
 strcpy(regName, parsedArr[i][0]);
// regNum = parsedArr[i][1];
 strcpy(regNum, parsedArr[i][1]);

if(strcmp(regName, "v")) {
        if( 0 < regNum < 1)
            return 2+regNum;
        }
    else if(strcmp(regName, "a"))
        if( 0< regNum <3 ){
            return 4+regNum;
        }
    else if(strcmp(regName, "t"))
        if( 0 < regNum < 7){
            return 8 + regNum;
        }
    else if(strcmp(regName, "s"))
        if( 0 < regNum < 7){
            return 16+ regNum;
        }
    else if(strcmp(regName, "t"))
        if( 8 < regNum < 9)
            return 24 + 25;
    else if(strcmp(regName, "k"))
        if( 0< regNum< 1){
            return 26 + regNum;
        }

return -1; //Failed to find register
}

void Parser (char str[]){ //Breaks string into an array and sotre string segments in ParsedString[];

char temp[100] = " ";
char  *ptr;
int i = 0;

printf ( "Parse0\n");

strcat(temp, str);

ptr = strtok(*str," "); //Find first use of spacebar

while( ptr != NULL){ //Go through string str and store each piece in strArr
    strncpy(parsedArr[i], ptr, 6);
	ptr = strtok(NULL," ");
	i++;
	}
return;
}

char IntToBinary(int num,int size){
int bi = 1;

while(num >= bi*2){
	bi = bi*2;
}
char bina[50];
while(num > 0){
	if(num >= bi){
		num -= bi;
		strcat(1, bina);//bina += "1");
	} else {
		strcat(0, bina);//bina += "0");
	}
	bi = bi / 2;
}
while(sizeof(bina) < size){
	strcat(0, bina); //bina = "0" + bina;
}
return  bina;
}

void PrintOut() {//Prints out Instruction
printf ( "operation: %s", parsedArr[0]);
printf ( "Rs: %s", foundArr[1]);
printf ( "Rt: %s", foundArr[2] );
printf ( "Rd: %s", foundArr[3]);
printf ( "Shamt: 0" );
printf ( "Funct: %s", foundArr[5]);
printf ( "Machine Code: %s", binStr );
}

int main(){
char input[99]; //takes in user input

printf ( "Please provide an R-type instruction. \n" );

//Input String
fgets (input, 99, stdin);

printf ( "Parse: %s\n", input );
Parser(input);//separate string based on space bar


printf ( "FindOp: %s\n",parsedArr[0]);
//Pick which variable and print 
if(FindOp() == 0){ //returns Funct in Dec and in Binary
	printf ( "Bad Input: Op" );
	return 0;
	}

//Shamt(); //append bits to binary
strcat("00000", binStr);

//FindR(); //called 3 times for rs, rt, and rd

//foundArr[2] = FindR(2);//rs
strcat(foundArr[2], FindR(2));
if( strcmp(foundArr[2], "-1") == 0){ //returns Funct in Dec and in Binary
	printf ( "Bad Input: rs" );
	return 0;
	}

// foundArr[3] = FindR(3);//rt
// if(foundArr[3] == "-1"){ //returns Funct in Dec and in Binary
// 	printf ( "Bad Input: rt" );
// 	return 0;
// 	}

// foundArr[4] = FindR(4);//rd
// if(foundArr[4] == "-1"){ //returns Funct in Dec and in Binary
// 	printf ( "Bad Input: rd" );
// 	return 0;
// 	}

//IntToBin( integer ,length ); //returns a string to represent binary
// strcat(IntToBin( foundArr[4],5 ), binStr);//rd
// strcat(IntToBin( foundArr[3],5 ), binStr);//rt
// strcat( IntToBin( foundArr[2],5 ), binStr);//rs

//OpCode to Binary
strcat("00000", binStr);

//Print Funct
PrintOut();

return 0;
}
