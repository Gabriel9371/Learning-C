# Cubo 3D em C puro + SDL2
 
Um cubo 3D wireframe, com projeção em perspectiva e rotação, renderizado em tempo real usando apenas **C puro** e **SDL2** para desenho de linhas — sem nenhuma engine ou lib gráfica de alto nível.
 
Feito como projeto de estudo para entender, na prática, os fundamentos de computação gráfica 3D: projeção de perspectiva, matrizes de rotação e o ciclo de renderização (game loop) do zero.
 
![linguagem](https://img.shields.io/badge/linguagem-C-blue)
![lib](https://img.shields.io/badge/lib-SDL2-green)

## Sobre o projeto

A ideia era simples no papel e meio complicado na prática: fazer 8 pontos no espaço 3D, conectar, formando um cubo, e fazer ele girar na tela — usando **apenas C e SDL2** (sem OpenGL, sem engine, sem lib 3D pronta).


## Como funciona
 
- **8 vértices** do cubo são definidos como combinações de `+1`/`-1` em cada eixo (x, y, z)
- A cada frame, cada vertice passa por uma **rotação em torno do eixo Y**, usando a matriz de rotação padrão (seno/cosseno), fazendo o cubo girar continuamente.
- Os pontos rotacionados (ainda em 3D) são então **projetados para 2D** usando uma projeção em perspectiva bem simples: quanto maior a distância (Z) de um ponto até a câmera, menor ele aparece na tela — "simulando" o efeito visual de profundidade.
- As **12 arestas** do cubo são desenhadas conectando os pares de vertices correspondentes com `SDL_RenderDrawLine`.
- O loop principal roda com a taxa de atualização do monitor (VSync), isso para uma rotação suave, independente da carga da CPU.

## Requisitos
 
- GCC (ou outro compilador C)
- SDL2 instalado
No Arch Linux:
```bash
sudo pacman -S sdl2
```
## Como compilar e rodar
 
```bash
gcc main.c -o cube `pkg-config --cflags --libs sdl2` -lm

./cube
```
> O `-lm` é porque o projeto usa as funções `sin()` e `cos()` de `<math.h>` na rotação.


ressione **ESC** ou feche a janela para sair. *(ajuste aqui se o controle de saída for outro)*

## Possíveis próximos passos
 
- [ ] Rotação tambem nos eixos X e Z (rotação livre, não só em Y)
- [ ] Controlar a rotação via teclado/mouse


## Aprendizados

- Diferença entre coordenadas no espaço matemático (centrado em zero) e coordenadas de tela (pixel, origem no canto superior esquerdo)
- Por que a projeção em perspectiva usa **divisão** pela profundidade (efeito de "quanto mais longe, menor")
- Como rotação 2D (dentro do plano X-Z) usa seno e cosseno para "misturar" as duas coordenadas proporcionalmente ao ângulo
- Por que um game loop precisa de sincronização (VSync) para não depender da velocidade da CPU
