# Processos de Sistemas Operacionais

--------------
## Introdução
- Primeiros sistemas: um programa por vez;
- Atualmente multiprogramação;
- Processos que executam concorrentemente, selecionados pela CPU a fim de tornar o computador mais produtivo.
<img width="540" height="280" alt="image" src="https://github.com/user-attachments/assets/23fd6839-44d7-4ac3-8a88-f398a1533be7" />

## Multiprogramação
- Mecanismo de interrupções
  - Permite que um controlador de periférico chame a atenção do processador;
  - Interrupção sinaliza a ocorrência de algum evento;
  - Alguns processadores salvam automaticamente os registradores quando ocorre uma interrupção; outros, salvam apenas alguns e a rotina de interrupção encarrega-se de salvar os demais;
  - Controlador de periférico: conecta o periférico ao processador; traduz sinais ao dispositivo;
  - Processador: ler, escrever dados, ler status do dispositivo, reiniciar, escrever comandos.
  - Diagrama de Tempo de uma Operação E/S:
  <img width="748" height="230" alt="image" src="https://github.com/user-attachments/assets/bde9e541-8941-4d6b-a402-d317701a06bb" />

  - As interrupções possuem um tipo (0..255) definido pelos projetistas do sistema;
  - Existem momentos em que não podem ocorrer interrupções (habilitar/desabilitar interrupções)
- Processo

## Processos

## Escalonamento de processos

## Operações nos processos

## Comunicação entre processos

## Mais alguns conceitos...
