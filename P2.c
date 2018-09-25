#include <stdio.h>

int main()
{
	int opcao, convert[100];
	char bin[256], bin1[256], bin2[256];
	int valor, i=0, desloca, j,d, k=0, aux=0, l, pot=1, decimal=0, cont=0, x=1, b=0, z, n_convert=0;

	printf("\nConversoes de bases numericas.\n");
	printf("1- Binario para decimal\n");
	printf("2- Binario para hexadecimal\n");
	printf("3- Hexadecimal para decimal\n");
	printf("4- Hexadecimal para binario\n");
	printf("5- Decimal para binario\n");
	printf("6- Decimal para hexadecimal\n");
	printf("7- Octal para decimal\n");
	printf("8- Decimal para octal\n");
	printf("\nInforme a opcao desejada: ");
	scanf("%d", &opcao);
	getchar();

   switch(opcao)
{

   	case 1:
   		printf("\nDigite o numero binario a ser convertido: ");
   		scanf("%s", bin);
   		getchar();
   		while (bin[k]!='\0'){
   			k++;
   			aux++;
		   }
		  l = aux - 1;
		  for( k=0; k<aux; k++, l--){
		  	bin1[l] = bin[k];
		  }
		  for( l=1; l<aux; l++){
		  	pot=pot*2;
		  	if(bin1[l] == '1')
		  	decimal = decimal + pot;
		  }
		  if(bin1[0] == '1') {
		  
		  decimal = decimal  + 1;
		  printf("\nNumero em decimal e: %d ", decimal);}
		  break;
		  
      case 2:
	   printf("\nDigite o numero binario a ser convertido: ");
	   scanf("%s", bin2);
	   getchar();
	   for( cont = 0; bin2[cont]!= '\0'; cont++);
	   cont--;		   
	   for( z = cont; z >= 0 ; z--)
	  {
	  
		if(bin2[z] == '0')
		
		convert[z] = 0;
		else if( bin2[z] == '1')
		convert[z] = 1; 
		}
		b = cont;
		while( b >= 0)
		{
			while( x <= cont - b)
			{
				convert[b] *=2;
				x++;
			}
		
		n_convert += convert[b];
		x = 1;
		b--;
        }
	  printf("\nNumero em hexadecimal e: %x", n_convert);
	  
	  break;
	  
		   
   		
   		 
     case 3: 
    	printf("\nDigite o numero hexadecimal a ser convertido: ");
		scanf("%x", &valor);
		getchar();
		printf("%x em decimal e: %d ", valor, valor);
        break;
        case 4:
    	printf("\nDigite o numero hexadecimal a ser convertido: ");
    	scanf("%x", &valor);
    	getchar();
    	for (j = 14; j >= 0; j--) 
    	{
    		d = valor >> j;
    		if( d & 1)
    		{
    			printf("1");
			} else printf("0");
		}
		break;
    
    case 5:
    printf("\nDigite o numero decimal a ser convertido: ");
    scanf("%d", &valor);
    getchar();
    for (i = 9; i>=0; i-- )
    {
    	desloca = valor >> i;
    	if( desloca & 1){
    		printf("1");
		}else { printf("0");
		}
	}
	break;
    case 6:
	
		printf("\nDigite o numero em decimal a ser convertido: ");
		scanf("%d", &valor);
		getchar();
		printf("%d em hexadecimal e %x ", valor, valor);
	break;
	case 7:
	printf("\nDigite o numero em octal a ser convertido: ");
	scanf("%o", &valor);
	getchar();
	printf("%o em decimal e: %d", valor, valor);
	break;
	case 8:
		printf("\nDigite o valor em decimal a ser convertido: ");
		scanf("%d", &valor);
		getchar();
		printf("%d em octal eh: %o", valor, valor );
		break; }

return 0;
}
