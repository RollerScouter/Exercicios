package br.edu.up.relacoes;

import br.edu.up.relacoes.agregacao.Carro;
import br.edu.up.relacoes.agregacao.Motor;

public class Sistema {
    public void main(String[]args){
        Motor motor150 = new Motor(150);
        Motor motor570 = new Motor(570);
        Motor motor1200 = new Motor(1200);

        Carro sandero = new Carro("Renault Sandero", 150);

    }
}
