package br.edu.up.exer.modelos;

public class Cheetah extends Cat{
    public Cheetah(Boolean health) {
        super(health);
    }
    public void run() {
        System.out.println("Cheetah is running!");
    }
}
