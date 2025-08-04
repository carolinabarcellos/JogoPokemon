#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MENOS_EFETIVO 0.8
#define SUPER_EFETIVO 1.2

// Definindo um novo tipo de dado chamado "pokemon"
typedef struct pokemon{
		char nome[50];
		float ataque;
		int defesa;
		float vida;
		char tipo[10];
	}pokemon;


//Simulando diferentes situações nas batalhas. O pk1 está atacando o pk2.

float batalhas_pokemons(pokemon pk1, pokemon pk2){

	if ((strcmp(pk1.tipo, "agua")==0) && (strcmp(pk2.tipo, "eletrico")==0)){
		return pk1.ataque*MENOS_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "agua")==0) && (strcmp(pk2.tipo, "fogo")==0)){
		return pk1.ataque*SUPER_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "eletrico")==0) && (strcmp(pk2.tipo, "pedra")==0)){
		return pk1.ataque*MENOS_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "eletrico")==0) && (strcmp(pk2.tipo, "agua")==0)){
		return pk1.ataque*SUPER_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "pedra")==0) && (strcmp(pk2.tipo, "gelo")==0)){
		return pk1.ataque*MENOS_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "pedra")==0) && (strcmp(pk2.tipo, "eletrico")==0)){
		return pk1.ataque*SUPER_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "fogo")==0) && (strcmp(pk2.tipo, "agua")==0)){
		return pk1.ataque*MENOS_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "fogo")==0) && (strcmp(pk2.tipo, "gelo")==0)){
		return pk1.ataque*SUPER_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "gelo")==0) && (strcmp(pk2.tipo, "fogo")==0)){
		return pk1.ataque*MENOS_EFETIVO;
	}
	if ((strcmp(pk1.tipo, "gelo")==0) && (strcmp(pk2.tipo, "pedra")==0)){
		return pk1.ataque*SUPER_EFETIVO;
	}
	else{
		return pk1.ataque*1;
	}
}

