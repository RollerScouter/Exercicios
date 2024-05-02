package br.edu.up.modelos;

import java.util.List;

public class Sessao {
    private String horario;
    private boolean tipo3D;
    private boolean tipoDublado;
    private List<Filme> filmes;
    private List<Sessao> sessoes;

    public Sessao(boolean tipo3D, String horario, boolean tipoDublado) {
        this.tipo3D = tipo3D;
        this.horario = horario;
        this.tipoDublado = tipoDublado;
    }


}
