#ifndef GeradorDeEntidades_H
#define GeradorDeEntidades_H
#include <string>
#include "item.hpp"
#include "Personagem.hpp"
#include "inventario.hpp"

using namespace std;

class GeradorDeEntidades {
public:
string Subitens[95] = {
    "Espada", "Escudo", "Capacete", "Armadura", "Botas",
    "Luvas", "Anel", "Amuleto", "Cajado", "Varinha",
    "Daga", "Martelo", "Machado", "Lança", "Arco",
    "Flecha", "Elmo", "Cota de malha", "Broquel", "Bastão",
    "Manto", "Túnica", "Bracelete", "Cinto", "Grevas",
    "Ombreira", "Adaga", "Faca", "Clava", "Maça",
    "Escapulário", "Pendente", "Pingente", "Tiara", "Diadema",
    "Coroa", "Guarda-peito", "Perneira", "Espaldar", "Escapulario",
    "Foice", "Funda", "Estilingue", "Tridente", "Estoque",
    "Sabre", "Cutelo", "Esporão", "Rede", "Bestas",
    "Arpéu", "Catapulta", "Balista", "Escudo de torre", "Punhal",
    "Facão", "Estrela da manhã", "Alabarda", "Bordão", "Pique",
    "Gadanha", "Foice de guerra", "Arco longo", "Arco curto", "Besta leve",
    "Besta pesada", "Rodela", "Adaga envenenada", "Lança de arremesso", "Granada",
    "Cajado mágico", "Varinha mágica", "Livro de feitiços", "Grimório", "Tomo",
    "Poção", "Elixir", "Unguento", "Ervas", "Cristal",
    "Gema", "Pedra rúnica", "Talismã", "Orbe", "Relíquia",
    "Ídolo", "Fetiche", "Chave", "Mapa", "Pergaminho",
    "Fósforo", "Tocha", "Lanterna", "Baú", "Saco"
};

string AdjItens[102] = {
    "do Rei Caído Grindon", "da Feiticeira Eldoria", "do Dragão Ancestral",
    "do Guardião das Sombras", "do Senhor dos Ventos", "do Campeão Eterno",
    "do Mestre das Runas", "do Andarilho dos Planos", "do Conquistador Imortal",
    "da Sombra Errante", "do Paladino de Zaron", "da Guardiã das Chamas",
    "do Vidente Cego", "do Arauto da Tempestade", "do Herdeiro de Antares",
    "do Legado Perdido", "do Crepúsculo Eterno", "da Aurora Boreal",
    "do Espírito da Floresta", "do Cavaleiro Espectral", "do Inquisidor Sagrado",
    "do Guardião dos Portões", "do Campeão dos Deuses", "da Sereia Encantadora",
    "do Labirinto do Minotauro", "da Relíquia Esquecida", "do Alquimista Louco",
    "da Torre Infinita", "do Abismo Sem Fim", "do Guardião do Abismo",
    "do Espelho da Verdade", "do Oráculo Silencioso", "do Titã Adormecido",
    "da Névoa Encantada", "do Senhor da Noite", "do Arauto do Caos",
    "do Guerreiro Fantasma", "da Canção da Sirena", "do Necromante Supremo",
    "da Ilha Flutuante", "do Dragão Celestial", "da Noite Sem Estrelas",
    "do Feiticeiro Oculto", "do Coração de Gelo", "da Forja Ancestral",
    "da Vingança de Sangue", "do Espírito do Vento", "do Guardião do Relâmpago",
    "do Caçador das Sombras", "do Vórtice Eterno", "do Senhor da Guerra",
    "da Rainha de Gelo", "do Martelo dos Deuses", "do Escudo Indestrutível",
    "da Fúria do Vulcão", "do Assassino Silencioso", "do Arqueiro Fantasma",
    "do Manto das Sombras", "do Voo da Fênix", "do Tridente do Abismo",
    "do Martelo do Trovão", "do Machado do Berserker", "do Colar das Almas",
    "da Adaga do Traidor", "da Capa da Invisibilidade", "do Livro das Sombras",
    "da Jóia do Destino", "do Cajado do Arcanjo", "do Escudo da Aurora",
    "da Lâmina do Exílio", "do Anel do Tempo", "da Lança de Longinus",
    "do Punhal do Caos", "da Espada da Luz", "do Anel do Dragão",
    "da Floresta Encantada", "do Cristal do Poder", "da Mente do Enigma",
    "da Poção da Eternidade", "do Machado de Ferro Negro", "do Sábio dos Mares",
    "do Rei dos Trolls", "do General dos Mortos", "do Mestre das Feras",
    "do Demônio Interior", "do Caminho da Redenção", "da Ira do Trovão",
    "do Silêncio das Profundezas", "do Conjurador Sombrio", "da Canção dos Elfos",
    "da Harpa Encantada", "do Trono de Ossos", "do Fragmento de Estrela",
    "da Armadura do Juízo Final", "do Mago Errante", "do Orbe da Destruição",
    "do Ladrão de Almas", "da Vingança do Exilado", "do Cristal da Sabedoria",
    "do Portador da Chama", "da Profecia do Dragão", "do Rei dos Céus"
};
string SubMonstros[87] = {
    "Dragão", "Troll", "Goblin", "Esqueleto", "Vampiro",
    "Lobisomem", "Elemental", "Lich", "Demônio", "Ogro",
    "Grifo", "Hidra", "Mantícora", "Basilisco", "Quimera",
    "Gnoll", "Súcubo", "Gárgula", "Zumbi", "Fantasma",
    "Aranha", "Serpente", "Minotauro", "Cyclops", "Kraken",
    "Vespa", "Harpia", "Espectro", "Fênix", "Leviatã",
    "Vulto", "Lamia", "Banshee", "Behemoth", "Wendigo",
    "polvo", "Golem", "Doppelganger", "Slime", "Ghoul",
    "Múmia", "Naga", "Verme", "Escorpião", "Sátiro",
    "Fada", "Demogorgon", "Chimera", "Gigante", "Anjo",
    "Serafim", "Dríade", "Kelpie", "Mago", "Cavaleiro",
    "Besta", "Aberração", "Corvo", "Lorde", "Druida",
    "Espírito", "Guardião", "Cão", "Centauro", "Sereia",
    "Beholder", "Rato", "Arauto", "Necrófago", "Yeti",
    "Abissal", "Diabrete","cogumelo","planta","ladrão",
    "Bruxa","Barbaro","Rei","Lobo","Cavalo",
    "Rato","Espirito","Fada","Elfo","Livro Amadiçoado",
    "Aradura Amadiçoada","Alquimista"};
string AdjMonstros[100] = {
    "do Abismo", "das Sombras", "da Destruição", "do Caos", "da Morte",
    "do Fogo", "da Gélida Noite", "da Tormenta", "das Profundezas", "do Submundo",
    "do Pesadelo", "da Loucura", "do Eclipse", "do Crepúsculo", "da Escuridão",
    "do Pântano", "da Selva", "da Névoa", "do Deserto", "da Montanha",
    "das Estrelas", "do Medo", "da Sombra Errante", "do Vazio", "da Ira",
    "da Agonia", "da Desolação", "do Inferno", "da Perdição", "do Pavor",
    "do Pântano", "da Bruxaria", "da Magia Negra", "do Sobrenatural", "do Horizonte",
    "da Floresta", "do Caos Antigo", "da Ruína", "do Gelo Eterno", "da Noite",
    "do Pavor Ancestral", "do Povo Oculto", "do Reino Perdido", "do Infinito", "do Fogo Infernal",
    "do Trovão", "do Inferno Gelado", "da Maldade", "da Lâmina Sombria", "do Relâmpago",
    "da Névoa Mortal", "da Fortaleza", "da Bastilha", "da Perdição", "do Horror",
    "da Solidão", "da Guerra", "da Sangria", "da Miséria", "do Terror",
    "da Vingança", "do Juízo Final", "do Desespero", "da Ascensão", "da Corrupção",
    "da Devastação", "da Profanação", "da Escuridão", "do Extermínio", "da Carnificina",
    "do Tormento", "do Caos Antigo", "da Força Bruta", "do Vazio Eterno", "do Reino Sombrio",
    "da Terra Desolada", "do Inferno Abissal", "da Chama Eterna", "do Mar Revolto", "da Tundra",
    "da Ilha das Sombras", "do Reino Fantasma", "da Torre Negra", "do Portal Proibido", "da Névoa Encantada",
    "do Vale dos Mortos", "da Vila Assombrada", "da Catedral Sombria", "do Castelo Destruído", "da Cripta Antiga",
    "da Cidade Perdida", "da Gruta Oculta", "da Praia Sombria", "do Templo Esquecido", "do Labirinto Sem Fim",
    "do Reino Perdido", "da Rocha Eterna", "da Pedra Filosofal", "do Vale da Morte", "da Prisão Abissal"
};

int nivelDeDificuldade = 1;
    std::string gerarNomeItem();
    item* gerarItem();
    std::string gerarNomeMonstro();
    Personagem* gerarMonstro();
    Inventario inventario;
};
#endif
