package br.edu.up.gestao.modelo;

public class Pessoa {
    public static String nome = "Pedro";
    public static int Idade = 20;
    public static double Altura = 1.89;

    public static void imprimirPessoa(){
        System.out.println("Nome: "+ nome);
        System.out.println("Idade: " + Idade);
        System.out.println("Altura: "+ Altura);
    }
    public static void idadeVerificacao(){
        if (Idade >= 18){
            System.out.println("Maior de idade!");
        }else{
            System.out.println("Menor de idade!");
        }
    }
}
