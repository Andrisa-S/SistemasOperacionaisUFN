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
  - Unidade de trabalho;
  - Programa de execução;
  - Processos
    - Sistema Operacional;
    - Usuários.
  - CPU Multiplexada entre os processos;
  - Um programa por si só não é um processo
    - Programa
      - Entidade passiva (disco)
    - Processo
      - Entidade ativa
        * _Program Counter_ indica próxima instrução;
        * Possui um conjunto de recursos associados.
- Proteção entre processos
  - Dois modos de operação
    - Usuário
      * Algumas instruções não podem ser executadas.
    - Supervisor
      * Instruções privilegiadas
  - As interrupções chaveiam o processador no modo supervisor;
  - Proteção de periféricos;
  - Proteção de memória.

## Processos
- Processo é um conceito utilizado em sistemas operacionais para identificar um elemento que concorre à execução
  - “Um mesmo programa pode estar sendo executado por vários usuários, ao mesmo tempo, mas para cada usuário existe um processo”;
  - Cada processo trabalha sobre uma área de memória privativa.
- Um Programa é uma sequência de instruções
  - Entidade Passiva.
- Um Processo altera seu estado à medida que executa um programa
  - Entidade Ativa.
- É representado pelo:
  * Espaço de Endereçamento (armazenamento da imagem do processo);
  * Estruturas Internas do Sistema (áreas de memórias, tabelas internas...);
  * Contexto de execução (pilhas, dados...).
  <img width="420" height="224" alt="image" src="https://github.com/user-attachments/assets/00f7662b-e46a-442f-a916-5a215ecd22f0" />

### Modelo de Processo Unix (Linux)
<img width="617" height="374" alt="image" src="https://github.com/user-attachments/assets/f1643dc7-a82c-4b5b-982a-100c81c02a78" />

### Estados do Processo
- Novo (New);
- Em execução (Running);
- Em espera (Waiting);
- Pronto (Ready);
- Encerrado (Terminated);
- **Conforme um processo é executado, ele muda de estado**;
- Apenas um processo executa em qualquer processador a cada instante;
- Muitos processos podem estar prontos ou em espera.

  #### Diagramas de Estados de um Processo
  <img width="611" height="313" alt="image" src="https://github.com/user-attachments/assets/d673e983-fba1-46d6-af0d-e0f8cc442501" />
---------------

- Processos são criados e destruídos
  - Depende do SO;
  - Alguns casos
    - Um processo para cada terminal
      * Criados na inicialização e destruídos quando o sistema é desligado.
    - Um processo para cada sessão de trabalho;
    - Criar livremente através de chamadas ao sistema.
- Processos do sistema (_daemon_);
- Processos
  - _cpu-bound_
    - Tempo de execução predominantemente definido pelo tempo dos ciclos de processador.
  - _i/o-bound_
    - Tempo de execução predominantemente definido pelas operações de E/S.

  #### Bloco de Controle de Processo
  - **Process Control Block - PCB**;
  - Cada processo é representado pelo SO por um PCB
    - Estado do Processo;
    - Contador de Programa;
    - Registradores do processador;
    - Pilha;
    - Seção de dados (var. globais);
    - Seção de texto (código);
    - Informações para o escalonamento;
    - Informações sobre o gerenciamento de memória;
    - Informações sobre a contabilização;
    - Informação sobre *status* de E/S.
  - PCB
    - Repositório de informações de cada processo.
  - **Bloco Descritor de Processo**
    - Exemplo da estrutura do PCB
      <img width="376" height="364" alt="image" src="https://github.com/user-attachments/assets/cdc59649-f9bb-48bf-a30d-8e794a4849d0" />
  - Criação
    - Alocação de área de memória para código, dados e pilha do processo e estruturas do sistema operacional;
    - Inicialização do PCB e inserção na fila.
  - Execução
    - Execução das instruções da área de código (há interação com o SO);
    - Atualização dos estados e recursos do processo no PCB.
  - Término
    - Liberação de recursos e estruturas de dados utilizadas.

## Hierarquia de Processos
- Alguns SO permitem trabalhar com o conceito de grupo de processos
  - Permite aplicar a mesma operação sobre todo o conjunto de processos
    - Direitos do processo.
- Processos podem ser criados por outros processos através de chamadas ao sistema
  - Processo que faz a chamada: **Processo Pai**;
  - Processo criado: **Processo Filho**.
    <img width="374" height="285" alt="image" src="https://github.com/user-attachments/assets/13616b26-77a9-4542-a0cd-545816e8cc98" />
      * P1 é o processo inicial do sistema, criado durante a inicialização;
      * Os demais processos foram criados através de chamadas ao sistema.;
      * A hierarquia muda com o passar do tempo;
      * Quando um processo é destruído, o que acontece com seus filhos?

## Escalonamento de processos
- Multiprogramação
  - Processos em execução o tempo todo;
  - Otimizar CPU.
- Tempo compartilhado
  - Alternar a CPU entre processos (frequentemente);
  - Transparente para usuário.
- Uniprocessador
  - Escalonamento.
- **Filas de Escalonamento**
  - Filas de Jobs
    - Todo processo que entra no sistema é colocado nessa fila.
  - Filas de Processos Prontos
    - Processos que estão na memória e estão prontos para serem executados.
  - Filas de Dispositivos ou I/O (*cada dsipositivo tem a sua*)
    - Lista de processosesperando por um determinado dispositivo;
    - Quando o dispositivo está ocupado, o processo é colocado na fila do dispositivo.
  - Lista encadeada
    - Cabeçalho
      * Ponteiros para o início e o fim da lista.
    - PCB
      * Ponteiros para o próximo processo da lista.
  <img width="631" height="175" alt="image" src="https://github.com/user-attachments/assets/3c7c9c46-1309-4f3c-a6f5-272d6eaa50e5" />

