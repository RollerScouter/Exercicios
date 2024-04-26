package br.edu.up.heranca;

import br.edu.up.heranca.modelos.Carro;
import br.edu.up.heranca.modelos.Moto;
import br.edu.up.heranca.modelos.Veiculo;

import java.util.ArrayList;
import java.util.List;

public class Principal {
    public static void main(String[] args) {
        Carro meuCarro = new Carro("Fiat", "Argus", 2024, 4);

        Moto minhaMoto = new Moto("Honda", "CG 150", 2016, 1);

        List<Veiculo> veiculos = new ArrayList<>();
        veiculos.add(meuCarro);
        veiculos.add(minhaMoto);

        for (Veiculo v: veiculos){
            if (v instanceof Carro){
                System.out.println("Meu carro é: " + v.getModelo());
                continue;
            }
            System.out.println(v);
        }
    }
}