int main(){
	
	//abrindo o arquivo e escolhendo o modo read
	FILE *arq;
	arq=fopen("arquivotrabalhopratico.txt", "r");
	
	if (arq == NULL) { //Em caso de erro ao abrir o arquivo. O programa deve finalizar. A função main retornará 1 nesse caso.
        printf("Erro ao abrir o arquivo.\n");
        fclose(arq);
        return 1;
    }
	
	int M=0, N=0;
	
	/* Retirando do arquivo as informações sobre a quantidade de pokemons por jogador, sendo 
	"N" a quantidade relativa ao jogador 1 e "M" a quantidade relativa ao jogador 2.
	*/
	char linha[100];
	fgets(linha, 100, arq);
	N=atoi(strtok(linha, " "));
	M=atoi(strtok(NULL, " "));
	
	if ((N>0 && N<=MAX)&&(M>0 && M<=MAX)){
		printf( "%d %d\n", N, M);
	}
	
	//No caso de N e/ou M não seguirem as regras. O programa deve finalizar. A função main retornará 1 nesse caso.
	else{
		printf("A quantidade de pokémons por jogador deve ser um número inteiro positivo de 1 a 100.\n");
		fclose(arq);
		return 1;
	}
	
	// Declarando dois vetores do tipo pokemon, utilizando alocação dinâmica de memória para evitar o uso excessivo de memória e lentidão.
	pokemon *pokemons_jogador_1=(pokemon *)malloc(N*sizeof(pokemon));
	pokemon *pokemons_jogador_2=(pokemon *)malloc(M*sizeof(pokemon));
	
	//Declarando duas variáveis que serão utilizadas para controlar os índices dos vetores pokemons_jogador_1 e pokemons_jogador_2;
	int jogador_atual1=0, jogador_atual2=0;
	
	int i=0;
	
	//Lendo e imprimindo na tela os dados de cada pokemon.
	for (i=0; i<N; i++){
		fscanf(arq, " %s %f %d %f %s", pokemons_jogador_1[i].nome, &pokemons_jogador_1[i].ataque, &pokemons_jogador_1[i].defesa, &pokemons_jogador_1[i].vida, pokemons_jogador_1[i].tipo);
		printf("%s %f %d %f %s\n", pokemons_jogador_1[i].nome, pokemons_jogador_1[i].ataque, pokemons_jogador_1[i].defesa, pokemons_jogador_1[i].vida, pokemons_jogador_1[i].tipo);
		
	}
		
	for (i=0; i<M; i++){
		fscanf(arq, " %s %f %d %f %s", pokemons_jogador_2[i].nome, &pokemons_jogador_2[i].ataque, &pokemons_jogador_2[i].defesa, &pokemons_jogador_2[i].vida, pokemons_jogador_2[i].tipo);
		printf( "%s %f %d %f %s\n", pokemons_jogador_2[i].nome, pokemons_jogador_2[i].ataque, pokemons_jogador_2[i].defesa, pokemons_jogador_2[i].vida, pokemons_jogador_2[i].tipo);
		
	}
	printf("\n");
	
	//Fechando o arquivo.
	fclose(arq);
	
	//Criando duas strings: sobreviventes e derrotados, onde serão adicionados os nomes dos pokemons em suas respectivas categorias.
	char sobreviventes[1000]="";
	char derrotados[1000]="";
	
	//Criação da variável ataque_final_jogador1 e da variável ataque_final_jogador2, para armazenar os valores do poder de ataque dos pokemons após aplicar a função "batalhas_pokemons"
	float ataque_final_jogador1, ataque_final_jogador2;
	
	//
	int atacante=1;
				
	do{
		
		if (atacante==1){
			ataque_final_jogador1=batalhas_pokemons(pokemons_jogador_1[jogador_atual1],pokemons_jogador_2[jogador_atual2]);
			
			if (ataque_final_jogador1 > pokemons_jogador_2[jogador_atual2].defesa){
							
				pokemons_jogador_2[jogador_atual2].vida -= (ataque_final_jogador1- pokemons_jogador_2[jogador_atual2].defesa);
				
			}
			else if (ataque_final_jogador1 <= pokemons_jogador_2[jogador_atual2].defesa){
								
				pokemons_jogador_2[jogador_atual2].vida -= 1;
			}
				
			if (pokemons_jogador_2[jogador_atual2].vida<=0){
				printf("%s venceu %s\n", pokemons_jogador_1[jogador_atual1].nome, pokemons_jogador_2[jogador_atual2].nome); 
				strcat(derrotados, pokemons_jogador_2[jogador_atual2].nome);
				strcat(derrotados, "\n");
				jogador_atual2=jogador_atual2+1;

			}
			atacante=2;
		}
						
		else if (atacante==2){
			ataque_final_jogador2=batalhas_pokemons(pokemons_jogador_2[jogador_atual2], pokemons_jogador_1[jogador_atual1]);
			
			if (ataque_final_jogador2 > pokemons_jogador_1[jogador_atual1].defesa){
					
				pokemons_jogador_1[jogador_atual1].vida -= (ataque_final_jogador2 - pokemons_jogador_1[jogador_atual1].defesa);
					
			}
			else if (ataque_final_jogador2 <= pokemons_jogador_1[jogador_atual1].defesa){
				pokemons_jogador_1[jogador_atual1].vida -= 1;
			}
				
			if (pokemons_jogador_1[jogador_atual1].vida<=0){
				printf("%s venceu %s\n", pokemons_jogador_2[jogador_atual2].nome, pokemons_jogador_1[jogador_atual1].nome); 
				strcat(derrotados, pokemons_jogador_1[jogador_atual1].nome);
				strcat(derrotados, "\n");
				jogador_atual1=jogador_atual1+1;

			}
			atacante=1;
		}
			
	}while (!(jogador_atual2>=M ||jogador_atual1>=N));
		
	
	//Verificar o jogador vencedor e imprimir o resultado na tela.
	if (jogador_atual1==N){
		printf("Jogador 2 venceu\n");
	}
	else{
		printf("Jogador 1 venceu\n");
	}
						
	//Criar a lista com os nomes dos pokémons sobreviventes, caso o Jogador 2 tenha vencido.
	if (jogador_atual1==N){
		for (i=0;jogador_atual2+i<M;i++){
			strcat(sobreviventes, pokemons_jogador_2[jogador_atual2+i].nome);
			strcat(sobreviventes, "\n");
		}
	}
	
	//Criar uma lista com os nomes dos pokémons sobrevivientes, caso o Jogador 1 tenha vencido.
	else{
		for (i=0;jogador_atual1+i<N;i++){
			strcat(sobreviventes, pokemons_jogador_1[jogador_atual1+i].nome);
			strcat(sobreviventes, "\n");
		}
	}
	
	printf("Pokémons sobreviventes:\n");
	printf("%s", sobreviventes);
	printf("Pokémons derrotados:\n");
	printf("%s\n", derrotados);
	
	free(pokemons_jogador_1);
	free(pokemons_jogador_2);
	
	return 0;
}