<img width="699" height="501" alt="image" src="https://github.com/user-attachments/assets/4207933c-9174-4ef5-a715-94b441961082" />

- Escalonador (*scheduler*)
  - Responsável por **selecionar o processo** (nas várias filas) que será alocado na CPU;
  - **Processos migram** entre as várias filas de escalonamento durante sua vida.
  <img width="619" height="130" alt="image" src="https://github.com/user-attachments/assets/c185ce84-750b-4681-94fa-d19592ae825d" />
  - Escalonador de Longo Prazo - *Long-Term*
    - **seleciona processos** e os **carrega na memória** para execução;
    - É executado com muito menos frequência (minutos);
    - Deve selecionar processos com cuidado a fim de balancear a carga do sistema;
    - Controla o **grau de multiprogramação**
      * Número de processos na memória;
      * Grau estável
        * Taxa média de criação de processos = Taxa média de saída de processos no sistema.
    - **Chamado** somente quando os **processos saem** do sistema;
    - Seleciona um boa combinação de
      * Processos I/O Bound;
      * Processos CPU Bound.
    - Muitos I/O Bound: Fila de prontos vazia;
    - Muitos CPU  Bound: Fila de I/O vazia; dispositivos sem uso.
  - Escalonador de LCurto Prazo - *Short-Term*
    - Seleciona processos a partir da **fila de prontos**
      * **Processos que concorrem á CPU.
    - A principal diferença entre escalonadores de Curto e Longo Prazo é a frequência de execução;
    - Deve selecionar novos processos com bastante frequência (milisegundos);
    - Deve ser bastante rápido pois pode-se perder mais de 10% do tempo somente com escalonamento.
  - Escalonador de Médio Prazo - *Medium-Term*
    - Nível intermediário de escalonamento;
    - Usa a idéia de que às vezes pode-se ter vantagens em remover o processo da memória, **reduzindo o nível de multiprogramação**
      * Posteriormente retorna ao ponto onde parou a execução.
    - Útil para
      * Melhorar a combinação de processos;
      * Mudança de requisitos durante a execução dos processos compromete a memória disponível.
    - *Swapping*.
  
## Operações nos processos
- Processos podem ser Criados ou Excluídos dinamicamente;
- **Criação de processos**
  - Um processo pode criar outros processos (system call create-process);
  - Processo criador: **Pai** (Parent);
  - Processo criado: **Filho** (Children);
  - Processo filho pode obter recursos de seu pai ou diretamente do SO
    - Se limitado a um subconjunto do Pai -> evita sobre-carga do sistema devido a criação de muitos processos.
  - Quando um processo cria outro, em **termos de execução**, pode ocorrer:
    - O pai executa concorrentemente com o filho;
    - O pai espera que os filhos terminem sua execução.
  - Quando um processo cria outro, em **relação ao espaço de memória**, pode ocorrer:
    - O processo filho é uma duplicata do pai;
    - O processo filho tem um programa carregado em si.
  - No Unix, um novo processo é criado com a chamada de sistema fork. Este novo processo é uma cópia do pai. Usando a chamada execve depois de um fork, é executado um novo programa que é carregado na memória, destruindo a imagem do processo que o chamou.
  - Árvore de processos no Unix.
    <img width="437" height="318" alt="image" src="https://github.com/user-attachments/assets/5cd5bdf8-cddb-4bd8-924e-f3513f2af5ee" />

- **Término de Processos**
  - O processo acaba quando é executada a última linha de comando do programa;
  - Este retorna dados a seu processo pai;
  - O pai pode terminar a execução do filho:
    - O filho excede a utilização de recursos;
    - A tarefa realizada pelo filho não é mais necessária;
    - O pai está sendo terminado.
- **Comandos**
  - fork
    - Permite a criação de um segundo fluxo de execução;
    - Fornecer o nome da subrotina ou programa;
    - Gerência do processador cria estruturas de dados necessárias e insere o processo na fila de prontos
      * O espaço de endereçamento deve ser igual ao do processo que o criou.
  - exit
    - Quem o executa é imediatamente terminado;
    - Executado por uma chamada de sistema.
  - wait
    - Um fluxo de execução espera outro terminar;
    - Ocorre o bloqueio do processo o qual é inserido em uma fila de processos bloqueados a espera do determinado processo.
  <img width="596" height="402" alt="image" src="https://github.com/user-attachments/assets/33e124a9-3559-4619-8663-cee0f2485d87" />
    <img width="424" height="346" alt="image" src="https://github.com/user-attachments/assets/cca49dea-91c8-4452-8a4e-8727063ec2e9" />

## Comunicação entre processos
- Trocas de Mensagens
  - Uso das primitivas de envio (*send*) e recebimento (*receive*).
- Sinais
  - São interrupções de software que notificam ao processador um evento que ocorreu;
  - Não permitem trocar dados;
  - Um processo, ao receber um sinal, pode:
    - Capturar;
    - Ignorar;
    - Mascarar (bloquear).

## Mais alguns conceitos...
### Programação Concorrente
<img width="678" height="329" alt="image" src="https://github.com/user-attachments/assets/8f4ca8be-d532-49d5-89ee-be20e1b7b59e" />

### Chaveamento de Contexto
<img width="662" height="386" alt="image" src="https://github.com/user-attachments/assets/899ecd84-9e18-40cb-aef8-69b6dcd9355c" />
