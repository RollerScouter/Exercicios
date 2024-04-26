package br.edu.up.relacoes.agregacao;

public class Motor {
    private Integer potencia;

    public Motor(Integer potencia) {
        this.potencia = potencia;
    }

    public Integer getPotencia() {
        return potencia;
    }

    public void setPotencia(Integer potencia) {
        this.potencia = potencia;
    }

    @Override
    public String toString() {
        return "Motor{" +
                "potencia=" + potencia +
                '}';
    }
}
