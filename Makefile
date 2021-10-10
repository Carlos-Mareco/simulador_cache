CC=g++
OUT=simulador_cache
DEP_DIR=${PWD}/source
FLAGS=-std=c++17

all:
	$(CC) ${DEP_DIR}/blocoCache.cpp ${DEP_DIR}/simulador_cache.cpp $(FLAGS) -o $(OUT)