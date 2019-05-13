#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char rChar = rand()%128;
    while(rChar < 31 || rChar > 126 || (rChar > 64 && rChar < 91)){
        rChar = rand()%128;
    }
    return rChar;
}

char *inputString()
{
    char rChar = rand()%123;
    int rItr = 5;
    char* in = (char*) malloc((rItr+1)*sizeof(char)); /*+1 for '\0' character */

    for(int i = 0; i < rItr; i++){
        in[i] = '\0';
    }

    for(int i = 0; i < rItr; i++){
        while((rChar != 114) && (rChar != 115) && (rChar != 116) && (rChar != 101)){
            rChar = rand()%117;
        }
        in[i] = rChar;
        rChar = rand()%1117;
    }    
    printf("string: %s\n", in);
    return in;
}

void testme()
{
  int tcCount = 0; 
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
