# Threads

- Processo
  - Um único fluxo de execução
  - Espaço de endereçamento, descritores de arquivos abertos, permissões de acesso, quotas...
- Threads
  - Múltiplos fluxos de execução
  - Multithreading -> mesmo espaço de endereçamento

<img width="850" height="253" alt="{68FE7ED0-7B6A-404A-91F3-F85BDD6814BF}" src="https://github.com/user-attachments/assets/239f8988-6816-481e-a20b-7dc46bb74aea" />

- Um fluxo de instrução é implementado através do Contador de Programa (PC) e do Stack Pointer (SP)
- Estruturas comuns compartilhadas entre os threads:
  - Código;
  - Dados;
  - Descritor de processo.

  ## Vários Fluxos de Execução (threads)
  - Vários fluxos de execução em um único processo
  <img width="376" height="188" alt="image" src="https://github.com/user-attachments/assets/c59724e4-5cb1-41bb-87c9-088f46be8796" />

- Processo leve
- Unidade básica de utilização da CPU
- Existem no interior de um processo

<img width="696" height="179" alt="image" src="https://github.com/user-attachments/assets/6b5ee7cd-c870-4cfd-81d6-7ad293635fd2" />

- Aplicações em PCs são multithreading
  - Thread único
    - Um cliente de cada vez
  - Multithread
    - Aceita requisições de vários clientes
  - Navegador Web
  - Servidor Web

  ## Benefícios do Uso de Threads
  - Capacidade de Resposta
    - Navegador Web
  - Compartilhamento de Recursos
    - Mesmo espaço de endereço do processo
    - Memória, recursos do processo que pertence
  - Economia
    - Troca de contexto de threads (alocação de memória e recursos) x processos
  - Aplicações multiprocessador
    - Paralelismo

  ## Threads de Usuário
  - Implementadas através de biblioteca ligada ao programa do usuário (Threads de usuário ou do nível do usuário)
  - Visíveis ao programador e desconhecidos do Kernel
  - Gerenciamento (criação/escalonamento) através de bibliotecas de threads
    - Pthreads Posix
    - C-threads Mach
    - threads Solaris
  - Gerenciamento mais rápido (Kernel não envolvido)

  ## Threads de Kernel
  - O SO suporta diretamente o conceito de Thread
    - A gerência do SO é voltada ao conceito de thread
  - Gerenciamento através do Kernel
  - São escalonados para execução nos vários processadores
  - Mais lentos
  - Suportadas diretamente pelo SO
  **Os SO fornecem suporte a *threads* de usuário e de kernel**

  ## Modelos de *Multithreading*
  * N:1 Muitos-para-um (many-to-one)
  * Gerenciamento de threads é feito no espaço do usuário (aplicação)
    - São implementadas no espaço do usuário (uso de biblioteca ligada ao programa)
    - API para uso de threads
  * Chaveamento de Contexto mais rápido
  * Menor custo para criação/destruição
  * O SO divide o tempo entre os processos
    - São manipuladas através de um único fluxo de instrução pertence a um processo
      
    - <img width="172" height="191" alt="image" src="https://github.com/user-attachments/assets/ceb74061-af76-4421-b630-db5ba9036249" />

  - A troca de contexto entre threads é feita no modo usuário pelo escalonador embutido na biblioteca
  - Se um thread está efetuando E/S, acontece o bloqueio de todas as threads do sistema
  - Não é possível utilizar multiprocessadores
  - Um thread é escalonado de cada vez

  * 1:1 Um-para-um (one-to-one)
    - Maior concorrência
    - Threads a nível do sistema
      - O sistema operacional mantém informações sobre processis e threads
    - Maior custo de gerenciamento
      - Exigem chamadas ao SO
      - Troca de contexto exige a intervenção do SO
      - <img width="183" height="186" alt="image" src="https://github.com/user-attachments/assets/f6119a69-2c11-4e2e-a54b-0e839c74945f" />
    - É possível a execução pararela (ambiente multiprocessado)
    - Permite sobrepor operações de processamento em I/O
    - Desempenho da aplicação
    - Depende número de threads suportados pelo sistema
    - Win NT, OS/2
      <img width="521" height="346" alt="image" src="https://github.com/user-attachments/assets/02106b53-3383-47b1-b747-1e21ed1ea45b" />

  * M:N Muitos-para-muitos (many-to-many)
    - Combina dos modelos N:1 e 1:1
    - M threads do usuário
    - N threads do SO
    - Multiplexa threads de usuários em um número menor ou igual de threads de kernel
    - Escalonamento de 2 níveis
      - Nível de usuário
      - Nível de sistema
      - <img width="169" height="237" alt="image" src="https://github.com/user-attachments/assets/f23003b0-fe44-4361-92b9-c42c2a1d2c2d" />
    - É possível criar tantos threads quantos forem necessários
    - Há um número de threads específico por aplicação ou máquina
    - Bloqueio -> escalonar outra para execução
    - Há paralelismo
    
    <img width="474" height="341" alt="image" src="https://github.com/user-attachments/assets/1ab84ecc-c235-456d-a3dd-34fcadfcf330" />

    ## Vantagens de *Multithreading*
    - Threads x Processos
      - Tempo de criação/destruição
      - Troca de contexto
      - Threads compartilham o mesmo espaço de endereçamento do processo que as criou, assim é possível o compartilhamento de memória sem a interação com o núcleo do sistema.

