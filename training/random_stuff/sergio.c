#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
	char modelo[50];
	char fabrica[50];
	int ano;
	float cons;
} Carro;



int main (){

	Carro reg[100];

	for (int i = 0; i < 100; ++i)
	{
		reg[i].ano = 0;
		reg[i].cons = 0;
	}

	char mod[50], fab[50], fab2[50], sele;
	int a = 0, r = 0, aux = 0, novo = 0;
	float b = 0, eco = 0 , beb = 0;

	

	do{
		a = 0;
		r = 0;
		aux = 0;
		b = 0;
		do{
			scanf("%c",&sele);
		}while(sele < 'a' || sele > 'g');

		switch (sele){
			case 'a':
				gets(mod);
				gets(fab);
				scanf("%d",&a);
				scanf("%f",&b);
				if (eco < b)
				{
					eco = b;
					
				}
				if (beb == 0)
				{
					beb = b;
					
				}
				else{
					if (beb > b)
					{
						beb = b;
					}
				}
				
				if(novo < a)
				{
					novo = a;
				}
				for (int i = 0; i < 100; ++i)
				{
					if (reg[i].ano == 0)
					{
						strcpy(reg[i].modelo,mod);
						strcpy(reg[i].fabrica,fab);
						reg[i].ano = a;
						reg[i].cons = b;
						break; 
					}
				}
				break;
			case 'b':
						scanf("%d", &r);
						strcpy(reg[r].modelo,"\0");
						strcpy(reg[r].fabrica,"\0");
						reg[r].ano = 0;
						reg[r].cons = 0;
						break; 
				break;
			case 'c':
				gets(fab2);
				for (int i = 0; i < 100; ++i)
					{
						aux = strcmp(reg[i].fabrica ,fab2);
						if (aux == 0)
						{
							printf("%s\n",reg[i].modelo);
							printf("%s\n",reg[i].fabrica);
							printf("%d\n",reg[i].ano);
							printf("%f\n",reg[i].cons); 
						}
					}
				break;
			case 'd':
				for (int i = 0; i < 100; ++i)
					{
						if (reg[i].cons == eco)
						{
							printf("%s\n",reg[i].modelo);
							printf("%s\n",reg[i].fabrica);
							printf("%d\n",reg[i].ano);
							printf("%f\n",reg[i].cons); 
							break; 
						}
					}
				break;
			case 'e':
				for (int i = 0; i < 100; ++i)
					{
						if (reg[i].cons == beb)
						{
							printf("%s\n",reg[i].modelo);
							printf("%s\n",reg[i].fabrica);
							printf("%d\n",reg[i].ano);
							printf("%f\n",reg[i].cons); 
							break; 
						}
					}
				break;
			case 'f':
			for (int i = 0; i < 100; ++i)
					{
						if (reg[i].ano == novo)
						{
							printf("%s\n",reg[i].modelo);
							printf("%s\n",reg[i].fabrica);
							printf("%d\n",reg[i].ano);
							printf("%f\n",reg[i].cons); 
							break; 
						}
					}
				break;
				case 'g':
				break;
		}



	}while(sele != 'g');

	


	return 0;
}
