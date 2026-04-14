package Thread1;

public class Principal extends Thread {
    private int sleepTime;

    public Principal(int sleepTime) {
        this.sleepTime = sleepTime;
    }

    public void run(){
        try{
            for(int i = 0; i <= 5; i++){
                System.out.println(i);
                Thread.sleep(sleepTime);
            }
        } catch (InterruptedException e) {
            System.out.println(e.toString());
        }
        System.out.println("Terminou!");
    }

    public static void main(String[] args) {
        Principal Thread1 = new Principal(1000);

        Thread1.run();
    }
}
