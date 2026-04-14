package Thread4;

public class Principal extends Thread {
    int download;

    public Principal() {
    }

    public void run(){
        try {
            for(int i = 0; i <= 10; i++) {
                System.out.println(download + "%");
                Thread.sleep(500);
                download+=10;
            }
            System.out.println("Download concluído com sucesso!");
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    static void main() {
        Principal thread = new Principal();

        thread.start();
    }
}
