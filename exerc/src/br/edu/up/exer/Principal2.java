package br.edu.up.exer;

import br.edu.up.exer.modelos.Ingresso;
import br.edu.up.exer.modelos.IngressoVIP;

public class Principal2 {
    public static void main(String[] args) {
        Ingresso ingresso = new Ingresso(200.0);
        Ingresso ingressovip = new IngressoVIP(200.0, 80.0);
        IngressoVIP vip = new IngressoVIP(200.0, 100.0);

        System.out.println(ingresso);
        System.out.println(ingressovip);
        System.out.println(vip);
    }
}
