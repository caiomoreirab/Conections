# Conections 🌐

Este programa em C encontra o maior conjunto de vértices ou a maior comunidade conectada em uma rede social (clique máximo) em um grafo não-direcionado lido de um arquivo. O problema é resolvido utilizando o algoritmo de força bruta, que verifica todas as possíveis combinações de vértices para determinar se formam um clique.

## Plataforma de Teste e Compilação 🖥️

### Plataformas Testadas ✅

O programa foi testado nas seguintes plataformas:

- **Linux:**
  - Distribuição: Ubuntu 20.04 LTS
  - Compilação: Feita utilizando o compilador `gcc`.

- **Windows:**
  - Versão: Windows 11
  - Compilação: Utilizou-se o compilador `gcc` via MinGW.

### Requisitos de Compilação 🛠️

Certifique-se de ter os seguintes requisitos atendidos para compilar e executar o programa:

- **Linux:**
  - ``GCC`` instalado (`sudo apt install gcc`)
  - Utilitário ``Make`` (`sudo apt install make`)

- **Windows:**
  - ``GCC`` via MinGW ou outro compilador C adequado configurado no PATH.
  - Atenção: Lembre-se de ter configurado o utilitário ``make`` corretamente. Por padrão o mingw instala como ``mingw32-make``

## Compilação e Execução 🚀

Para compilar o programa, vá até o diretório onde estão localizados os arquivos (`main.c`, `example.txt`) e execute:

```bash
make
```
Isso irá compilar o programa usando o make com o arquivo de entrada main.c.

Para executar:
```bash
cd out
./main
```

## Como Funciona ℹ️

### Algoritmo Utilizado 🛠️

O algoritmo empregado é baseado em força bruta:
1. **Inicialização do Grafo:** O grafo é inicializado com base no número de vértices lidos de um arquivo de entrada.
2. **Leitura das Conexões:** As conexões entre os vértices são lidas de um arquivo que descreve quais vértices estão conectados.
3. **Encontrando o Clique Máximo:** Utilizando uma abordagem de combinações, o programa verifica todas as possíveis combinações de vértices para determinar se formam um clique (conjunto completo de vértices conectados entre si).
4. **Saída:** O programa imprime o tamanho e os vértices do maior clique encontrado.

### Complexidade ⏳

O algoritmo de força bruta verifica todas as possíveis combinações de vértices, o que resulta em uma complexidade exponencial. Para um grafo com *n* vértices, a complexidade é aproximadamente O(2^n).

## Arquivos no Repositório 📁

- `conexoes.txt`: Arquivo de entrada que descreve as conexões entre os vértices do grafo. O formato é: **`e v1 v2`**<br />
Onde `e` indica uma conexão entre os vértices `v1` e `v2`, `v3` e `v4`, e assim por diante.

- `main`: Executável para sistemas Linux.
- `main.exe`: Executável para sistemas Windows.

## Como Usar 🚀

1. **Execução:**
 - **Linux:** Execute o comando `./main` no terminal.
 - **Windows:** Execute `main.exe` no prompt de comando.

2. Certifique-se de ter os arquivos necessários (`conexoes.txt` e os executáveis) no mesmo diretório antes de executar o programa.

## Um exemplo de entrada para o programa seria:<br />

![image](https://github.com/Fabio-araujo-silva/Conections/assets/82675020/2ad17af8-2d5a-4ce8-8189-b30eb6447b74)
<br />Onde o grafo possui 5 vértices e 6 arestas<br />
<br />representado por:

```
5 6
e 1 2
e 1 3
e 2 4
e 2 3
e 3 4
e 4 5
```
### Saída 💡

A saída seria:
(1, 2, 3)
Isso indica que um dos maiores cliques encontrados (existem, nesse caso, mais de um com o mesmo tamanho) possui 3 vértices (1, 2 e 3).


## Observações 📝

- A complexidade exponencial torna este método impraticável para grafos muito grandes devido ao tempo necessário para processamento.
