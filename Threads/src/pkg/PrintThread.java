/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg;

/**
 *
 * @author laboratorio
 */
class PrintThread extends Thread {
    private int sleepTime;
    
    public PrintThread(String str){
        super(str);
        sleepTime = (int) (Math.random() * 5000);
        System.out.println(getName() + " dormira " + sleepTime + " ms...");
    }
    
    public void run(){
        try{
            System.out.println(getName() + " indo dormir.");
            Thread.sleep(sleepTime);
        } catch (InterruptedException e){
            System.out.println(e.toString());
        }
        System.out.println(getName() + " TERMINOU! ");
    }
}
