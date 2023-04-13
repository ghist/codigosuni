#include <stdio.h>

int main(){
	char regiao;
	int escolha;
	
	scanf("%c", &regiao);
	
	switch(regiao){
		
		case 'a' :
			scanf("%d", &escolha);
			if(escolha == 0){
				printf("R$ 500.00");
			}if (escolha == 1){
				printf("R$ 900.00");
			}
		break;
		
		case 'b' :
			scanf("%d", &escolha);
			if(escolha == 0){
				printf("R$ 350.00");
			}if (escolha == 1){
				printf("R$ 650.00");
			}
		break;
		
		case 'c' :
			scanf("%d", &escolha);
			if(escolha == 0){
				printf("R$ 350.00");
			}if (escolha == 1){
				printf("R$ 600.00");
			}
		break;
		
		case 'd' :
			scanf("%d", &escolha);
			if(escolha == 0){
				printf("R$ 300.00");
			}if (escolha == 1){
				printf("R$ 550.00");
			}
		break;
			
	}
	return 0;
}
