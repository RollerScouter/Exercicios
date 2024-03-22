package br.up.edu.printer;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ex02 {
    public static void main(String[] args) throws IOException {
        String path = "C:\\Users\\autologon\\Documents\\teste";
        File diretorio = new File(path);

        if (!diretorio.exists()) {
            diretorio.mkdir();
        }

        File arquivo = new File(diretorio, "informações.txt");
        if (!arquivo.exists()) {
            arquivo.createNewFile();

        }
        Scanner scanner = new Scanner(System.in);
        FileWriter file = new FileWriter(arquivo, true);
        PrintWriter writer = new PrintWriter(file);
        writer.println("ISBN do Livro: ");
        System.out.println("ISBN do Livro: ");
        writer.println(scanner.nextLine());
        writer.println("Nome do Livro: ");
        System.out.println("Nome do Livro: ");
        writer.println(scanner.nextLine());
        writer.println("Autor do Livro: ");
        System.out.println("Autor do Livro: ");
        writer.println(scanner.nextLine());
        writer.println("Genero do Livro: ");
        System.out.println("Genero do Livro: ");
        writer.println(scanner.nextLine());
        writer.println("Número de páginas do Livro: ");
        System.out.println("Número de paginas do Livro: ");
        writer.println(scanner.nextLine());


        writer.flush();
        writer.close();

    }
}

