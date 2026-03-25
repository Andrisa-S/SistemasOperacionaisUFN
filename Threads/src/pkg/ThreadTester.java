/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg;

/**
 *
 * @author laboratorio
 */
public class ThreadTester {
    public static void main(String[] args) {
        PrintThread thread1, thread2, thread3, thread4;
        thread1 = new PrintThread("thread1");
        thread2 = new PrintThread("thread2");
        thread3 = new PrintThread("thread3");
        thread4 = new PrintThread("thread4");
        
        System.out.println("\nIniciando threads...");
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
        System.out.println("Threads iniciadas");
    }
}
