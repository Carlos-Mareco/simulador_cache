# Expressao booleana

A partir das saídas de um circuito no arquivo [input.txt](./input.txt) é gerada uma expressão booleana simplificada em formato de mintermos. Além de exibir o mapa de Karnaugh(ainda em desenvolvimento).

## Compilação e execução

Use o compilador G++ integrante da [GCC](https://gcc.gnu.org/) (GNU Compiler Collection) através do [Makefile](./Makefile).
Certifique-se de estar no diretório do programa.

```bash
make
```
E para executar, ainda no mesmo diretório do programa, use :

```bash
./simulador_cache 4 32
```
Os parâmetros 4 e 32 são, respectivamente, as quantidades de endereços na memória cache e memória principal.

## Ambiente de criação e teste

**Informação do OS:** Linux Mint 20.1 Cinnamon.<br>
**Kernel do Linux:** 5.4.0-88-generic<br>
**Processador:** Intel© Core™ i7-7500U CPU @ 2.70GHz × 2.<br>
**Memória:** 7.7 GiB.<br>
**Editor/IDE:** [Visual Studio Code 1.61.0](https://code.visualstudio.com/).<br>
**Compilador:** G++ 9.3.0.<br>

## Licença

Licenciado sob a [GNU General Public License](./LICENSE).

## Condirações finais

Este programa faz parte de um dos componentes avaliativos da disciplina de Arquitetura de Computadores do Curso de Ciência da Computação da Universidade Federal do Amapá.