# Escalonamento

## Introdução
- Base para Sistemas Operacionais Multiprogramados;
- Escalonamento de: Processos e Threads (no nível do Kernel);
- Função fundamental dos Sistemas Operacionais
  - Quase todos os recursos são escalonados antes do uso. A CPU é o principal recurso -> ponto central para o projeto de sistemas operacionais.
- CPU sem trabalho útil -> tempo perdido (ociosidade);
- Processos passam para o estado "em Espera", a CPU pode ocupar-se com outro processamento;
- Multiprogramação
  - Procura utilizar o tempo de forma produtiva;
  - Vários processos na memória para execução.

## Ciclos de CPU e I/O
- A execução de um processo alterna entre:
  - ciclos de CPU;
  - ciclos de I/O.
- Processo limitado por I/O:
  - Possui muitos ciclos de surtos curtos de CPU
- Processo limitado por CPU:
  - Alguns ciclos de surtos longos de CPU
- Essa distribuição deve ser observada para escolha do algoritmo de escalonamento

## Escalonador de CPU
- Escalonamento executado pelo Escalonador de Curto Prazo;
- Escolhe um processo na Fila de Processos Prontos;
- Objetivos:
  - Aumentar a produção do sistema (*througput*);
  - Diminuir o tempo de resposta aos usuários;
  - Manter o processador ocupado o máximo possível;
  - Diminuir o tempo médio de espera na fila do processador (*tunraroundtime*).
- Uma fila de escalonamento não necessariamente é implementada como FIFO;
- Pode ser:
  - Fila de prioridades;
  - Lista encadeada desordenada;
  - Árvore.
- Que situações geram escolha de um processo?
  - <img width="658" height="251" alt="{A92FAD32-A60B-44E3-8C56-594D58EA95BB}" src="https://github.com/user-attachments/assets/81a1e1a2-65ad-4c41-9112-a83361b8c79d" />

## Escalonamento
- O Escalonamento pode ser:
  - Preemptivo:
    * As interrupções estão habilitadas;
    * A execução pode ser interrompida.
  - Não-preemptivo ou Cooperativo:
    * O processo, após ter a CPU alocada, mantém o uso até liberá-la;
    * Término da execução;
    * Passagem para o estado Em espera;
    * Não é necessário o temporizador de hardware.
- No Escalonamento Preemptivo:
  - Há custo associado à coordenação do acesso aos dados compartilhados;
  - Influencia no projeto do kernel do SO
    * Chamada ao sistema: o kernel pode estar ocupado com outro processo;
    * Podem gerar mudanças em dados compartilhados;
    * É necessária a conclusão de uma chamada ao sistema ou operação I/O antes de fazer a troca de contexto.
-  Devido ao escalonamento preemptivo, alguns SO são implementados de forma a esperar a conclusão de uma chamada ao sistema ou de um bloco de operações de I/O antes de ser efetuada a troca de contexto.
  - Simplicidade do Kernel;
  - Versão do Unix;
  - Não eficiente para sistemas de tempo real.
- Há possibilidade de habilitar/desabilitar as interrupções a fim de proteger uma seção de código.

## *Dispatcher* = Executor
- Módulo que dá controle da CPU ao processo escalonado. Faz:
  - passagem para o modo de usuário/supervisor;
  - troca de contexto:
    * Salva no descritos de processo ou na pilha do processo;
    * Ao ser restaurado, o *Program Counter* (PC) indica o ponto de continuação da execução;
    * Mudança para posição adequada no programa do usuário conforme o *Program Counter* (PC).

## Critérios de Escalonamento
- São critérios utilizados para a comparação de algoritmos/políticas de escalonamento;
- O escalonamento procura **maximizar** os seguintes critérios:
  - **Utilização de CPU**: Deve ficar o maior tempo possível ocupada;
  - **Throughput**: Número de Processos terminados por unidade de tempo. Por exemplo: 1 processo / hora; 10 processos / segundo.
- O escalonamento procura **minimizar** os seguintes critérios:
  - **Tempo de retorno**: É o tempo entre a Submissão e a Conclusão do Processo. Envolve o tempo na fila de prontos, em execução, usando dispositivos...
  - **Tempo de Espera**: Tempo esperando na fila de processos prontos (não afeta operações de I/O);
  - **Tempo de Resposta**: É o tempo entre a Submissão e a Primeira Resposta do processo (não considera a velocidade do dispositivo de saída).

## Políticas de Escalonamento
- As políticas de escalonamento constituem-se em algoritmos de escalonamento que selecionam quais processos devem utilizar a CPU em determinado instante. As principais políticas são:
  - First-Come, First-Served (FCFS) ou First-In, First-Out (FIFO);
  - Shortest Job First - SJF;
  - Escalonamento por Prioridade;
  - Escalonamento Round – Robin (RR) ou Revezamento Circular ou Fatia de Tempo.
