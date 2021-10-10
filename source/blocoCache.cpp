/**
 * @file blocoCache.cpp
 * @author Carlos Henrique Barreto Mareco
 * @date 20 Ago 2021
 */
#include "blocoCache.hpp"

using namespace std;

blocoCache::blocoCache(){
    this->verificador = false;
    this->tag = "";
}

string blocoCache::tagEnd(string endereco, int nBitsCache){
    return endereco.erase(endereco.size() - nBitsCache);
}

bool blocoCache::compareTag(string tag){
    if(this->tag.compare(tag) == 0)
        return true;
    else
        return false;
}

void blocoCache::adicionaCache(string tag){
    this->verificador = true;
    this->tag = tag;
}

bool blocoCache::verificaEnd(string endereco, int nBitsCache){
    if(this->verificador && compareTag(tagEnd(endereco, nBitsCache))){
        return true;
    } else {
        adicionaCache(tagEnd(endereco, nBitsCache));
        return false;
    }
}