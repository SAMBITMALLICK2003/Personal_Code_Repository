#include <iostream>
using namespace std;

char* xstrcpy(char *dest, char *src){
    while(*src){
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return dest;
}
char* xstrcat(char *dest,char *src)
{
    char *start=dest;
    while(*dest)
    {
        dest++;
    }
    while(*src)
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}
int xstrcmp(char* str1, char* str2){
    while(*str1 && *str2){
        if(*str1!=*str2){
            return *str1-*str2;
        }
        str1++;
        str2++;
    }
    return 0;
}
void xstrswap(char* str1, char* str2){
    char temp[100];
    xstrcpy(temp,str1);
    xstrcpy(str1,str2);
    xstrcpy(str2,temp);
}
int main() {
    char *dest = new char[100];
    char*src = new char[100];
    cout<<"Enter dest string: ";
    cin.getline(dest,100);
    cout<<"Enter src string: ";
    cin.getline(src,100);
    cout<<"string before copying: "<<dest<<endl;
    xstrcpy(dest,src);
    cout<<"string after copying: "<<dest<<endl;
    return 0;
}