- Existem outros algoritmos de escalonamento como High Response Ratio Next (HRRN), Shortest Remaining Time (SRT) e também a combinação de mais de uma política de escalonamento, caracterizando os escalonadores por:
  - Múltiplas Filas;
  - Múltiplas Filas com realimentação.

## Algoritmos de Escalonamento
- First-Come, First-Served (FCFS) ou First-In, First-Out (FIFO);
- Shortest Job First - SJF;
- Escalonamento por Prioridade;
- Escalonamento Round – Robin (RR) ou Revezamento Circular ou Fatia de Tempo;
- Múltiplas Filas;
- Múltiplas Filas com realimentação.

  ### First-Come, First-Served (FCFS) ou First-In, First-Out (FIFO)
- É o algoritmo mais simples de implementar: o Processo que solicita a CPU primeiro, recebe primeiro, ou seja, conforme os processos vão chegando são inseridos no fim da fila de prontos.
- É implementado por uma FIFO: um processo entra na fila de processos prontos e seu PCB é ligado ao final da fila.
- O processo utiliza CPU até o término do processamento, ou realize uma chamada ao sistema. Quando a CPU é liberada, ela é alocada ao processo que está no início da fila.
- O processo que entra em execução é removido da fila de prontos.
- Geralmente, apresenta tempo de espera longo, pois não favorece os processos I/O bound. Exemplo:
  - <img width="474" height="231" alt="image" src="https://github.com/user-attachments/assets/11c00c0e-30e1-4cf6-914b-24c762e5b647" />

