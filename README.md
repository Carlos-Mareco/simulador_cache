# Simulador de cache

Simula o acesso que o processador precisa realizar na memória cache, onde o processador precisa de um dado da memória principal, mas que esse dado deve ser referenciado na memória cache. Além de que, ao final da execução do programa, é informado a taxa de hits e misses que o processador contabilizou para encontrar a informação na cache. 

## <img height="30" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg"> Compilação e execução

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

## Considerações finais

Este programa faz parte de um dos componentes avaliativos da disciplina de Arquitetura de Computadores do Curso de Ciência da Computação da Universidade Federal do Amapá.
