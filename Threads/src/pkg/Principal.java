/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg;

/**
 *
 * @author laboratorio
 */
class Principal extends Thread {

    public Principal (String str){
        super(str);
    }
    
    public void run(){
        for (int i = 0; i < 30; i++){
            System.out.println(i + "" + getName());
        }
        System.out.println(getName() + " TERMINOU! ");
    }
    
//    public static void main(String[] args) {
//        Principal Thread1 = new Principal(" Primeira ");
//        Principal Thread2 = new Principal(" Segunda ");
//        
//        Thread1.start();
//        Thread2.start();
//        
//        for (int i = 0; i < 20; i++){
//            System.out.println(i + "Thread Principal");
//        }
//        System.out.println("THREAD PRINCIPAL - Término da Execução");
//    }
    
    public static void main(String[] args) {
        Mensagem msg = new Mensagem();
        
        Thread t1 = new Thread(() ->{
            msg.esperarMensagem();
        });
        
        Thread t2 = new Thread(() -> {
            try{
                Thread.sleep(2000);
            } catch (InterruptedException e){
                e.printStackTrace();
            }
            msg.enviarMensagem();
        });
        
        t1.start();
        t2.start();
    }
}
