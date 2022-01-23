#include <stdio.h>
int main(int argc, char *argv[], char *env[])
{
int t;
for(t=0; env[t]; t++)
printf("%s\n", env[t]);
return 0;
}