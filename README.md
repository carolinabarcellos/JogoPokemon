# Jogo de Batalhas de Pokémons

Este projeto implementa um jogo de batalhas entre Pokémons de dois jogadores, desenvolvido como parte de um trabalho prático para a disciplina Programação e Desenvolvimento de Software 1 da UFMG.

## Descrição do Problema

O jogo consiste em uma batalha entre dois jogadores, cada um possuindo de 1 a 100 Pokémons. Cada Pokémon é caracterizado por:

- Nome (string)  
- Tipo (string)  
- Poder de ataque (float)  
- Poder de defesa (int)  
- Vidas (float)  

Alguns Pokémons ganham ou perdem força dependendo do tipo do adversário. Por exemplo:

- Pokémon do tipo **água** aumenta seu poder de ataque em 20% quando batalha contra Pokémon do tipo **fogo**.  
- Pokémon do tipo **água** reduz seu poder de ataque em 20% contra Pokémon do tipo **elétrico**.

## Regras da Batalha

- O primeiro Pokémon do Jogador 1 ataca o primeiro Pokémon do Jogador 2 inicialmente.  
- Se o poder de ataque do atacante for maior que o poder de defesa do defensor, o defensor perde uma quantidade de vidas equivalente à diferença entre esses poderes. Caso contrário, o defensor perde 1 vida.  
- Quando um Pokémon perde todas as suas vidas (vidas ≤ 0), ele é derrotado e substituído pelo próximo Pokémon do seu jogador.  
- A batalha continua alternando o ataque entre os Pokémons envolvidos até que um deles seja derrotado.  
- O jogo termina quando todos os Pokémons de um dos jogadores forem derrotados.

## Entrada

O programa recebe como entrada um arquivo `.txt` contendo:

- A primeira linha com a quantidade de Pokémons de cada jogador.  
- As linhas seguintes contendo as informações de cada Pokémon em pares (um do Jogador 1 e um do Jogador 2), na ordem:  
  `Nome Ataque Defesa Vidas Tipo Nome Ataque Defesa Vidas Tipo`

### Exemplo de entrada

1 1
Squirtle 10 15 15 agua Vulpix 15 15 15 fogo

### Exemplo de saída

Squirtle venceu Vulpix Jogador 1 venceu Pokémons sobreviventes: Squirtle
Pokémons derrotados: Vulpix

## Considerações

Este projeto foi feito na linguagem C e explora conceitos de simulação, estruturas de dados para controle dos Pokémons, e lógica condicional baseada em tipos para determinar efeitos de vantagem/desvantagem em batalhas.

