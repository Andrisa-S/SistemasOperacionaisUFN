public class ThreadServidor implements Runnable {
    // Referência para a fila compartilhada
    private FilaMatchmaking fila;

    // Quantidade total de partidas que o servidor deve organizar
    private int totalPartidas;

    public ThreadServidor(FilaMatchmaking fila, int totalPartidas) {
        this.fila = fila;
        this.totalPartidas = totalPartidas;
    }

    @Override
    public void run() {

        System.out.println("[SERVIDOR] Servidor de matchmaking iniciado. "
                + "Aguardando jogadores...\n");

        int partidasRealizadas = 0;

        while (partidasRealizadas < totalPartidas) {

            try {

                System.out.println("[SERVIDOR] Aguardando jogador 1...");

                // Retira o primeiro jogador da fila (bloqueia se vazia)
                Jogador jogador1 = fila.retirarDaFila();

                System.out.println("[SERVIDOR] Aguardando jogador 2...");

                // Retira o segundo jogador da fila (bloqueia se vazia)
                Jogador jogador2 = fila.retirarDaFila();

                // Exibe o início da partida
                partidasRealizadas++;
                System.out.println("\n========================================");
                System.out.println("  PARTIDA " + partidasRealizadas + " INICIADA!");
                System.out.println("  " + jogador1.getNickname()
                        + "  VS  " + jogador2.getNickname());
                System.out.println("========================================\n");

                // Simula a duração da partida
                Thread.sleep(1500);

                System.out.println("[SERVIDOR] Partida " + partidasRealizadas
                        + " encerrada. Fila atual: " + fila.tamanho() + " jogador(es).\n");

            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("[SERVIDOR] Servidor interrompido.");
                return;
            }
        }

        System.out.println("[SERVIDOR] Todas as " + totalPartidas
                + " partidas foram realizadas. Servidor encerrado.");
    }
}
