package br.edu.up.exer;

import br.edu.up.exer.modelos.Animal;
import br.edu.up.exer.modelos.Cachorro;
import br.edu.up.exer.modelos.Gato;

public class Principal3 {
    public static void main(String[] args) {
        Animal animal = new Animal();
        Animal gato = new Gato();
        Animal cachorro = new Cachorro();

        animal.emitirSom();
        gato.emitirSom();
        cachorro.emitirSom();
    }
}
