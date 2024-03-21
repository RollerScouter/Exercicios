package br.edu.up.gerenciador;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class contador {
    public static void main(String[] args) throws IOException {
        String path = "C:\\Users\\autologon\\Documents\\projetos\\root";
        File diretorio = new File(path);

        if (!diretorio.exists()) {
            diretorio.mkdir();
        }

        File arquivo = new File(diretorio, "numeros.txt");
        if (!arquivo.exists()) {
            arquivo.createNewFile();

        }
        FileWriter file = new FileWriter(arquivo);
        PrintWriter writer = new PrintWriter(file);
        for (int i = 1; i <= 10; i++){

            writer.println(i);
        }
        writer.flush();
        writer.close();
    }
}
