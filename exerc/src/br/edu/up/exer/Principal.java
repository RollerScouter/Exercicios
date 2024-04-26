package br.edu.up.exer;

import br.edu.up.exer.modelos.Equipamento;
import br.edu.up.exer.modelos.EquipamentoSonoro;

public class Principal {
    public static void main(String[] args) {
        Equipamento e = new Equipamento();
        e.ligar();
        System.out.println(e);

        EquipamentoSonoro equipamentoSonoro = new EquipamentoSonoro();
        System.out.println(equipamentoSonoro);
        equipamentoSonoro.ligar();
        equipamentoSonoro.estereo();
        System.out.println(equipamentoSonoro);
        equipamentoSonoro.mono();
        System.out.println(equipamentoSonoro);
        equipamentoSonoro.desligar();
        System.out.println(equipamentoSonoro);

    }
}
