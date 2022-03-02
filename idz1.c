#include <stdio.h>
long long int f(int x)//от 0 до 1048575(2^20-1)
{
    long long int bin = 0;
    long long int i = 1;
    while(x){
        bin = bin+((x%2)*i);
        i = i * 10;
        x = (x-x%2)/2;
    }
   return bin;
}
int main() {
    int x = 0;
    int i = 0;
    int norm[10000];
    long long int bin[10000];
    char c;
    while ((c = getchar()) != '\n') {
        if(c != ' '){
            x = x*10 + (c - '0');
        }else{
            norm[i] = x;
            bin[i] = f(x);
            i = i + 1;
            x = 0;
        }
    }
    norm[i] = x;
    bin[i] = f(x);
    for(int k=0; k<=(i); k++)
    {
        printf("%d",norm[k]);
        putchar(' ');
    }
    putchar('\n');
    for(int k=0; k<=(i); k++)
    {
        printf("%llu",bin[k]);
        putchar(' ');
    }
    return 0;
}
