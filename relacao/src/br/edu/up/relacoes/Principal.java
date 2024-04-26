package br.edu.up.relacoes;

import br.edu.up.relacoes.associacao.Aluno;
import br.edu.up.relacoes.associacao.Turma;

import java.util.ArrayList;

public class Principal {

    public static void main(String[] args){
        Turma turmaJava = new Turma("Desenvolvimento Java");
        Turma turmaRust = new Turma("Desenvolvimento Rust");


        for (int i = 1; i<=5; i++){
            Aluno aluno = new Aluno("Aluno"+ i);
            System.out.println("Turma: " + aluno.getTurma());

            if(i % 2 == 0){
                turmaJava.adicionarAluno(aluno);
                System.out.println("Turma: " + aluno.getTurma());
                continue;
            }

            turmaRust.adicionarAluno(aluno);
            System.out.println("Turma: " + aluno.getTurma());
        }
\
        System.out.println("Total de aluno: " + turmaRust.quantidadeAluno());
        System.out.println("Total de aluno: " + turmaJava.quantidadeAluno());
    }
}
