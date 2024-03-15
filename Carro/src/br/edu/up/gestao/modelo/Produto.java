package br.edu.up.gestao.modelo;
import java.util.Scanner;
public class Produto {
    public static String nome = "Bolacha";
    public static Double preco = 7.50;
    public static int quantidade = 20;
    static Scanner scanner = new Scanner(System.in);

    public static void quantidadeAtualizar(){
        System.out.println("Informe a nova quantidade do produto: ");
        quantidade = scanner.nextInt();

    }
    public static void precoTotal(){
        double precoAll = (quantidade*preco);
        System.out.println("O preço total dos produtos em estoque é: " + precoAll);
    }
}
