# RNG RPG

RNG RPG é um jogo de RPG baseado em turnos, onde a sorte desempenha um papel crucial em todas as ações. Prepare-se para enfrentar monstros, coletar itens e subir de nível, tudo isso enquanto escolhe as melhores estratégias para sobreviver.


## Funcionalidades
 * Criação de Personagem: O jogador pode criar um personagem escolhendo o nome, idade, sexo, raça e classe.
 * Combate: O jogo possui um sistema de combate por turnos onde o jogador pode atacar fisicamente, atacar magicamente ou se defender contra monstros gerados aleatoriamente.
 * Geração de Itens: Itens são gerados aleatoriamente com diferentes bônus e podem ser equipados pelo jogador para melhorar seus atributos.
 * Sistema de Nível: O jogador sobe de nível após derrotar monstros, aumentando seus atributos básicos.
 * Sistema de Nível dos Monstros: A dificuldade do monstro sobe após o anterior ter sido derrotado, aumentando seus atributos básicos.
 * Inventário: O jogo possui um inventário onde o jogador pode armazenar e gerenciar seus itens.


Estrutura do Código
Arquivo Principal (main.cpp)
O arquivo principal contém a lógica do jogo, incluindo a criação do personagem, combate, geração de itens e gerenciamento do inventário.
Classes e Arquivos de Cabeçalho

* ## Classe "classe":
   * Define os atributos ***(Vida,ataque fisico,ataque magico,resistência física,resistência magica)*** e métodos relacionados às classes dos personagens. As classes incluem:
   * Mago
   * Guerreiro
   * Ladino
   * Tanker
* ## Classe "Personagem":
  * Define os atributos e métodos relacionados aos personagens do jogo, incluindo:
  * Nome
  * Idade
  * Sexo
  * Raça
  * Classe 
  * Métodos para atacar fisicamente, atacar magicamente e defender.

* ## Classe "item":
  * Define os atributos e métodos relacionados aos itens do jogo, incluindo:
  * Nome
  * Bônus de vida
  * Bônus de ataque físico
  * Bônus de ataque mágico
  * Bônus de resistência física
  * Bônus de resistência mágica

* ## Classe "GeradorDeEntidades":
  * Responsável por gerar monstros e itens aleatórios. Inclui listas de nomes e adjetivos para criar combinações únicas de itens e monstros.
  
* ## Classe "Inventario":
  *Cria um inventario onde vão ser guardados os itens obtidos.
  *Dê a opção para o usario apagar os itens.
   

> Notas : 

> O jogo utiliza system("cls") para limpar a tela no Windows e system("clear") para sistemas Unix.
> Os atributos dos personagens aumentam em 2 pontos ao subir de nível.
> Os atributos do monstros são gerados aleatoriamente, mas o nível de dificuldade multiplica os atributos continuamente.
> A defesa aumenta a resistência temporariamente e é resetada no próximo turno de ataque.
> Divirta-se jogando RNG RPG e que a sorte esteja ao seu lado!






