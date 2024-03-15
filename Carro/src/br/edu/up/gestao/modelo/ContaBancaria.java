package br.edu.up.gestao.modelo;
import java.util.Scanner;
public class ContaBancaria {
    public static String titular = "Pedro";
    public static int saldo = 1000;
    static Scanner scanner = new Scanner(System.in);

    public static void depositarSaldo(){
        System.out.println("Insira o valor a ser depositado: ");
        int valor = scanner.nextInt();
        saldo = saldo + valor;
        System.out.println("Novo saldo: "+ saldo);

    }

    public static void sacarSaldo(){
        System.out.println("Insira o valor a ser sacado: ");
        int valor = scanner.nextInt();
        saldo = saldo - valor;
        System.out.println("Novo saldo: "+ saldo);

    }
}
