#include<stdio.h>
#include<stdlib.h>
int main() 
{
	printf("ÇëÊäÈë¼üÅÌ×Ö·û£º");
 char ch;
 while ((ch = getchar()) !=' ') 
 {
	 if (ch >= 'A'&&ch <= 'Z') 
  {        
   putchar(ch + 32);
   printf("\n");
  }
  	 else if (ch >= 'a'&&ch <= 'z') 
  {    
	  putchar(ch - 32);
	  printf("\n");
  }                
 }
 system("pause");
 return 0;
}
