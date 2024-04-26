package br.edu.up.exer.modelos;

public class Cat {
    private Boolean health;

    public Cat(Boolean health) {
        this.health = health;
    }

    public Boolean isHealth() {
        return health;
    }

    public void run(){
        System.out.println("Cat is running!");
    }
}
