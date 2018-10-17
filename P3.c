/*P3.c*/
/*Nome: Priscila Alves Nunes*/
/*Matrícula: 11811EBI010*/

#include <stdio.h>

long long int eleva(int base, int exp)
{
  int result=1;
  for(;exp>0;exp--)
  {
    result*=base;
  }
  return result;
}

int main()
{
  int i,j=0,k;
  unsigned long long int numero=0;
  char str[256];
  printf("Digite a string: \n");
  scanf("%s",str);
  for(k=0;str[k]!='\0';k++);
  for(;k>=0;k--)
  {
    if(str[k]>=48 && str[k]<=57)
	{
      numero+=(str[k]-48)*(eleva(10,j));
      j++;
    }
  }
  printf("\nO resultado e: %lld",numero);
}
