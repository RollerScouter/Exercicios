package br.edu.up.gerenciador;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class principal {
    public static void main(String[] args) throws IOException {
        String path = "C:\\Users\\autologon\\Documents\\projetos\\root";
        File diretorio = new File(path);

        if (!diretorio.exists()) {
            diretorio.mkdir();
        }

        File arquivo = new File(diretorio, "bd.txt");
        if (!arquivo.exists()) {
            arquivo.createNewFile();

        }
        FileWriter file = new FileWriter(arquivo, true);
        PrintWriter writer = new PrintWriter(file);

        writer.println("Aluno: Rhafael Costa");
        writer.println("Aluno: Pedro Henrique");
        writer.println("Aluno: Annamaria");

        writer.flush();
        writer.close();

    }
}

