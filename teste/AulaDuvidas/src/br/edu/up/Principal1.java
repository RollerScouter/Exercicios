package br.edu.up;

import java.util.Scanner;

public class Principal1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] sequencia = new int[5];
        for(int i = 0; i < 5; i++){
            System.out.println("Informe um numero:");
            sequencia[i] = scanner.nextInt();
        }
        int soma = 0;
        for(int i = 0; i < 5; i++){
            soma = soma + sequencia[i];

        }
        double media = soma/5;
        for(int i = 0; i < 5; i++ ){
            if(sequencia[i] > media){
                System.out.println(sequencia[i]);
                System.out.println("MAIOR!");
            } else if(sequencia[i] < media){
                System.out.println(sequencia[i]);
                System.out.println("MENOR!");
            }
            else {
                System.out.println(sequencia[i]);
                System.out.println("Igual!");
            }
        }


    }
}