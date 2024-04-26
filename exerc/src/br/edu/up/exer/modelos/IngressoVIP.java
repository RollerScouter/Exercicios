package br.edu.up.exer.modelos;

public class IngressoVIP extends Ingresso{
    private Double valorAdicional;

    public IngressoVIP(double valor, Double valorAdicional) {
        super(valor);
        this.valorAdicional = valorAdicional;
    }

    public Double getValorAdicional() {
        return valorAdicional;
    }

    public void setValorAdicional(Double valorAdicional) {
        this.valorAdicional = valorAdicional;
    }

    @Override
    public String toString() {
        var novoValor = getValor() + this.valorAdicional;
        return "IngressoVIP{" +
                "valor=" + novoValor +
                '}';
    }
}
