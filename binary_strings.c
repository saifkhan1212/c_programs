#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program generates all possible string patterns
// based on the string pattern it gets as an input from 
// command line.

//  this function generates all possible patterns recursivly.
// for every x or X, 1 and 0 is placed and a result generate new pattern.
// if the index which starts from 0 becomes equal to size of pattern then
// we print the pattern as all x have been replaced by 0 or 1.

// Parameters? there are two parameters. pattern array contains the basic
// pattern that is taken as input. and in recursive calls it will contain
// the pattern array. the second parameter is index. index is basically a helper
// variable which help us to traverse pattern from index 0. and recursively 
// generate patterns as we move with index.

// returns? it does not return anything. it jsut prints the patterns
// instead of returning them.

void Genrate_String(char pattern[], int index)
{
  if (index == strlen(pattern))
  {
    printf("%s\n",pattern);
    return;
  }

  if (pattern[index] == 'x' || pattern[index]=='X')
  {
    pattern[index] = '0';
    Genrate_String(pattern, index + 1);

    pattern[index] = '1';
    Genrate_String(pattern, index + 1);

    pattern[index]='x';
  }
  else
    Genrate_String(pattern, index + 1);
}



// What it does? this function calls its helper function Genrate_String and
// Genrate_String function does all the work.

// Parameters? there is only single parameter which is pattern array. the 
// pattern array contains the pattern taken as input from user.

// What it returns? it does not return anything. 

void Genrate_Binary_Strings(char pattern[])
{
  Genrate_String(pattern,0);
}

int main(int argc,char *argv[])
{
  Genrate_Binary_Strings(argv[1]);
  return 0;
}