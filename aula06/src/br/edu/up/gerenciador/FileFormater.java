package br.edu.up.gerenciador;

import java.io.File;
import java.io.IOException;
import java.util.Formatter;

public class FileFormater {
    public static void main(String[] args) throws IOException {
        String path = "C:\\Users\\autologon\\Documents\\projetos\\root";
        File diretorio = new File(path);

        if (!diretorio.exists()) {
            diretorio.mkdir();
        }

        File arquivo = new File(diretorio, "bd2.txt");
        if (!arquivo.exists()) {
            arquivo.createNewFile();

        }
        Formatter formatter = new Formatter(arquivo);
        formatter.format("Aluno: Rhafael\n");
        formatter.format("Aluno: Rhafael\n");
        formatter.format("Aluno: Rhafael\n");

        formatter.flush();
        formatter.close();

    }

}
