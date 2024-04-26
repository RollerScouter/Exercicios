package br.edu.up.exer;

import br.edu.up.exer.modelos.*;

public class PrincipalCat {
    public static void main(String[] args) {
        Cat lion = new Lion(true);
        Cat tiger = new Tiger(true);
        Cat cheetah = new Cheetah(true);

        DocLittle.health(lion);
        DocLittle.health(tiger);
        DocLittle.health(cheetah);
    }
}
