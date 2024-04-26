package br.edu.up.exer.modelos;

public class Lion extends Cat {
    public Lion(Boolean health) {
        super(health);
    }

    public void run() {
        System.out.println("Lion is running!");
    }
}
