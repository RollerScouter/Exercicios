package br.edu.up;

public class Animal {

    final double CALORIAS_MAX = 1000.00;

    final double CALORIAS_MIN = 0;

    final Integer idade_max = 11;

    // Especie
    public static String nome;
    // Idade
    public int idade;
    // Calorias
    public double calorias;
    // Familia
    public String familia;
    // Estado = Vivo ou Morto
    public boolean estado;

    public int nroMaximoCorridaSseguidas = 0;

    public int atividadesRealizadas = 0;

    // Nascer = Contrutor
    public Animal(String nome, String familia){
        this.nome = nome;
        this.familia = familia;
        this.idade = 0;
        this.calorias = 100.00;
        this.estado = true;

    }
    public void comer(){
        this.calorias += 250;
        this.nroMaximoCorridaSseguidas = 0;
        this.estavivo();
        this.precisaDormir();

    }
    public void morrer(){
        this.estado = false;

    }
    public void dormir(){
        this.calorias -= 50;
        this.idade ++;
        this.nroMaximoCorridaSseguidas = 0;
        this.atividadesRealizadas = 0;
        this.estavivo();

    }
    public void correr(){
        this.calorias -= 100;
        this.nroMaximoCorridaSseguidas++;
        this.atividadesRealizadas++;
        this.estavivo();
        this.precisaDormir();
        this.precisaComer();

    }

    public void estavivo(){
        if (this.idade > idade_max || this.calorias > CALORIAS_MAX || this.calorias <= CALORIAS_MIN){
            this.estado = false;
            System.out.println("Seu bichinho morreu!");

        }

    }

    public void precisaDormir(){
        if (atividadesRealizadas >= 5){
            System.out.println("Vou dormir!");
        this.dormir();

        }
    }

    public void precisaComer(){
        if (nroMaximoCorridaSseguidas >= 3){
            System.out.println("Vou comer!");
            this.comer();

        }
    }
    public void imprimirInformacoes(){
        System.out.println("Nome: " + this.nome);
        System.out.println("Estado: " + this.estado);
        System.out.println("Familia: " + this.familia);
        System.out.println("Idade: " + this.idade);
        System.out.println("Calorias: " + this.calorias);

    }

    // Comer = +250 calorias
    // Correr = -100cal
    // Dormir = -50cal
    // Morrer

    //se o animal fizer 11 anos ele morre
    //se ele ficar com 0 ou menos calorias
    //se ele ficar com mais de 1000 calorias ele morre
}
