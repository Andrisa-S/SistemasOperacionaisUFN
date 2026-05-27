Aqui está um resumo estruturado para os tópicos da sua prova, baseado nos materiais fornecidos:

### 1. Sincronização de Processos
A programação concorrente envolve múltiplos processos ou *threads* que cooperam para realizar uma tarefa, compartilhando recursos como variáveis e estruturas de dados. No entanto, isso traz desafios importantes:

*   **Condição de Corrida (*Race Condition*):** Ocorre quando o valor de dados compartilhados depende da ordem exata de execução dos fluxos, gerando resultados incorretos.
    *   **Exemplo:** Se dois processos tentarem atualizar simultaneamente a variável `cont` (um incrementando e outro decrementando), a troca de contexto no nível das instruções de máquina (ex: registradores) pode fazer com que um valor substitua o outro, deixando o saldo de `cont` inconsistente. O mesmo ocorre ao tentar sacar um valor de uma conta bancária sem sincronização.
*   **Seção Crítica:** É a parte do código de um processo onde ocorre a manipulação de dados compartilhados. Ela **deve ser executada de forma mutuamente exclusiva**.
    *   **Requisitos para proteger a Seção Crítica:** Uma solução correta exige **Exclusão Mútua** (só um processo executa por vez), **Progresso** (processos fora da seção crítica não podem bloquear os outros) e **Espera Limitada** (há um limite de tempo para que um processo consiga entrar na sua seção).
*   **Problema do Produtor-Consumidor:** Um problema clássico onde um produtor insere itens em um *buffer* de tamanho limitado e um consumidor os retira. O produtor deve dormir se o *buffer* estiver cheio, e o consumidor deve dormir se estiver vazio.
    *   **Exemplo:** Um servidor de impressão. Editores de texto (produtores) enviam arquivos para a fila (*buffer*). O servidor (consumidor) organiza a fila e envia para a impressora.

---

### 2. Mecanismos de Sincronização
Para evitar as condições de corrida, os sistemas operacionais oferecem ferramentas para garantir a exclusão mútua e coordenar a execução:

*   **Spin-lock:** Um mecanismo suportado por hardware onde o processo fica em um *loop* (espera ocupada ou *busy-waiting*) testando uma variável ("fechadura") até que ela esteja livre.
    *   **Vantagem/Desvantagem:** É simples, mas desperdiça processamento já que o processo no *loop* ocupa a CPU. Útil apenas para seções críticas muito pequenas.
*   **Semáforos:** Criados por E. W. Dijkstra, são estruturas abstratas que mantêm um valor inteiro e uma fila de processos.
    *   **Operações:** **P (*wait/acquire*)** decrementa o valor. Se for negativo, bloqueia a *thread* e a coloca na fila. **V (*signal/release*)** incrementa o valor e, se houver processos na fila, acorda um deles.
    *   **Tipos:** Binários (valores 0 ou 1, controlam acesso exclusivo) e de Contagem (assumem qualquer valor, usados para controlar quantidade de recursos, como vagas livres em um *buffer*).
*   **Mutex:** Versão simplificada do semáforo, representada por apenas um bit (livre = 0, ocupado ≠ 0). Serve especificamente para exclusão mútua. Usa funções como `mutex_lock` para entrar na seção e `mutex_unlock` para sair.
*   **Monitores:** São estruturas de mais alto nível que encapsulam as variáveis compartilhadas e as rotinas (funções), garantindo que apenas um processo fique ativo no monitor em determinado instante.
    *   Eles utilizam **variáveis de condição** (operações `wait` e `signal`/`notify`) para suspender e acordar *threads* internamente.
    *   **Exemplo:** Em Java, a palavra reservada `synchronized` na declaração de um método transforma aquele bloco em um monitor, impedindo execuções simultâneas por outras *threads*.

---

### 3. Deadlock (Impasse)
Um *deadlock* ocorre quando um conjunto de processos está bloqueado porque **cada um espera por um recurso que está sendo segurado por outro processo do mesmo conjunto**. Consequentemente, nenhum deles consegue prosseguir.

*   **Exemplo Claro:** O Processo P1 alocou a fita e precisa da impressora. O Processo P2 alocou a impressora e precisa da fita. Ambos travam.

**Para ocorrer um *Deadlock*, 4 condições devem ser verdadeiras simultaneamente:**
1.  **Exclusão Mútua:** Os recursos envolvidos não podem ser compartilhados livremente.
2.  **Posse e Espera:** O processo já segura um recurso e está esperando por outro.
3.  **Não-preempção:** O recurso não pode ser retirado à força do processo; ele mesmo deve liberá-lo voluntariamente.
4.  **Espera Circular:** Forma-se um ciclo (ex: P0 espera P1, P1 espera P2, e P2 espera P0).

**Métodos para tratar Deadlocks:**
*   **Prevenção:** Impor regras estritas para eliminar, logo na arquitetura, pelo menos uma das quatro condições necessárias (como exigir que recursos sejam alocados todos de uma vez, ou em ordem específica de numeração).
*   **Impedimento (Evitar):** O sistema precisa de informação antecipada sobre os recursos que o processo usará no futuro. O sistema usa essas informações para aceitar ou rejeitar pedidos garantindo que o sistema fique sempre em um **"estado seguro"**.
*   **Detecção:** Permite que o *deadlock* aconteça, mapeando as alocações em um **Grafo de Espera** para procurar ciclos.
*   **Recuperação:** Após detectar o problema, o sistema quebra o ciclo **abortando processos** ou realizando a **preempção de recursos** (retirando o recurso à força e fazendo um *rollback* no processo que o perdeu).
