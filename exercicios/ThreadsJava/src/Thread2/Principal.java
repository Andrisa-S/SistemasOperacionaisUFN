package Thread2;


public class Principal extends Thread{

    public Principal(String str) {
        super(str);
    }

    public void run(){
        try{
            for(int i = 0; i <= 5; i++){
                System.out.println(i + "" + getName());
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(e.toString());
        }
        System.out.println("Terminou!");
    }

    public static void main(String[] args) {
        Principal thread1 = new Principal(" Thread A ");
        Principal thread2 = new Principal(" Thread B ");

        thread1.start();
        thread2.start();
    }
}
