public class Principal {
    public static void main(String[] args) {

        System.out.println("=== SISTEMA DE MATCHMAKING ONLINE ===\n");

        // Fila compartilhada entre todos as threads
        FilaMatchmaking fila = new FilaMatchmaking();

        /*
            Configuração da simulação:
            - 3 grupos de jogadores, cada um com 4 jogadores
            - Total de 12 jogadores = 6 partidas
        */
        int jogadoresPorGrupo = 4;
        int totalPartidas = 6;

        // Criação das threads de jogadores (grupos diferentes chegando simultaneamente)
        Thread grupoA = new Thread(new ThreadJogadores("GrupoA", fila, jogadoresPorGrupo));
        Thread grupoB = new Thread(new ThreadJogadores("GrupoB", fila, jogadoresPorGrupo));
        Thread grupoC = new Thread(new ThreadJogadores("GrupoC", fila, jogadoresPorGrupo));

        // Criação da thread do servidor
        Thread servidor = new Thread(new ThreadServidor(fila, totalPartidas));

        // Inicia o servidor antes dos jogadores para ele já estar esperando
        servidor.start();

        // Inicia os grupos de jogadores simultaneamente
        grupoA.start();
        grupoB.start();
        grupoC.start();

        // Thread principal aguarda todas terminarem
        try {
            grupoA.join();
            grupoB.join();
            grupoC.join();
            servidor.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println("Thread principal interrompida.");
        }

        System.out.println("\n=== SIMULAÇÃO ENCERRADA ===");
    }
}
