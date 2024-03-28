package br.edu.up;

import java.util.Scanner;

public class AnimalVirtual {

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.println("Nome do animal: ");
        var nome = scanner.nextLine();
        System.out.println("Familia do animal: ");
        var familia = scanner.nextLine();
        var animal = new Animal(nome, familia);
        int op;
        do {
            System.out.println("==============================");
            System.out.println("1- Comer");
            System.out.println("2- Correr");
            System.out.println("3- Dormir");
            System.out.println("4- Morrer");
            System.out.println("5- Detalhes");
            System.out.println("===============================");

            System.out.println("Informe o proximo comportamento do animal: ");
            op = scanner.nextInt();
            comportamento(op, animal);
        } while (animal.estado == true);
    }

    public static void comportamento (Integer op, Animal animal){
        switch (op) {
            case 1:
                animal.comer();
                break;
            case 2:
                animal.correr();
                break;
            case 3:
                animal.dormir();
                break;
            case 4:
                animal.morrer();
                break;
            case 5:
                animal.imprimirInformacoes();
                break;
            default:
                System.out.println("OPÇÃO INVALIDA!");
                break;
        }

    }
}
