package br.edu.up.gestao.modelo;

public class Retangulo {
    public static int altura = 6;
    public static int largura = 8;

    public static void areaRetangulo(){
        System.out.println("Área do retangulo:" + (altura*largura));
    }
    public static void perimetroRetangulo(){
        System.out.println("Perimetro do retangulo:" + ((2*altura)+(2*largura)));
    }
}
