import java.util.Scanner;

public class ex01 {

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);

        System.out.println("Matricula: ");
        var Matricula = scanner.nextLine();
        System.out.println("Nome: ");
        var Nome = scanner.nextLine();
        System.out.println("Primeira nota: ");
        var Nota1 = scanner.nextDouble();
        System.out.println("Segunda nota: ");
        var Nota2 = scanner.nextDouble();

        float notafinal = (float) (Nota1 + Nota2)/2;

        System.out.println("Matricula: "+ Matricula);
        System.out.println("Nome: " + Nome);
        if (notafinal >= 6){
            System.out.println("Aprovado: (x) Sim () Não");
        } else{
            System.out.println("Aprovado: () Sim (x) Não");            
        }
        System.out.println("Nota final: " + notafinal);
    }
}