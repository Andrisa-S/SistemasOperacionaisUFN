# Sistemas Operacionais
## Estrutura
-------------------------------------

### Análise de um Sistema Operacional
- Serviços fornecidos;
- Interface fornecida a usuários e programadores;
- Componentes e interconexões.

------------------------------------

### Mecanismo de Interrupções
- Torna eficiente a interação do processador com os periféricos e permite E/S assíncrona;
- Sinalizar ocorrência de eventos;
- Tratador de interrupção;
- Interrupção pode ser ocasionada por hardware, software ou por uma exceção;
- Vetor de interrupção;
- Execução de interrupção;
  - Transfere o controle para o tratador (salva o contexto de execução);
  -  Desvia controle para o tratador;
  -  Retorna execução (restaura contexto de execução).
- Chamada de Sistema;
  - Processo usuário solicita serviços ao sistema operacional.

### Proteção
-  O sistema operacional deve garantir a correta utilização dos recursos computacionais e propiciar a execução das aplicações no computador;
-  Para isto, é necessário mecanismos de proteção para que as aplicações não consigam acessar o hardware diretamente e sim, que isto seja mediado pelo sistema operacional;
-  Há diferentes modos de execução (privilégios), que constituem o Modo Dual de operação:
  - Modo supervisor, privilegiado, sistema, monitor ou kernel;
  - Modo usuário.

#### Modo Dual de Operação
-  Arquitetura de processadores oferecem mecanismos para diferenciar dois modos de operação;
  - Modo Supervisor (privilegiado)
    -  Modo de execução sistema operacional (instruções privilegiadas);
    - Execução de todas as instruções do processador.
  - Modo Usuário
    -  Execução dos processos usuários;
    - Somente um subconjunto de instruções do processador, registradores e portas de E/S estão disponíveis.
    - Caso o código em execução tentar executar uma instrução não disponível, será gerada uma exceção.
  - Chaveamento de modos.
    - Interrupção (modo usuário -> modo supervisor);
    - Instrução (modo supervisor -> modo usuário).
------------------------------------------------------------
- Proteção de memória;
- Proteção de CPU.

### Chamadas ao Sistema

#### Controle de processo

#### Gerência de arquivos

#### Gerência de dispositivos

#### Manutenção de informações

#### Comunicação

----------------------------------------------

## Estrutura do Sistema
-  Sistema Operacional deve ser dividido em pequenos componentes e não ser um sistema monolítico;
-  Principais componentes:
  - Núcleo;
  - Drivers: códigos específicos para acessar os dispositivos físicos. Ex.: discos rígidos IDE, SCSI, portas USB, placas de vídeo.
  - Códigos de inicialização: reconhecer, testar e configurar os dispositivos instalados. Carregar o núcleo do SO e iniciar a execução.
  - Programas utilitários:  funcionalidades complementares do SO.
-  Como os componentes são combinados e interconectados
  - Estrutura simples;
  - Camadas;
  - Microkernels;
  - Módulos.

### Kernel do SO
-  É a parte do SO executada com interrupções desabilitadas e no modo privilegiado;
- Nos trechos críticos não há interrupção;
- O Kernel pode ser monolítico;
- O Kernel é um pequeno monitor monolítico que recebe o controle quando ocorrem chamadas ao sistema ou interrupções;
- Os serviços são implementados fora do kernel;
- Mantém o descritor do processo e implementa funções para sincronização e comunicação;
-  Pode ser microkernel ou monitor monolítico.

### Estrutura Simples
-  Sistemas sem estrutura bem definida.
  - Iniciaram pequenos, simples e limitados -> cresceram.

### Estrutura do Unix
-  O UNIX originalmente foi limitado pela funcionalidade de hardware;
-  Dividido em 2 partes:
  - Kernel;
  - Programas de sistema.

### Camadas
- Forma de modularização de um sistema;
- Uma camada de sistema operacional;
- As camadas são construídas de forma que somente utilizem os serviços das camadas de nível mais baixo;
- Menos eficientes devido à hierarquia de camadas; Permite controle maior do hardware, em relação à abordagem simples;
-  A primeira camada pode ser depurada sem preocupação com o resto do sistema, porque utiliza somente o hardware básico para implementar suas funções;
- **Dificuldade:** definição adequada das camadas;
- Tendem a ser *menos eficientes* que outros tipos -> em cada camada, os parâmetros podem ser modificados, os dados precisam ser transferidos... *custos* são acrescentados -> *maior tempo na chamada ao sistema.*
- OS/2;
  - Acrescentou camadas, operações multitarefas e em modo dual;
  - Não permite ao usuário acesso aos recursos de baixo nível;
  - Sistema operacional tem mais controle sobre o hardware e programas em execução.
- MULTICS;
- Windows NT (parcialmente)
  -  Implementa camada inferior de abstração do hardware (HAL – Hardware Abstraction Layer).

### Microkernel ou Micronúcleo
- Expansão do Unix, o kernel tornou-se grande e difícil de gerenciar;
- 1980 – Sistema Operacional Mach – Carnegie Mellon University;
- Fornecem
  -  Gerência mínima de memória e processos;
  -  Um recurso de comunicação entre programa do usuário e serviços que estão em execução também no espaço de usuário.
- Proporcionam
  - Facilidade de expansão do sistema -> novos serviços são adicionados ao espaço do usuário;
  - Modificações facilitadas no kernel;
  - Maior segurança e confiabilidade em caso de falhas.
-  Possibilitar a comunicação entre o programa cliente e os diversos serviços disponibilizados;
-  Sistemas baseados no kernel do Mach
  - UNIX Digital;
  - Apple MacOS X.

### Módulos
- POO -> Kernel modular;
- Há um kernel básico e módulos carregáveis dinamicamente;
- A interface entre os módulos é claramente definida;
- Solaris, Linux, Mac OS X;
- Flexibilidade;

### Máquina Virtual 
- VM da IBM;
- O SO possibilita que um processo “possua” seu próprio processador com sua própria memória;
- Cada processo recebe uma cópia do computador básico;
- O computador físico compartilha seus recursos para que isto ocorra;
- Atualmente, usada para portabilidade dos sistemas;
- Vantagens:
  - Aos usuários e desenvolvedores;
  - Isolamento dos recursos da Máquina Virtual;
  - Testes.
- Desvantagens:
  - Difícil de implementar.

-------------------------------------------------

## Considerações Finais
- Abordagens
  - Camadas;
  - Microkernel;
  - Módulos;
  - Máquina Virtual.
  não são mutualmente exclusivas.
