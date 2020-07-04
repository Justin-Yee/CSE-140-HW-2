
/*
Created by: 
William Breytberg
Irma Gonzalez Padilla
Justin Yee
*/

//Libraries
#include <cstring.h>
#include <iostream.h>

//Global Variable
char parsedArr[6][6]; //Holds the original string as segments
char foundArr[6][6];  //Holds the decimal value of the string
char binStr[32];       //Holds the binary as a string

//Functions

bool FindOp() { // Determines which OpCode it is
//return bool, 1 is successful, 0 is fail
 switch(parsedArr[0]){
    case "add":
        foundArr[5] = "32";
        binStr = "100000";
        return 1;
    case "addu":
        foundArr[5] = "33";
        binStr = "100001";
        return 1;
    case "and":
        foundArr[5] = "36";
        binStr = "100100";
        return 1;
    case "jr":
        foundArr[5] = "8";
        binStr = "001000";
        return 1;
    case "nor":
        foundArr[5] = "39";
        binStr = "100111";
        return 1;
    case "or":
        founArr[5] = "37";
        binStr = "100101";
        return 1;
    case "slt":
        founArr[5] = "42";
        binStr = "101010";
        return 1;
    case "sltu":
        founArr[5] = "43";
        binStr = "101011";
        return 1;
    case "sll":
        founArr[5] = "0";
        binStr = "000000";
        return 1;
    case "srl":
        founArr[5] = "2";
        binStr = "000010";
        return 1;
    case "sub":
        founArr[5] = "34";
        binStr = "100010";
        return 1;
    case "subu":
        founArr[5] = "35";
        binStr = "100011";
        return 1;
    default:
        founArr[5] = "-1";
        binStr = "222222";
        return 0;
    }
}

int FindR(int i){ // Determines the registers

 char regName; //Contains letter values of registar
 char regNum;  //Contains the numbers

 switch(parsedArr[i]){
    case "zero":{
        return 0;} 
    case "at":{
        return 1;}
    case "gp":{
        return 28;}
    case "sp":{
        return 29;}
    case "fp":{
        return 30;}
    case "ra":{
        return 31; }
    }


 regName = reg[0]; 
 regNum = reg[1];

 switch(regName){
    case "v":
        if( 0 < regNum < 1){
            return 2+regNum;
        }
    case "a":
        if( 0< regNum <3 ){
            return 4+regNum;
        }
    case "t":
        if( 0 < regNum < 7){
            return 8 + regNum;
        }
    case "s":
        if( 0 < regNum < 7){
            return 16+ regNum;
        }
    case "t":
        if( 8 < regNum < 9)
            return 24 or 25;
    case "k":
        if( 0< regNum< 1){
            return 26 + regNum;
        }
}

return -1; //Failed to find register
}

void Parser (char *str){ //Breaks string into an array
//Loop through "string" till end
//	Store string segments in ParsedString[];

char  * ptr;
Int i = 1;
strcat(" ", str);

ptr = strtok(str," "); //Find first use of spacebar

while( ptr != NULL){ //Go through string str and store each piece in strArr
	parsedArr[i] = ptr;
	ptr = strtok(NULL," ");
	i++;
	}
return;
}

char IntToBinary(int num,int size){
int bi = 1;
//int = num;
while(int >= bi*2){
	bi = bi*2;
}
char[50] bina = "";
while(num > 0){
	if(num >= bi){
		num -= bi;
		strcat(1, bina);//bina += "1";
	} else {
		strcat(0, bina);//bina += "0";
	}
	bi = bi / 2;
}
while(bina.length < size){
	bina = "0" + bina;
}
returns  bina;
}

void PrintOut() {//Prints out Instruction
cout << "operation: " << parsedArr[0]<< endl;
cout << "Rs: " << foundArr[1]<< endl;
cout << "Rt: " << foundArr[2] << endl;
cout << "Rd: " << foundArr[3]<< endl;
cout << "Shamt: 0" << endl;
cout << "Funct: " << foundArr[5]<< endl;
cout << "Machine Code: " << binStr << endl;
}

int main(){
char[99] input; //takes in user input

cout << "Please provide an R-type instruction." << endl;


//Input String
cin >> input;

Parser(input);//separate string based on space bar

//Pick which variable and print 
if(FindOp() == 0){ //returns Funct in Dec and in Binary
	cout << "Bad Input: Op" << endl;
	return 0;
	}

//Shamt(); //append bits to binary
strcat("00000", binStr);

//FindR(); //called 3 times for rs, rt, and rd

//foundArr[2] = FindR(2);//rs
strcat(foundArr[2], FindR(2));
if( strcmp(foundArr[2], "-1") == 0){ //returns Funct in Dec and in Binary
	cout << "Bad Input: rs" << endl;
	return 0;
	}

// foundArr[3] = FindR(3);//rt
// if(foundArr[3] == "-1"){ //returns Funct in Dec and in Binary
// 	cout << "Bad Input: rt" << endl;
// 	return 0;
// 	}

// foundArr[4] = FindR(4);//rd
// if(foundArr[4] == "-1"){ //returns Funct in Dec and in Binary
// 	cout << "Bad Input: rd" << endl;
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