# Threads Java

## Introdução
- Pode-se especificar fluxos de execução (threads), designando uma parte de um programa que pode ser executado simultaneamente com outras threads.
- *Multithreading* é parte da própria linguagem (pacote java.lang)
- Cada thread tem uma prioridade
- Há duas formas para uso de threads:
  - Criar uma subclasse da classe *Thread* (herança) e reescrever o método run()
    - A classe *Thread* implementa a interface *Runnable*
    - O método *run* é o "Corpo" da *Thread*
  - Criar uma classe que implementa a interface
    - *Runnable*

  ### Classe Thread
  - Alguns métodos
    - Construtores
    - run()
    - start()
    - sleep()
    - join()

 ### Estados de Threads
 <img width="588" height="405" alt="image" src="https://github.com/user-attachments/assets/02b40cbf-39dd-4a08-acd2-68803bcffdf7" />

- Exemplo 1:
  - <img width="575" height="369" alt="image" src="https://github.com/user-attachments/assets/dedf26f5-9db6-4ede-b92a-1d8283cbc44b" />
- Exemplo 2:
  - <img width="647" height="335" alt="image" src="https://github.com/user-attachments/assets/54a0e5be-6645-435f-9a8f-89abda7fba58" />
  - <img width="575" height="317" alt="image" src="https://github.com/user-attachments/assets/0e3e1d12-7760-4883-b999-dcc3aa5f46c1" />
- Exemplo 3:
  - <img width="609" height="379" alt="image" src="https://github.com/user-attachments/assets/f18156ef-aaef-475b-8897-cff256e175a8" />
  - <img width="427" height="387" alt="image" src="https://github.com/user-attachments/assets/dba07bc6-c5e5-4c6e-8a3c-1230d7c496c2" />

# POSIX Threads

- POSIX Threads, ou Pthreads, é um padrão estabelecido pela IEEE em 1995 que define uma interface padronizada para a criação e gerenciamento de threads.
- Esse padrão é amplamente utilizado em sistemas operacionais baseados em Unix e Linux, permitindo a execução concorrente de múltiplos fluxos de execução dentro de um mesmo processo.
- Para utilizar Pthreads em programas escritos em linguagem C, é necessário incluir a biblioteca por meio da diretiva #include <pthread.h>.
- As principais funções da biblioteca estão relacionadas à criação, ao término e à sincronização de threads, destacando-se o uso de pthread_create, pthread_exit e pthread_join.
- A seguir, será apresentado um exemplo prático de criação e manipulação de threads utilizando Pthreads.

  ## Criação de Threads
  - A função pthread_create é responsável por criar uma nova thread, permitindo a execução concorrente dentro do programa.
  - Seu protótipo recebe quatro parâmetros: o identificador da thread, os atributos (que podem ser definidos como padrão com NULL), a função que será executada pela thread e o argumento que será passado para essa função.
    - #include <pthread.h>
      - int pthread_create (pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);

  ## Término de Threads
  - A função pthread_exit é utilizada para finalizar a execução de uma thread, podendo retornar um valor que posteriormente pode ser recuperado por outra thread.
  - Por fim, a função pthread_join é responsável por fazer com que uma thread aguarde o término de outra, garantindo sincronização entre elas; caso haja um valor de retorno, este pode ser armazenado para uso posterior.
  - Essas funções são fundamentais para o controle do ciclo de vida e da coordenação entre threads em aplicações concorrentes.
    - #include <stdlib.h>
      - void pthread_exit (void *retval);

  ## Espera
  - A função pthread_join suspende a execução da thread que a chamou até que a thread especificada como argumento seja finalizada.
  - Esse mecanismo é utilizado para sincronizar a execução entre threads, garantindo que uma só continue após a conclusão da outra.
  - Caso a thread finalizada retorne algum valor diferente de nulo, esse valor pode ser recuperado e armazenado por meio do parâmetro thread_return.
    - #include <stdlib.h>
      - int pthread_join (pthread_t th, void **thread_return);









