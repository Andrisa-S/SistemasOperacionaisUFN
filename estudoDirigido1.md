# Estudo Dirigido 1 - 18/02/26

### 1.  Caracterize um sistema de computação moderno
	CPU, memória principal, controlador de memória, memória secundária, controladores de dispositivos, periféricos. Conectividde com rede, gráficos e vídeo.

### 2.  Quais a etapas de inicialização do computador?
	a) Execução da BIOS (teste de hardware)
	b) Carregamento do Bootloader
	c) Primeiro processo do sistema operacional é iniciado (init).
	d) Espera por um evento.

### 3.  O que é interrupção? Como os Sistemas Operacionais tratam as interrupções?
	Sinal que informa a CPU que um evento ocorreu. O sistema operacional pode responder a uma mudança no status do dispositivo notificando os processos que estão à espera desses eventos.
	a) Pausa do processamento
	b) N° IRQ - Tratador de interrupções (SO)
	c) Chaveamento/troca de contexto
	d) Buscar na tabela ou vetor de interrupção o endereço da rotina para tratar a interrupção
	e) Carregar a rotina e tratar a interrupção

### 4.  Defina I/O síncrona e I/O assíncrona. Qual permite melhor uso da CPU?
	**Input/Output (entrada/saída).** 
	I/O síncrona: mantém a CPU sincronizada, impossibilitando outras tarefas e desperdiçando CPU.
	I/O assíncrona: permite outras tarefas, melhorando o desempenho multiprogramação.

### 5.  Qual a finalidade da DMA – Direct Memory Access?
	O DMA aprimora técnicas habilitando dispositivos e controladores a transferir blocos de dados de e para a memória principal, o que libera o processador para executar instruções de software.

### 6.  Como funciona a RAM? Qual o ciclo básico de execução de uma instrução?
	a RAM **(Random Access Memory)**, é uma memória volátil de acesso aleatório, no sentido que processos podem acessar localizações de dados em qualquer ordem.
	Ciclo básico de execução de uma instrução:
		a) Buscar uma instrução na RAM
		b) Decodificar a instrução
		c) Buscar os operandos na RAM
		d) Executar a instrução
		e) Armazenar os dados na RAM
		f) Buscar o endereço da próxima instrução (continuidade do ciclo)

### 7. Caracterize a estrutura de armazenamento de um sistema de computação.
	Registradores compõem a memória mais veloz e mais cara, cache, em seguida vem a memória principal/real/física, composta por por DDR, DRAM, etc. (meios voláteis), e depois os armazenamentos secundário/permanente e terciário (disco rígido, fita, CDs, DVDs, etc.).

### 8.  Em que consiste o uso de cache?
	Memória intermediária/auxiliar, inclui os dados recentemente utilizados. Visa compatibilizar velocidade da CPU e da RAM.

### 9.  Caracterize os diferentes tipos de proteção de hardware suportados em um sistema de computação
	**Modo Dual de Operação** (processador) -
		Modo superior/monitor/kernel (todas as instruções do processador podem ser executadas)
		Modo usuário (algumas instruções disponíveis)
	**I/O** - Instruções privilegiadas
	**CPU** - Temporizador de hardware, que periodicamente interrompe a CPU
	**Memória principal** -
		Proteção do espaço de endereçamento de cada tarefa (2 registradores: registrador base - 1° endereço da tarefa na memória. E registrador limite - tamanho da tarefa)
		MMU - Unidade de Gerência de Memoria
	

