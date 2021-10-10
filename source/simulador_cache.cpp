/**
 * @file simulador_cache.cpp
 * @author Carlos Henrique Barreto Mareco
 * @date 20 Ago 2021
 */
#include <iostream>
#include <cmath> //log2(n) e pow(2, n)
#include <string> //operações com string
#include <vector> //uso do vector
#include <sstream> //usado para dar split (virgula como separador) na string
#include "blocoCache.hpp"
#include "colors.h"

using namespace std;

//Simulador da memória cache
void simuladorCache(int end_cache, int end_principal);
//Converte um número binário em decimal
int convToDec(string binario);
//Retorna um vector com todos os endereços digitados pelo usuário, além de verificar a válidade desses endereços.
vector<string> getEnderecos(vector<string> enderecos, int nBitsPrincipal);
//Exibi os endereços reconhecidos no terminal
void coutEnderecos(vector<string> enderecos, int nBitsPrincipal, int nBitsCache);

int main(int argc, char const *argv[]){
    
    // argv[1]: memória cache, argv[2]: memória principal
    if (argc == 3){
        int end_cache = atoi(argv[1]);
        int end_principal = atoi(argv[2]);
        if (end_cache > 1 && end_principal > 1 && end_cache <= end_principal){
            cout << "Aviso: Os endereços são alterados automaticamente para base 2.\n";
            cout << "------------Informações Gerais------------\n";
            cout << "Endereços na memória cache: " << (end_cache = pow(2, (int) log2(end_cache))) << endl;
            cout << "Endereços na memória principal: " << (end_principal = pow(2, (int) log2(end_principal))) << endl;
            simuladorCache(end_cache, end_principal);
        } else {
            cout << "ERRO: Endereço(s) inválido(s)!\n";
        }
    } else {
        cout << "ERRO: Argumentos inválidos!\n";
        cout << "Use: " << argv[0] << " <endereços na mem. cache> <endereços na mem. principal>\n";
    }

    return 0;
}

void simuladorCache(int end_cache, int end_principal){
    blocoCache memoriaCache[end_cache]; // Criar um vetor com 'end_cache' posições, onde cada posição é um endereço na cache 
    int nBitsCache = log2(end_cache); // Guarda o tamanho de bits do endereço da cache
    int nBitsPrincipal = log2(end_principal); // Guarda o tamanho de bits do endereço da memória principal
    int hit = 0;
    int miss = 0;
    vector<string> enderecos; //Guarda todos os endereços válidos digitados pelo usuário

    cout << "Memória principal tem endereços de " << nBitsPrincipal << " bits.\n";
    cout << "Bits da tag: " << nBitsPrincipal-nBitsCache << "\n";
    cout << "Bits de endereço na cache: " << nBitsCache << "\n";
    cout << "------------------------------------------\n";
    cout << "Entre com os endereços (digite em binário e use virgula para separar): \n";
    enderecos = getEnderecos(enderecos, nBitsPrincipal);
    coutEnderecos(enderecos, nBitsPrincipal, nBitsCache);
    for(int i = 0; i < enderecos.size(); i++){
        if(memoriaCache[convToDec(enderecos[i])%end_cache].verificaEnd(enderecos[i], nBitsCache))
            hit++;
        else
            miss++;
    }
    if((hit+miss) != 0){
        cout << "Hits: " << hit << "\nMisses: " << miss << endl;
        cout.precision(2);
        cout <<"Taxa de hits: " << fixed << ((float)hit/(hit+miss))*100 << "%\n"; 
    } else {
        cout << "ERRO: Não há entrada de endereços válidos!\n";
    }
}

int convToDec(string binario){
    int tmp = 0;
    for(int i = 0; i < binario.size(); i++){
        if(binario[binario.size()-1-i] == '1')
            tmp+= pow(2, i);
    }
    return tmp;
}

vector<string> getEnderecos(vector<string> enderecos, int nBitsPrincipal){
    string tmp;
    string aux = "";
    getline(cin, tmp); //Guarda os endereços digitados pelo usuário

    //remove qualquer caractere que não seja binário ou virgula.
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i] == '1' || tmp[i] == '0' || tmp[i] == ',')
            aux += tmp[i];
    }
    //separa os binários que tem 'nBitsPrincipal' bits de tamanho em cada posição do vector enderecos
    stringstream temp(aux);
    tmp = "";
    while(getline(temp, tmp, ',')){
        if(tmp.size() == nBitsPrincipal)
            enderecos.push_back(tmp);
    }
    return enderecos;
}

void coutEnderecos(vector<string> enderecos, int nBitsPrincipal, int nBitsCache){
    if(enderecos.size() != 0){
        cout << "Endereços reconhecidos:\n";
        for(int i = 0; i < enderecos.size(); i++){
            for (int j = 0; j < nBitsPrincipal; j++){
                if(j < nBitsPrincipal-nBitsCache){
                    cout << CLR_GREEN << enderecos[i][j];
                } else {
                    cout << CLR_BLUE << enderecos[i][j];
                }
            }
            cout << CLR_RESET;
            if(i != enderecos.size()-1)
                cout << ", ";
        }
        cout << endl;
        cout << "Obs.: Partes em verde e azul são, rescpectivamente, a tag e o endereço na cache.\n";
    }
}