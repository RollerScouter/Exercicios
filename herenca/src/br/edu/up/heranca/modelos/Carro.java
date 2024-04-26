package br.edu.up.heranca.modelos;

public class Carro extends Veiculo{
    private Integer porta;

    public Carro(String marca, String modelo, Integer anoFabricado, Integer porta) {
        super(marca, modelo, anoFabricado);
        this.porta = porta;
    }

    public Integer getPorta() {
        return porta;
    }

    public void setPorta(Integer porta) {
        this.porta = porta;
    }

    @Override
    public String toString() {
        return "Carro{" +
                "marca='" + super.getMarca() + '\'' +
                ", modelo='" + super.getModelo() + '\'' +
                ", anoFabricado=" + super.getAnoFabricado() + '\'' +
                ", porta=" + this.porta + " " +
                '}';
    }
}
