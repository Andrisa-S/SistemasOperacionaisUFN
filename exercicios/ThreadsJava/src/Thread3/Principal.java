package Thread3;

public class Principal extends Thread{
    static int contador;
    int i;

    public Principal(String str) {
        super(str);
    }

    public void run(){
        for(i = 0; i < 1000; i++){
            contador++;
        }
        System.out.println(getName() + " Último número: " + contador);
        System.out.println("Terminou!");
    }

    public static void main(String[] args) {
        Principal thread1 = new Principal(" Thread A ");
        Principal thread2 = new Principal(" Thread B ");

        thread1.run();
        thread2.run();
        System.out.println(contador);
    }
}

/* RESUMO RACE CONDITION
 Race Condition é um problema de concorrência que ocorre quando duas ou mais threads ou processos acessam e manipulam recursos compartilhados ao mesmo tempo, sem sincronização adequada. O resultado final passa a depender da ordem de execução, tornando o comportamento do sistema imprevisível e inconsistente.

 Nos sistemas operacionais, isso aparece principalmente em programas multithreaded, onde variáveis globais ou memória compartilhada são modificadas simultaneamente.
 */
