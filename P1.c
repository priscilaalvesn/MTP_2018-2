/*P1.c*/
/*Nome: Priscila Alves Nunes*/
/*Matrícula: 11811EBI010*/

#include <stdio.h>

int main ()
{
	int estado = 0, i = 0;
	char bits[256];
	printf("Digite um numero binario: ");
	scanf("%s", &bits);
	while(bits[i] != '\0')
	{
		if(bits[i] == '0')
		{
			if(estado == 0);
			else if(estado == 1)
				estado = 2;
			else if(estado == 2)
				estado =1;
				i++;	
		}
		else if(bits[i] == '1')
		{
			if(estado == 0)
				estado = 1;
			else if (estado == 1)
				estado = 0;
			else if( estado == 2);
				i++;
		}
		else
		{
			printf ("O numero nao e binario");
			return 0;
		} 
	}
	
	if(estado == 0)
			printf("%s eh multiplo de 3", bits);
		else
			printf("%s nao eh multiplo de 3", bits);
		return 0;
}
