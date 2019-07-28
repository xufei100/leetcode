#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int getNum(char c )
{
    switch (c) {
     case 'I': return 1;
     case 'V': return 5;
     case 'X': return 10;
     case 'L': return 50;
     case 'C': return 100;
     case 'D': return 500;
     case 'M': return 1000;
   }
   return 0;
}


int romanToInt(char *s)
{
    int i = 0;
    int result = 0;
    int previous = 0;
    bool add = true;
    for (i = 0; s[i] != '\0'; i++)
    {
        int current = getNum(s[i]);
        if (i >=1 && current > previous) {
            result = result + current - 2*previous;
	}else {
            result = result + current;
        }
        previous = current;
    }
    return result;
}


int main()
{
    char str[10];
    char *s = str;
    strcpy(str,"III");
    printf("III to int %d \n", romanToInt(s));
    strcpy(str,"IV");
    printf("IV to int %d\n", romanToInt(s));
    strcpy(str,"IX");
    printf("IX to int %d\n", romanToInt(s));
    strcpy(str,"LVIII");
    printf("LVIII to int %d\n", romanToInt(s));
    strcpy(str,"MCMXCIV");
    printf("MCMXCIV to int %d\n", romanToInt(s));
   
}
