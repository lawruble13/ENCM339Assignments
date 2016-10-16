// line-getter4D.c
// ENCM 339 Fall 2016 Lab 4 Exercise D

#include <stdio.h>
#include <string.h>

#define QUIT_LETTER 'q'

// Again, in a practical program, this is a ridiculously small size
// for an array that is supposed to hold a line of text. But it's
// convenient for testing purposes.
#define LINE_ARRAY_SIZE 8

int eat_til_newline(FILE *stream);
// REQUIRES: stream is open for input.
// PROMISES: Characters are read from stream and discarded until either a
//   '\n' has been read or an input error has occurred.
//   Return value is 0 if '\n' is read, and EOF for an error.

int get_a_line(char *s, int size, FILE *stream);
// Does what fgets does, using repeated calls to fgetc, but
// provides a more useful return value than fgets does.
//
// REQUIRES
//   size > 1. 
//   s points to the start of an array of at least size bytes.
//   stream is open for input.
// PROMISES
//   Return value is EOF if input error occurred.
//   Otherwise, return value gives the index of the '\0' that
//   terminates the string in the array.

void reverse(char *s);
//REQUIRES: s points to a valid C string
//PROMISES: string at location s will be reversed in place.

int main(void)
{
  char line[LINE_ARRAY_SIZE];
  int input_error = 0;

  while (1) {
    printf("Please enter a line of text. To quit, start it with %c.\n",
	   QUIT_LETTER);
    
    int val=get_a_line(line,LINE_ARRAY_SIZE,stdin);
    
    if (val == EOF) { 
      // Case 3 or 4 (Input error.)
      input_error = 1;
      break;
    }
    if (line[0] == QUIT_LETTER)
      break;

    // If val is the size-1, then the string was too long. Otherwise, 
    // it's fine.
    if(val == LINE_ARRAY_SIZE-1){
	eat_til_newline(stdin);
	fputs("Input line ignored because it was too long!\n",stdout);
    } else {
	printf("The line, newline removed, was \"%s\".", line);
	reverse(line);
	printf("   In reverse, that is \"%s\".\n",line);
    }
  } // while (1)

  fputs("\nReason for quitting: ", stdout);
  if (input_error)
    fputs("unexpected input error.\n", stdout);
  else
    printf("found %c at beginning of line.\n", QUIT_LETTER);

  return 0;
}

int get_a_line(char *s, int size, FILE * stream){
/*	Strips newline from string read, replaces with '\0'. Therefore, 
	the index of '\0' will be size-1 only for a string too long for
	the given array. Otherwise, it will be size-2 or less.
*/
	char c;
	int i;
	for(i=0;i<size-1;i++){
		c=fgetc(stream);
		if(EOF == c){
			s[i]='\0';
			return EOF;
		}
		s[i] = c;
		if(c == '\n') break;
	}
	if(s[i] == '\n') s[i]='\0';
	s[i]='\0';
	return i;
}

int eat_til_newline(FILE * stream)
{
  int c;
  do {
    c = fgetc(stream);
  } while (c != EOF && c != '\n');
  
  // Return EOF if c == EOF, otherwise return 0.
  return (c == EOF) ? EOF : 0;
}

void reverse(char *s)
{
	char *f=s+strlen(s)-1, *b=s;
	char t;
	while (f > b){
		t=*f;
		*f--=*b;
		*b++=t;
	}
}
