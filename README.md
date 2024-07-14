
<div align="center">
<img src="https://github.com/VitorLionAmaral/Text_RPG_C-_UFMG/assets/163683980/319bb27e-2823-48c3-b37c-55ea02f5d981" width="300px" />
</div>

# RNG RPG

> dificuldades : **A entrega parcial foi feito inteiramente por 2 pessoas, Vitor Leão Amaral e Matheus Alberto dos Santos Rodrigues**.
> Comentários de finalização do projeto: esse projeto teve pequenas contribuições de João Victor Cirilo referente a tratativas de erros e diretrizaes do jogo

RNG RPG é um jogo de RPG baseado em turnos, onde a sorte desempenha um papel crucial em todas as ações. Prepare-se para enfrentar monstros, coletar itens e subir de nível, tudo isso enquanto escolhe as melhores estratégias para sobreviver.


## Funcionalidades
 * Criação de Personagem: O jogador pode criar um personagem escolhendo o nome, idade, sexo, raça e classe.
 * Combate: O jogo possui um sistema de combate por turnos onde o jogador pode atacar fisicamente, atacar magicamente ou se defender fisicamente e defender magicamente contra monstros gerados aleatoriamente.
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
Status Inicias
Vida:60
Ataque fisico: 30
Ataque Magico: 150
Resistencia Fisica: 10
Resistencia mágica: 20
   * Guerreiro
Status Inicias
Vida: 150
Ataque fisico: 60
Ataque Magico: 20
Resistencia Fisica: 20
Resistencia mágica: 10
   * Ladino
Status Inicias
Vida: 80
Ataque fisico: 150
Ataque Magico: 20
Resistencia Fisica: 10
Resistencia mágica: 10
   * Tanker
Status Inicias
Vida:200
Ataque fisico: 30
Ataque Magico: 30
Resistencia Fisica: 15
Resistencia mágica: 15

* ## Classe "Personagem":
  * Define os atributos e métodos relacionados aos personagens do jogo, incluindo:
  * Nome 
  * Idade
  * Sexo
  * Raça

Os campos de "Nome", "Idade", "Sexo" e "Raça" não interferem na jogabilidade do jogador, sendo criadas apenas para criar imersão do jogador com seu personagem. Ainda assim, é permitido essa costumização ao jogador, tendo uma etapa de confirmação posteriormente ao começo de cada partida.    
  * Classe
As classes definim os status base iniciais do jogador, não havendo um diferencial de crescimento por nível entre as classes, ou limitações de quais itens cada classe pode equipar.
  * Métodos para atacar fisicamente, atacar magicamente, defender fisicamente e defender magicamente; caso o jogador entre com qualquer entrada que não seja o equivalente a uma dessas ações

* ## Classe "item":
  * Define os atributos e métodos relacionados aos itens do jogo, incluindo:
  * Nome
  
O código possui dois grupos de primeiros e segundos nomes que são combinados de maneira aleatoria para a geração dos itens, os primeiros e segundos nomes dos itens não afetam seus status, são apenas para criar maior imersão no jogo, fazendo com que o jogador não receba os memsmo itens ao recomeçar o jogo ou ao continuar a derrotar os monstros que se apresentarem e recolher sua recompensa. O primeiro nome identifica o tipo de arma(espada, arco,...) e o segundo nome o personaliza; há 95 primeiros nomes e 102 segundos nomes, criando 9690 posibilidades de itens para serem recebidos.

Os itens possuem bonus nos seus status alocados de maneira rândomica, sendo elas um porcentual randomico sobre um valor de vantagem, sendo um binário de "1" ou "-1" que tambem é definido de maneira rândomica e especifica para cada tipo de bonus a ser levado em conta na geração do monstro; dessa forma o valor de vantagem pode ser negativo, indicando que em realidade o jogador irá perder status caso escolha utilizar o item.
Não há alteração de proporção do porcentual de vantagem que o mostro será gerado, nem sobre qual lado da luta receberá a vantagem conforme os mostros vão sendo derrotados, seguindo a mesma regra do começo ao final de cada partida. 

  * Bônus de vida : 0 À 20% sobre a vantagem
  * Bônus de ataque físico : 0 À 15% sobre a vantagem 
  * Bônus de ataque mágico : : 0 À 15% sobre a vantagem
  * Bônus de resistência física : 0 À 15% sobre a vantagem
  * Bônus de resistência mágica : 0 À 15% sobre a vantagem

A partir deste sistema é importante ressaltar que os itens gerados podem não ser úteis ao jogador, sendo parte do jogo a decisão do aventureiro se irá adicionar o item a seu inventário ou não.


* ## Classe "GeradorDeEntidades":
  * Responsável por gerar monstros e itens aleatórios. Inclui listas de nomes e adjetivos para criar combinações únicas de itens e monstros.
  * Nome
O código possui dois grupos de primeiros e segundos nomes que são combinados de maneira aleatoria para a geração do monstro, os primeiros e segundos nomes dos monstros não afetam seus status são apenas para criar maior imersão no jogo, fazendo com que o jogador não enfrente os memsmo monstros ao recomeçar o jogo ou ao continuar a derrotar os monstros que se apresentarem. O primeiro nome identifica o tipo de monstro(raça) e o segundo nome o personaliza; há 87 primeiros nomes e 100 segundos nomes, criando 8700 posibilidades de monstro para serem enfrentados.

Os monstros possuem bonus nos seus status alocados de maneira rândomica, sendo elas um porcentual randomico sobre um valor de vantagem, sendo um binário de "1" ou "-1" que tambem é definido de maneira rândomica e especifica para cada tipo de bonus a ser levado em conta na geração do monstro; dessa forma o valor de vantagem pode ser negativo, indicando que em realidade o jogador que possui a vantagem sobre o monstro.
Não há alteração de proporção do porcentual de vantagem que o mostro será gerado, nem sobre qual lado da luta receberá a vantagem conforme os mostros vão sendo derrotados, seguindo a mesma regra do começo ao final de cada partida.  

  * Bônus de vida : 0 À 20% sobre a vantagem
  * Bônus de ataque físico : 0 À 15% sobre a vantagem 
  * Bônus de ataque mágico : : 0 À 15% sobre a vantagem
  * Bônus de resistência física : 0 À 15% sobre a vantagem
  * Bônus de resistência mágica : 0 À 15% sobre a vantagem
  
* ## Classe "Inventrio":


 * Cria um inventário onde vão ser armazenados os itens obtidos

No inicio da partida após o jogador escolher sua classe será gerado de maneira randômica 10 opções primeiros itens, esta é a única fase do jogo o qual é obrigatorio que o usuário escolha um item.

* Limite de inventário

O inventário limita o jogado até 10 itens.

 * Dá a opção para o usuário apagar os itens armazenados.

No final de cada rodada é aberta a opção de descartar um dos itens em seu inventário


> Notas : 

> O jogo utiliza system("cls") para limpar a tela no Windows e system("clear") para sistemas Unix.
> Os atributos dos personagens aumentam em 2 pontos ao subir de nível.
> Os atributos do monstros são gerados aleatoriamente, mas o nível de dificuldade multiplica os atributos continuamente.
> A defesa aumenta a resistência temporariamente e é resetada no próximo turno de ataque.
> Divirta-se jogando RNG RPG e que a sorte esteja ao seu lado!






