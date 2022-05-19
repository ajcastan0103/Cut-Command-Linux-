#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//function to check errors. 
//parameters of # of arguments, argument strings and the max # of fields
//returns 1 if error is encountered, otherwise return 0
int errorCheck(int argc, char *argv[], int MAX)
{
	//check if there is suffient amount of arguments
	if(argc<4)
	{	
		return 1;
	}
	//check if input and output delimiters are of length 1
	if(strlen(argv[1])!=1)
	{
		return 1;
	}
	if( strlen(argv[2])!=1)
	{
		return 1;
	}	
	//loop checks if all fields are digits and between 1 and 100
	for(int i=3;i<argc;i++)
	{
		//checks if all characters per field are digits
		for(int j=0;j<strlen(argv[i]);j++)
		{
			if(isdigit(argv[i][j])==0)
			{
				return 1;
			}
		}
		//check if number field is between 1 and 100
		int argval=atoi(argv[i]); 
		if(argval>MAX)
                { 
                    return 1;
                }
                if(argval<1)
                {
                    return 1;
                }
		
	}
	//check if fields are in increasing order
	if(argc>4)
	{
	   for(int i=3;i<argc;i++)
	   {
		int elem=atoi(argv[i]);
		if(i!=argc-1)
		{
			int nextelem= atoi(argv[i+1]);
			//check if next field is less than current field
			if(elem>nextelem)
			{
				return 1;
			}
			//check if there are duplicate fields
			if(elem==nextelem)
			{
				return 1;
			}
		}
	   }
	}
	return 0;
}
//function to print fields.
//parameters of # of arguments, string arguments, array of fields, size of array and ouput delimiter.
void printLine(int argc, char *argv[],char *array[], int count, char outdelim)
{
	 int existline=0;
	//iterate arguments
         for(int i=3;i<argc;i++)
         {
               int argval=atoi(argv[i]);
               int index=argval -1;
	       //if a field matches with the length of the array,
	       //a new line prints. This "if" statement checks this and if it does exist,     
	        //printing a second new line will be avoided.
               if(argval==count)
                {
                    existline=1;
                 }
                //check if field exists in array to print.
                 //if not, break the loop
  	         if(index>count)
                {
          	   break;
	        }
		//prints existing element in array
       	        if(array[index]!=NULL)
                 {
                      printf("%s",array[index]);
                  }
		//checks next array[argument] to see if the field exists.
		//if so, print the output delimiter as it expects the next field.
                   if(i!=argc-1)
                  {
                       int nextarg=atoi(argv[i+1]);
                       int plusindex=nextarg-1;
                       if(array[plusindex]!=NULL&&plusindex<count)
                       {
                            printf("%c",outdelim);
                       }

                   }

                }
      if(existline!=1)
       {
          printf("\n");
       }

} 
