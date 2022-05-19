#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cutfuncs.h"
#define MAX 100
//main with parameters of # of args and arg strings from command line
//checks for errors when calling function, then inserts fields into array.
//then calls function to print the fields.
int main (int argc, char *argv[]) {

	//check for invalid input from user.
	int error= errorCheck(argc, argv, MAX);//variable that holds return value from function. returns 1 if error,else 0
	if(error==1)
	{
		printf("%s: specify input_delimiter output_delimiter and 1-%d fields in order\n",argv[0],MAX);
		exit(1);
	}	

	char line[100];
	//iterate through each line from stdin file	
	while(fgets(line, sizeof line, stdin)) 
	{          
	     char *element;//variable for element per line in text file
	     char *org=strdup(line);//variable to use current line
	     char *array[1000];//array to hold strings for fields of each line
	     int i=0;//index value to add fields from line to array
	     int count =0;//int variable to keep track of array's length

	     //store elements (split from input delimiter) into array
	     while ((element=strsep(&org,argv[1]))!=NULL)
		{
			array[i++]=element;
			count++;
		}
	     //print fields from array
	     printLine(argc,argv,array,count,argv[2][0]);
	      
	     //clear array for next line in file
	    for(int i=0;i<100;i++)
		{	
			array[i]=NULL;
		} 
	}
	exit(0);
}