- **Situação Dinâmica:**
  - Um Processo limitado pela CPU: obtém e detém a CPU;
  - Muitos Processos limitados por I/O: terminam sua operação de I/O e passam para Prontos;
  - Dispositivos de I/O ociosos;
  - Processo limitado pela CPU termina e passa para operação de I/O;
  - Todos os Processos limitados I/O são executados pois tem surtos curtos de CPU;
  - Executam rapidamente e voltam para a fila de I/O;
  - CPU ociosa;
  - Processo limitado pela CPU mais uma vez vai para fila de prontos e retorna para a CPU;
  - Processos limitados por I/O esperam na fila de prontos até a CPU estar disponível.

  ### Shortest Job First - SJF
  - Para cada processo é associada a duração de seu próximo ciclo de surto de CPU;
  - Quando a CPU está disponível, o processo a ser escalonado é o que tem surto de menor duração.
    - Se houver empate, usa-se o escalonamento FCFS.
  - É um algoritmo ótimo
    - Tempo de Espera Médio é mínimo.
  - <img width="573" height="334" alt="image" src="https://github.com/user-attachments/assets/712cb875-cae6-4efc-a1ff-24cfaebec7be" />
  - Problema
    - Para o escalonamento de CPU (escalonador de curto prazo) não existe como saber a duração do próximo ciclo de surto de CPU;
    - Em sistemas batch, o usuário pode especificar esse tempo quando submete o job;
    - Pode-se fazer uma previsão: espera-se que o próximo ciclo de surto de CPU seja semelhante em duração aos anteriores.

  ### Escalonamento por Prioridade
  - SJF é um caso de escalonamento por prioridade:
    - A prioridade é dada aos processos de menores ciclos de surtos de CPU.
  - Na política de escalonamento por Prioridade, uma prioridade é associada a cada processo e a CPU é alocada ao processo de mais alta prioridade.
    - Se houver empate, o escalonamento FCFS é utilizado.
  - Prioridades
    - São definidas em faixas de valores:
      * 0.. 10;
      * 0.. 255.
    - É pré-definido se a prioridade mais alta é determinada pelo maior ou menor número
      * Consideraremos o menor número como sendo a prioridade mais alta.
    - As Prioridades podem ser:
      * Interna:
        - Representam alguma quantidade mensurável para calcular a prioridade do processo (tempo, memória, arquivos abertos, razão entre surtos I/O e CPU).
      * Externa:
        - Definida por critérios externos ao Sistema Operacional (importância do processo, tipo, quantidade paga pelo uso no computador, departamento...)
    - <img width="583" height="279" alt="image" src="https://github.com/user-attachments/assets/3108ffd6-c482-43ba-8943-9ada8c5e67d5" />
    - Pode ser não-preemtivo ou preemptivo;
    - Por exemplo, na seguinte situação: **um processo chegou no sistema durante a execução de outro e o processo que chegou tem prioridade mais alta**
    - No escalonamento não-preemptivo:
      * o processo é colocado no início da fila, pois tem prioridade mais alta;
    - No escalonamento preemptivo:
      * o processo em execução é interrompido e a CPU é alocada ao novo processo.
  - **Problema**: Bloqueio por tempo indefinido ou starvation ou postergação indefinida
    - Processos de baixa prioridade podem ficar esperando pela CPU indefinidamente.
  - **Solução**:
    - Técnica de Envelhecimento (conhecida como aging) 🡪 consiste em aumentar gradativamente a prioridade dos processos que estão na fila de Prontos durante muito tempo, para favorecer sua execução.

  ### Escalonamento Round – Robin (RR) ou Revezamento Circular ou Fatia de Tempo
  - Adequado para Sistemas de Tempo Compartilhado;
  - É o escalonamento FCFS acrescido da preempção para alternar entre os processos;
  - O sistema define um quantum de tempo (fatia)
    - 10, 100 ms
  - O processador percorre a Fila de Prontos, alocando os processos por um intervalo de tempo de até um quantum.
  - É mantido por FIFO: novos processos são adicionados ao final da fila.
  - <img width="830" height="312" alt="image" src="https://github.com/user-attachments/assets/d4b5ae88-928d-491a-b157-3b0133c42a0c" />
  - **1 - Surto de CPU de menos de um quantum**
    - O próprio processo libera CPU;
    - O próximo processo é escalonado.
  - **2 - Surto de CPU excede um quantum**
    - Temporizador esgotará o tempo de execução do processo atual;
    - Acontece Interrupção do SO;
    - Há Troca de contexto dos processos;
    - Processo interrompido vai para o final da fila de prontos;
    - O próximo processo é escalonado.
  - <img width="781" height="367" alt="image" src="https://github.com/user-attachments/assets/e185c8ea-3e55-483e-8fd2-3e283dc267f4" />
  - O Algoritmo Round-Robin é preemptivo;
  - Se houver n processos na Fila de Prontos e q quantum;
  - Então
    - Cada processo terá 1/n do tempo da CPU em lotes de no máximo q unidades de tempo;
    - Cada processo deve esperar no máximo (n-1)q unidades de tempo até o próximo quantum.
  - Desempenho depende do tamanho do quantum
    - Se o quantum for muito grande -> ficará semelhante ao FCFS;
    - Se o quantum for muito pequeno -> compartilhamento de processador -> como se cada um dos n processos tivesse seu próprio processador executando a 1/n da velocidade real do processador (execução com travamentos: executa e para, executa e para...)
    - Tempo de Retorno também depende do tamanho do quantum
    - **80 % dos surtos de CPU < quantum**

  ### Escalonamento por Múltiplas Filas
  - Utilizado em casos onde os processos podem ser classificados em diferentes grupos como por exemplo:
    - Processos de Primeiro Plano (interativos)
      * Podem ter prioridade em relação aos outros processos.
    - Processos de Segundo Plano (batch)
      * Possuem diferentes tempos de resposta, portanto podem ter escalonamentos distintos.
  - A fila de processos prontos é dividida em várias filas separadas por um dos critérios:
    - Prioridade;
    - Tamanho;
    - Tipo.
  - Cada fila possui seu próprio algoritmo de escalonamento;
  - Deve haver escalonamento entre as filas:
    - Geralmente Preemptivo de Prioridade Baixa (fila do primeiro plano pode ter prioridade absoluta sobre a de segundo plano);
    - OU O tempo é fracionado entre as filas.
   - <img width="525" height="278" alt="image" src="https://github.com/user-attachments/assets/0f09c62f-7d1c-4242-b22b-3c69d939f906" />
   - Processos na fila Batch só poderiam executar se os processos das filas do Sistema e Interativos estivessem vazias;
   - Se um Processo do Sistema entrasse na fila, o Processo em Batch seria interrompido.

  ### Escalonamento por Múltiplas Filas com realimentação
  - No caso anterior, os processos não se movem entre as filas. Apesar de apresentar um baixo custo de escalonamento, não é um processo flexível.
  - Nesse escalonamento
    - Processo se move entre as filas;
    - Processos são separados por **diferentes ciclos de surtos de CPU**.
  - Se um processo utilizar surto de CPU excessivo, é movido para uma fila de menor prioridade;
  - Logo: os processos limitados por I/O estão nas filas de prioridade mais alta;
  - Possui técnica de Envelhecimento: processo que espera demais em uma fila de baixa prioridade passa para uma fila de maior prioridade;
  - Exemplo: 3 filas (F0, F1, F2)
    - <img width="637" height="221" alt="image" src="https://github.com/user-attachments/assets/0d70bc30-fb30-4d98-8137-fc6cb1408808" />
    - Executa todos os processos das filas nessa sequência: F0 → F1 → F2
    - Se chegar um processo na F1, interrompe o da F2. O mesmo acontece se chegar um processo na F0;
    - F2 somente executa quando F0 e F1 estiverem vazias.
  - Considerações sobre o exemplo:
    - Prioridade mais alta é dada aos processos com Surto de CPU <= 8 ms;
    - Processos com Surto de CPU entre 8 e 24 ms são rapidamente atendidos;
    - Processos com Surto de CPU maior que 24 ms vão para a F2;
    - Os processos limitados por I/O estão nas filas de prioridade mais alta.
  - Esse escalonador é definido pelos seguintes parâmetros:
    - Número de filas;
    - Algoritmo de escalonamento para cada fila;
    - Método para remover/rebaixar processos;
    - Método para determinar em que fila entrará determinado processo.

