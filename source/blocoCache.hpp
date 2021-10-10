/**
 * @file blocoCache.hpp
 * @author Carlos Henrique Barreto Mareco
 * @date 20 Ago 2021
 */
#ifndef BLOCO_CACHE_HPP
#define BLOCO_CACHE_HPP

#include <string>

using namespace std;

// Classe responsável por simular um endereço da cache
class blocoCache{
private:
    bool verificador; // Se tiver um dado no endereço, então verificador = true
    string tag; // Guarda a tag na memória cache

    //Define o tamanho da tag
    string tagEnd(string endereco, int nBitsCache);
    //Retorna true se a tag inserida como argumento for igual a tag do endereço da cache
    bool compareTag(string tag);
    //Adiciona um dado na cache, alterando o verificador e a tag
    void adicionaCache(string tag);
public:
    //Construtor que define a cache como vazia inicialmente
    blocoCache();
    //Verifica se um endereço da memória principal já foi referenciado nesse endereço da memória cache
    bool verificaEnd(string endereco, int nBitsCache);
};

#endif 