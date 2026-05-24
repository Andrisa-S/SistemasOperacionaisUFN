import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class FilaMatchmaking {
    // Capacidade máxima da fila de espera
    private static final int CAPACIDADE = 5;

    // Fila compartilhada entre as threads de jogadores e o servidor
    private BlockingQueue<Jogador> fila = new ArrayBlockingQueue<>(CAPACIDADE);

    /**
     * Insere um jogador na fila de espera.
     *
     * Se a fila estiver cheia, a thread que chamou este método
     * será bloqueada automaticamente até que um espaço fique disponível.
     *
     * @param jogador o jogador a ser inserido
     */
    public void entrarNaFila(Jogador jogador) throws InterruptedException {
        fila.put(jogador); // bloqueia se a fila estiver cheia
        System.out.println("Jogador " + jogador.getNickname() + " entrou na fila. "
                + "[Fila: " + fila.size() + "/" + CAPACIDADE + "]");
    }

    /**
     * Retira um jogador da fila de espera.
     *
     * Se a fila estiver vazia, a thread que chamou este método
     * será bloqueada automaticamente até que um jogador entre.
     *
     * @return o próximo jogador da fila
     */
    public Jogador retirarDaFila() throws InterruptedException {
        return fila.take(); // bloqueia se a fila estiver vazia
    }

    /**
     * Retorna o número atual de jogadores na fila.
     */
    public int tamanho() {
        return fila.size();
    }
}
