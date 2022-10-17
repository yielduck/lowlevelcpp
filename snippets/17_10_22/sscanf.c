#include <stdio.h>

int main()
{
    int x, y;
    char s[] = "(10, 20)";
    int result = sscanf(s, "(%i, %i)", &x, &y);
    printf("%i; %i\n", result, x + y);
}
