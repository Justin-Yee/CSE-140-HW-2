
/*
Created by: 
William Breytberg
Irma Gonzalez Padilla
Justin Yee
*/

//Libraries 
#include cstring
#include iostream

//Global Variable 
string parsedArr[6]; //Holds the original string as segments
string foundArr[6]; //Holds the decimal value of the string
string binStr; //Holds the binary as a string

//Functions

bool FindOp() // Determines which OpCode it is
//Return bool, 1 is successful, 0 is fail
{

Switch(parsedArr[0]){
	case 'add':
		foundArr[5] = 32;
		binStr = 100000;
		return 1;
case 'addu' :
	foundArr[5] = 33;
	binStr = 100001;
	return 1;
case 'and' :
	foundArr[5]=36;
	binStr = 100100;
	return 1;
case 'jr' :
	foundArr[5] =8;
	binStr= 001000;
	return 1;
case 'nor' :	
	foundArr[5]=39;
	binStr= 100111;
	return 1;
case 'or' :	
	founArr[5]= 37;
	binStr= 100101;
	return 1;
case 'slt' :
	founArr[5]= 42;
	binStr= 101010;
	return 1;
case 'sltu' :
	founArr[5]= 43;
	binStr= 101011;
	return 1;
case 'sll' :
	founArr[5]= 0;
	binStr= 000000;
	return 1;
case 'srl' :
	founArr[5]= 2;
	binStr= 000010;
	return 1;
case 'sub' :
founArr[5]= 34;
	binStr= 100010;
	return 1;
case 'subu' :
founArr[5]= 35;
	binStr= 100011;
	return 1;
	default :
		founArr[5]= -1;
	binStr= 222222;
	return 0;
}

}

Int FindR(string reg){ // Determines the registers 

char regName;//Contains letter values of registar
char regNum; //Contains the numbers

switch(reg) {
case ‘zero’
	Return 0; 
case ‘at’
	Return 1;
case ‘gp’
	Return 28;
case ‘sp’
	Return 29;
case ‘fp’
	Return 30;
case ‘ra’
	Return 31; 
}

/* code to separate name and number */
regName = reg[0]; 
regNum = reg[1];

switch(RegName){
case ‘v’($v0-$v1)
	if( 0 < regNum < 1){
		Return 2+RegNum;
	}
case ‘a’
	if( 0< regNum <3 ){
		Return 4+RegNum;
	}
case ‘t’
	if( 0 < regNum < 7){
		Return 8 + RegNum;
	}
case ‘s’
	if( 0 < regNum < 7){
		Return 16+ RegNum;
	}
Case ‘t’
	if( 8 < regnum < 9)
		Return 24 or 25;
case ‘k’
	if( 0< regNum< 1){
		return 26 + RegNum;
	}
}

Return -1; //Failed to find register
}

Void Parser (string str){ //Breaks string into an array
//Loop through “string” till end
//	Store string segments in ParsedString[];

char  * ptr;
Int i = 1;
strcat(“ ”, str);

ptr = strtok(str,’ ‘); //Find first use of spacebar

while( ptr != NULL){ //Go through string str and store each piece in strArr
	parsedArr[i] = ptr;
	ptr = strtok(NULL,’ ‘);
	i++;
	}
return;
}

String IntToBinary( num, size){
bi = 1
int = num
while(int >= bi*2){
	bi*=2;
}
bina = ""
while(int > 0){
	if(int >= bi){
		int -= bi;
		bina += "1";
	} else {
		bina += "0";
	}
	bi /= 2;
}
while(bina.length < size){
	bina = "0" + bina;
}
Returns  bina;
}

Void PrintFunt() {//Prints out Instruction
cout << “operation: “ << parsedArr[0]<< endl;
cout << “Rs: “ << foundArr[1]<< endl;
cout << “Rt: “ << foundArr[2] << endl;
cout << “Rd: “ << foundArr[3]<< endl;
cout << “Shamt: 0“ << endl;
cout << “Funct: “ << foundArr[5]<< endl;
cout << “Machine Code: “ << binStr << endl;
}

Int Main()
{
String input; //takes in user input

cout << "Please provide an R-type instruction." << endl;


//Input String
cin >> input;

Parser(input);//separate string based on space bar

//Pick which variable and print 
if(FindOp() == 0){ //Returns Funct in Dec and in Binary
	cout << "Bad Input: Op" << endl;
	return;
	}

//Shamt(); //append bits to binary
strcat(“00000”, binStr);

//FindR(); //called 3 times for rs, rt, and rd

foundArr[2] = FindR(parsedArr[2]);//rs
if(foundArr[2] == -1){ //Returns Funct in Dec and in Binary
	cout << "Bad Input: rs" << endl;
	return;
	}

foundArr[3] = FindR(parsedArr[3]);//rt
if(foundArr[3] == -1){ //Returns Funct in Dec and in Binary
	cout << "Bad Input: rt" << endl;
	return;
	}

foundArr[4] = FindR(parsedArr[4]);//rd
if(foundArr[4] == -1){ //Returns Funct in Dec and in Binary
	cout << "Bad Input: rd” << endl;
	return;
	}

//IntToBin( integer ,length ); //returns a string to represent binary
strcat(IntToBin( foundArr[4],5 ), binStr);//rd
strcat(IntToBin( foundArr[3],5 ), binStr);//rt
strcat(IntToBin( foundArr[2],5 ), binStr);//rs

//OpCode to Binary
strcat(“00000”, binStr);

//Print Funct
PrintFunct();

return 0;
}

