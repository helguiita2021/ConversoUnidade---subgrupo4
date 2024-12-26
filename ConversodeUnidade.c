#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Função para conversão de massa
void conversorMassa();
double converterMassa(double valor, char unidadeDe[], char unidadePara[]);

// Função para conversão de energia
void ConversorEnergia(){//Função para Converte de Watts para Quilowatts
	float watts,quilowatts;
	printf("Convertendo Watts para Quilowatts:\n");
	printf("Entre com o valor em Watts:");
	scanf("%f",&watts);
	quilowatts = watts/1000;
	printf("O valor em Quilowatts e: %2f \n",quilowatts);
}

// Função principal com menu interativo
int main(){
    int opcao;
    char continuar;

    do { // MENU INTERATIVO
    printf("\n BEM VINDO AO PROGRAMA DE CONVERSÃO DE UNIDADES - EMBARCATECH:\n");
    printf("Escolha qual conversão gostaria de fazer:\n");
    printf(" Digite 1 - Unidades de Comprimento\n");
    printf(" Digite 2 - Unidades de Massa\n");
    printf(" Digite 3 - Unidades de Volume\n");
    printf(" Digite 4 - Unidades de Temperatura\n");
    printf(" Digite 5 - Unidades de Velocidade\n");
    printf(" Digite 6 - Unidades de Energia\n");
    printf(" Digite 7 - Unidades de Área\n");
    printf(" Digite 8 - Unidades de Tempo\n");
    printf(" Digite 9 - Unidades de Dados\n");
    printf(" Digite 10 - Caso deseje Sair do Sistema\n");
    printf(" Informe a sua escolha:\n");
    scanf("%d",&opcao);
    
    switch(opcao){
    	 case 1:
    	 	break;
    	 case 2:
    	 	 conversorMassa();
	    break;
		 case 3:
		    break;
	     case 4:
		    break;
		 case 5:
		    break;
		 case 6:
		     ConversorEnergia();
			break;
		 case 7:
		    break;
	      case 8:
		    break;
		  case 9:
		    break;
		  case 10:
		    return 0;
		  default:
		     printf("Esta opcao não e valida.!\n"); 						  				

    }

    printf("\nDeseja escolher outra opção? (S/N): ");
    scanf(" %c", &continuar); //O espaço antes de %c é necessário para ignorar espaços em branco e realmente ler a variável
    } while ((continuar == 'S') || (continuar == 's'));

    return 0;
    system("PAUSE");

}

// Implementação da função de conversão de massa
double converterMassa(double valor, char unidadeDe[], char unidadePara[]) {
    double fatorDeConversao[7] = {1000.0, 100.0, 10.0, 1.0, 0.1, 0.01, 0.001}; // Fatores para kg, hg, dag, g, dg, cg, mg
    char *unidades[7] = {"kg", "hg", "dag", "g", "dg", "cg", "mg"};

    int indiceDe = -1, indicePara = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(unidadeDe, unidades[i]) == 0) {
            indiceDe = i;
        }
        if (strcmp(unidadePara, unidades[i]) == 0) {
            indicePara = i;
        }
    }

    if (indiceDe == -1 || indicePara == -1) {
        printf("Conversão não suportada.\n");
        return -1.0; // Indica erro
    }

    return valor * (fatorDeConversao[indiceDe] / fatorDeConversao[indicePara]);
}

void conversorMassa() {
    double valor;
    char unidadeDe[10], unidadePara[10];

    printf("\n********************************************\n");
    printf("***         Conversor de Massa           ***\n");
    printf("********************************************\n");
    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    printf("Digite a unidade de origem (kg, hg, dag, g, dg, cg, mg): ");
    scanf("%s", unidadeDe);

    printf("Digite a unidade de destino (kg, hg, dag, g, dg, cg, mg): ");
    scanf("%s", unidadePara);

    double resultado = converterMassa(valor, unidadeDe, unidadePara);

    if (resultado != -1.0) {
        printf("\n%.2lf %s equivalem a %.2lf %s\n", valor, unidadeDe, resultado, unidadePara);
    } else {
        printf("\nConversão inválida. Tente novamente com unidades suportadas.\n");
    }
}
