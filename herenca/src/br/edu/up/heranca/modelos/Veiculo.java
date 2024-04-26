package br.edu.up.heranca.modelos;

public class Veiculo {
    public String marca;
    private String modelo;
    private Integer anoFabricado;

    public Veiculo(String marca, String modelo, Integer anoFabricado) {
        this.marca = marca;
        this.modelo = modelo;
        this.anoFabricado = anoFabricado;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public Integer getAnoFabricado() {
        return anoFabricado;
    }

    public void setAnoFabricado(Integer anoFabricado) {
        this.anoFabricado = anoFabricado;
    }

    @Override
    public String toString() {
        return "Veiculo{" +
                "marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                ", anoFabricado=" + anoFabricado +
                '}';
    }
}
