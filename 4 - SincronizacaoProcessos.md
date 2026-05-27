# Sincronização de Processos
----------------------
## Programação Concorrente

  * Caracteriza-se pela execução de vários processos que cooperam entre si para realização de uma determinada tarefa;
  * Um programa executado por um único processo é dito programa sequencial;
  * Um programa concorrente possui vários fluxos de execução de instruções (vários fluxos de controle) e há necessidade de trocas de dados por estes fluxos.
  * Nas arquiteturas com múltiplos processadores na execução de um programa concorrente, acontece o paralelismo real
    * os vários processos ou threads são escalonados aos diferentes processadores, tornando a execução paralela (simultânea).
  * Nas arquiteturas monoprocessador, a execução de um programa concorrente acontece alternadamente
    * os diferentes processos ou threads são escalonados à mesma CPU e não executam simultaneamente. Há um paralelismo aparente.
  * A motivação para o uso da programação concorrente se dá por ela:
    * permitir a exploração do paralelismo real existente em máquinas multiprocessadoras, consequentemente, o aumento de desempenho da aplicação;
    * permitir realizar operações simultâneas de processamento e E/S (entrada/saída), ou seja, enquanto um fluxo de execução de instruções realiza operações de CPU, outro(s) executam operações de entrada e saída.
      * Isso também possibilita a obtenção de desempenho nas aplicações, diminuindo a ociosidade do processador enquanto operações de E/S são realizadas.
  * Em relação à programação sequencial, a programação concorrente é mais complexa:
    * Há necessidade de projetar e implementar as operações dos diferentes threads/processos executando concorrentemente, de forma que os dados comuns a eles mantenham a consistência, os processos/threads mantenham a execução (não fiquem em espera indefinida) e o resultado final da aplicação seja correto, independente da velocidade de execução dos processos;
  * A depuração de um programa concorrente é tarefa árdua comparada à execução sequencial.

## Processos cooperativos

  * **Processos Concorrentes** que podem afetar ou ser afetados pela execução uns dos outros;
  * São processos que cooperam para a realização de determinada atividade;
  * Podem compartilhar diretamente o mesmo espaço de endereçamento lógico (dados e código);
  * Por serem concorrentes, pode acontecer inconsistência ao serem acessados os dados compartilhados.

## Problema do Produtor-Consumidor

  * A programação concorrente implica no compartilhamento de recursos, como variáveis, estruturas de dados, registros, arquivos, bancos de dados...
  * O acesso aos recursos compartilhados deve ser feito mantendo-se o correto e coerente estado do sistema.
  * O problema do compartilhamento de recursos pode ser exemplificado com um Problema Clássico de Sincronização em sistemas operacionais, chamado:
    * Problema do Produtor-Consumidor ou Problema do Buffer Limitado (bounded buffer).
  * Segundo Silberschatz (2008), o Problema do Produtor-Consumidor possui:
    * um buffer de tamanho limitado compartilhado entre os processos;
    * há um processo produtor que insere um item no buffer a cada execução;
    * há um processo consumidor que remove um item do buffer a cada execução;
    * há uma variável inteira (count) compartilhada entre os processos que é utilizada para contar quantos itens existem no buffer.
    <img width="676" height="274" alt="image" src="https://github.com/user-attachments/assets/2914bed7-215c-4045-afc9-5b3cd668d804" />
  * Este problema mostra uma relação entre processos, bastante comum em sistemas operacionais.
  * Como exemplo, pode-se citar um servidor de impressão:
    * Os vários processos usuários como editores de texto, planilhas, aplicativos (produtores) produzem impressões e as enviam para uma fila (o buffer limitado) do servidor de impressão.
    * O processo consumidor (servidor de impressão) organiza a fila, lê as impressões e as encaminha para a impressora.

## Condição de Corrida


## Seção Crítica


### Requisitos de uma solução à Seção Crítica


## Mecanismos de Sincronização
