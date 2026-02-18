# INTRODUÇÃO

## Sistema Operacional
- Programa colocado entre o hardware do computador e os programas do usuário;
- Torna o uso do computador conveniente;
- Uso eficiente do hardware;
- Controla e coordena o uso do hardware entre vários programas aplicativos para os vários usuários.

- Alocador de recursos;
- Programa de controle.

### Sistemas de Grande Porte
- Usados nos mainframe;
- Sistemas em lote;
- Sistemas multiprogramados;
- Sistemas de tempo compartilhado.

  #### Sistemas em lote (batch)
  Processamento sequencial jobs, monoprogramado, monousuário.
  - Máquinas grandes, operadas a partir de um console;
  - Dispositivos de entrada;
  - Dispositivos de saída;
  - Usuário não interagia diretamente na máquina;
  - SO era simples.
  
  - Job (tarefa)
    - Criado pelo usuário; uso de cartões;
    - Organizados pelo operador do lote, conforme as características/necessidades;
    - Passagem entre diferentes jobs é manual;
    - Saída aparecia algum tempo depois.
  
  - CPU ociosa
     - Velocidade dos dispositivos de entrada/saída x velocidade CPU.
  - SO sempre residente na memória - Monitor residente.
  
  #### Sistemas multiprogramados
  - Sistemas batch com discos;
  - E com as interrupções -> escalonamento de job -> multiprogramação;
  - Vários jobs na memória.
  
  - SO precisa tomar decisões;
  - Pool de jobs;
  - Escalonamento de Jobs e CPU;
  - Gerência de Memória e I/O.
  
  #### Sistemas Timesharing ou Tempo Compartilhado
  - CPU executa vários jobs alternando entre eles;
  - Há uma divisão do tempo de processamento entre os vários usuários -> tempo de resposta;
  - Multiprogramação;
  - Tornam-se comuns no início da década de 70.

### Sistemas de Computadores Pessoais (desktop)
- Inicialmente, não possuíam recursos para proteger o SO; não eram multiusuário, nem multitarefa;
- MULTICS.

  #### Sistemas monousuário
  
  #### Sistemas multiusuário
  
  #### Sistemas monotarefa
  
  #### Sistemas multitarefa

### Sistemas Paralelos
- Vários processadores;
- Fortemente acoplados;
- Comunicaçao Através da memória.

- Multiprocessamento simétrico.

### Sistemas Distribuídos
- 1990 - crescimento das redes de computadores;
- Sistemas fracamente acoplados;
- Comunicação acontece por trocas de mensagens.
  #### Sistemas Cliente-Servidor
  #### Sistemas peer-to-peer
  #### Sistsemas Operacionais Distribuídos

### Sistemas de Tempo Real
- Sistemas com propósito específico;
- Aplicação dedicada;
- Processamento precisa ser feito dentro dos limites de tempo 
definidos;
- Quase não é encontrada memória virtual nestes sistemas.

## Considerações Finais

### SO
- Oferece ao usuário um ambiente conveniente para o 
desenvolvimento e execução de programas;
- Gerencia os recursos de um sistema de computação 
de forma a garantir a correta e eficiente utilização dos 
mesmos.

### Multiprogramação

## Top 5 melhores computadores (Nov/25)
- El Capitan
  - Processador: AMD 4th Gen EPYC 24C 1.8GHz;
  - SO: TOSS;
  - EUA.
- Frontier
  - AMD Optimized 3rd Generation EPYC 64C 2GHz;
  - HPE Cray OS;
  - EUA.
- Aurora
  - Xeon CPU Max 9470 52C 2.4GHz;
  - SUSE Linux Enterprise Server 15 SP4;
  - EUA.
- JUPITER Booster
  - GH Superchip 72C 3GHz;
  - Red Hat Enterprise Linux;
  - Alemanha.
- Eagle
  - Xeon Platinum 8480C 48C 2GHz;
  - Ubuntu 22.04;
  - EUA.
