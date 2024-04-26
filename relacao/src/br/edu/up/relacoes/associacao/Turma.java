package br.edu.up.relacoes.associacao;

import java.util.ArrayList;
import java.util.List;

public class Turma {
    private String nome;
    private List<Aluno> alunos;

    public Turma(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

//    public List<Aluno> getAlunos() {
//        return alunos;
//    }
//
//    public void setAlunos(List<Aluno> alunos) {
//        this.alunos = alunos;
//    }

    public void inicializarListaAluno(){
        if(this.alunos == null){
            this.alunos = new ArrayList<>();
        }
    }

    public void adicionarAluno(Aluno aluno){
        this.inicializarListaAluno();
        this.alunos.add(aluno);
        aluno.setTurma(this);

//        if(this.nome != aluno.getTurma().getNome()){
//            return false;
//        }
//        this.alunos.add(aluno);
//        return true;
    }
    public int quantidadeAluno(){
        return this.alunos.size();
    }

    @Override
    public String toString() {
        return "Turma{" +
                "nome='" + nome + '\'' +
                ", alunos=" + alunos +
                '}';
    }
}
