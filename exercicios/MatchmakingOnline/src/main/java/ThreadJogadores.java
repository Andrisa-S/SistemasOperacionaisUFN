public class ThreadJogadores implements Runnable {
    // Nome do grupo de jogadores desta thread (ex: "Grupo A")
    private String grupo;

    // Referência para a fila compartilhada
    private FilaMatchmaking fila;

    // Quantidade de jogadores que esta thread irá criar
    private int quantidadeJogadores;

    // Contador global de IDs compartilhado entre instâncias
    private static int contadorId = 1;

    // Lock para garantir IDs únicos entre threads diferentes
    private static final Object lockId = new Object();

    public ThreadJogadores(String grupo, FilaMatchmaking fila, int quantidadeJogadores) {
        this.grupo = grupo;
        this.fila = fila;
        this.quantidadeJogadores = quantidadeJogadores;
    }

    @Override
    public void run() {

        // Nicknames fictícios para simular jogadores reais
        String[] nicknames = {
                "NightWolf", "SpiritKiller", "UmReto", "MoonOkami",
                "DriGamer", "MateusGames", "TeteuGamer", "Gutchola",
                "Bitchola", "GhostSniper", "FrostArrow", "LightBringer",
                "CrimsonAxe", "SilentWind", "ThunderClaw", "ArcaneEye"
        };

        for (int i = 0; i < quantidadeJogadores; i++) {

            try {

                // Gera um ID único com segurança entre threads
                int id;
                synchronized (lockId) {
                    id = contadorId++;
                }

                // Escolhe um nickname baseado no índice
                String nickname = nicknames[id % nicknames.length];

                Jogador jogador = new Jogador(id, nickname + "_" + grupo + (i + 1));

                // Insere na fila (bloqueia se estiver cheia)
                fila.entrarNaFila(jogador);

                // Pausa para simular intervalo real entre entradas de jogadores
                Thread.sleep(300);

            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Thread " + grupo + " interrompida.");
                return;
            }
        }

        System.out.println("[" + grupo + "] Todos os jogadores foram enviados para a fila.");
    }
}
