package br.edu.up.gestao;


import br.edu.up.gestao.modelo.*;

public class Principal {
    public static void main(String[] args){
    Carro teste = new Carro();
    teste.Mostrar_informacoes();
    Retangulo teste2 = new Retangulo();
    teste2.areaRetangulo();
    teste2.perimetroRetangulo();
    ContaBancaria teste3 = new ContaBancaria();
    teste3.sacarSaldo();
    teste3.depositarSaldo();
    Produto teste4 = new Produto();
    teste4.quantidadeAtualizar();
    teste4.precoTotal();
    Pessoa teste5 = new Pessoa();
    teste5.imprimirPessoa();
    teste5.idadeVerificacao();



}


}
