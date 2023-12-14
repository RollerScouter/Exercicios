// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Trabalho Semestral: Processador MIPS em C.
// Autor: Pedro Henrique Costa Dias, Engenharia da Computação
// Ultima edição: 26/11/2023

int concatenador(int tempOffSet, int tempPC, int PC){
    printf("\n\nPor fim, os valores de 28-bits do jump target sao concatenados com os 4 primeiros bits do valor atualizado de PC provido pelo adder (%d), formando assim um endereco de 32-bits que pode ser utilizado como o novo valor de PC para obter a proxima instrucao.", tempPC);
    PC = tempOffSet;
    printf("Novo valor de PC: %d", PC );
    return PC;
}

int Link(int tempPC, int $ra, int RegWrite){
	printf("\n\n O valor do adder e salvo antes da concatenação no registrador 31 para recuperação posterior, com o recebimento do sinal de RegWrite(%d) possibilitando a escrita deste valor no registrador.", RegWrite);
	$ra = tempPC;
	return $ra;
}

int Branch_(int Branch){
	printf("\n\nA CU carrega um sinal de Branch para ser comparado com o resultado de uma operacao booleana para assim determinar se havera um branch no endereco de instrucao.");
	Branch = 1;
	return Branch;
}    
    


void control_unit_j(char OPCODE[]){
    printf("\n\nJa o segmento contendo o OPCODE vai para a CU, onde se identifica a instrucao a ser realizada.");
    if(strcmp(OPCODE, "000010") == 0){
        printf("\n\nOperacao realizada: J. Tipo de operacao: J-tipo. ");
    }
    if(strcmp(OPCODE, "000000") == 0){
        printf("\n\nOperacao realizada: JR.Tipo de operacao: R-tipo. ");
    }
    if(strcmp(OPCODE, "000011") == 0){
    	printf("\n\nOperacao realizada: JAL. Tipo de operacao: J-tipo ");
	}
    return 0;
}

int shifter(int tempOffSet){
    printf("\n\n A instrucao entao e divida em segmentos, com o segmento de 26 bits contendo o target sendo direcionado para o Shifter onde se realiza uma operacao de Shift Left 2 no mesmo, o extendendo para 28 bits.");
    printf("\nJump Target: %d", tempOffSet);
    tempOffSet = tempOffSet << 2;
    printf("\nOriginal Jump Target: %d", tempOffSet);
    return tempOffSet;
}

int PC_Write(int tempPC, int PC){
    printf("\n\nO valor de PC e atualizado apos a operacao aritmetica realizado pelo Adder, apontando para a proxima instrucao.");
    PC = tempPC;
    printf("\n\n Novo valor de PC: %d", PC);
    return PC;
}


void SignalExtend(unsigned tempIMM, unsigned i){
    printf("\n\nPor fim, o valor imediato chega no sign extender, onde ele e extendido de 16-bits para um tamanho de 32-bits. assim podendo se relacionado com os valores nos registradores que tambem sao deste tamanho. ");
    printf("\n\nIMM extendido: ");
    for (i = 1 << 31; i > 0; i = i/2){
        (tempIMM & i) ? printf("1") : printf("0");
    }
    
    return 0;
}

void SignalExtendedOffSet(unsigned tempOffSet, unsigned i){
    printf("\n\nPor fim, o valor chega no sign extender, onde ele e extendido de 16-bits para um tamanho de 32-bits. assim podendo se relacionado com os valores nos registradores que tambem sao deste tamanho. ");
    printf("\n\nOffSet extendido:");
    for (i = 1 << 31; i > 0; i = i/2){
        (tempOffSet & i) ? printf("1") : printf("0");
    }
    
    return 0;
}

int Ler_IMM(char r3[], int tempIMM){
    sscanf(r3, "%d", &tempIMM);
    return tempIMM;
}

int Ler_OffSetJ(char r1[], int tempOffSet){
    sscanf(r1, "%d", &tempOffSet);
    return tempOffSet;
}
int Ler_OffSetB(char r3[], int tempOffSet){
    sscanf(r3, "%d", &tempOffSet);
    return tempOffSet;
}

int rf_write_r(char r1[], int tempRD){
    printf("\n\nPor fim, apos a atualizacao do valor de PC, o RF escreve o novo valor no registro destinatario apos receber um sinal de write 1 da CU. ");
    printf("%s = %d", r1, tempRD);
    return tempRD;
}

int rf_write_i(char r1[], int tempRT){
    printf("\n\nPor fim, apos a atualizacao do valor de PC, o RF escreve o novo valor no registro destinatario apos receber um sinal de write 1 da CU. ");
    printf("%s = %d", r1, tempRT);
    return tempRT;
}

int alu_r(int tempRS, int tempRT, int tempRD, int ALUctrl){
    printf("\n\nNa ALU, se realiza a operacao aritmetica baseada nos registradores de leitura obtidos pela RF e o sinal da ALUCtrl: ");
    if(ALUctrl == 1){
        tempRD = tempRS + tempRT;
        printf("\nOperacao de ADD, %d + %d = %d", tempRS, tempRT, tempRD);
    }
    if(ALUctrl == 2){
        tempRD = tempRS - tempRT;
        printf("\nOperacao de SUB, %d - %d = %d", tempRS, tempRT, tempRD);
    }
    if(ALUctrl == 3){
        tempRD = tempRS & tempRT;
        printf("\nOperacao de AND, %d & %d = %d", tempRS, tempRT, tempRD);
    }
    if(ALUctrl == 4){
        tempRD = tempRS | tempRT;
        printf("\nOperacao de OR, %d | %d = %d", tempRS, tempRT, tempRD);
    }
    
    if(ALUctrl == 5){
        tempRD = tempRS ^ tempRT;
        printf("\nOperacao de XOR, %d ^ %d = %d", tempRS, tempRT, tempRD);
    }
    if(ALUctrl == 6){
        if(tempRS < tempRT){
            tempRD = 1;
            printf("\nOperacao de SLT, %d < %d , logo RD = %d", tempRS, tempRT, tempRD);
        }
        else{
            tempRD = 0;
            printf("\nOperacao de SLT, %d nao e < %d , logo RD = %d", tempRS, tempRT, tempRD);
        }
    }
    if(ALUctrl == 7){
        tempRD = ~(tempRS | tempRT);
        printf("\nOperacao de NOR, ~(%d | %d) = %d", tempRS, tempRT, tempRD);
    }
    if(ALUctrl == 8){
        tempRD = tempRS * tempRT;
        printf("\nOperacao de MUL, %d * %d = %d", tempRS, tempRT, tempRD);
    }
    return tempRD;
}

int alu_i(int tempRS, int tempIMM, int tempRT, int ALUctrl){
    printf("\n\nNa ALU, se realiza a operacao aritmetica baseada nos registradores de leitura obtidos pela RF e o sinal da ALUCtrl: ");
    if(ALUctrl == 1){
        tempRT = tempRS + tempIMM;
        printf("\nOperacao de ADDI, %d + %d = %d", tempRS, tempIMM, tempRT);
    }
    if(ALUctrl == 2){
        tempRT = tempRS & tempIMM;
        printf("\nOperacao de ANDI, %d & %d = %d",tempRS, tempIMM,tempRT);
    }
    if(ALUctrl == 3){
        tempRT = tempRS | tempIMM;
        printf("\nOperacao de ORI, %d | %d = %d",tempRS, tempIMM,tempRT);
    }
    if(ALUctrl == 4){
        tempRT = tempRS ^ tempIMM;
        printf("\nOperacao de XORI, %d ^ %d = %d",tempRS, tempIMM,tempRT);
    }
    if(ALUctrl == 5){
    	if(tempRS < tempIMM){
        tempRT = 1;
        printf("\nOperacao de SLTI, %d < %d, logo RT = %d.",tempRS, tempIMM,tempRT);
    }
    else{
    	tempRT = 0;
    	printf("\nOperacao de SLTI, %d > %d, logo RT = %d", tempRS, tempIMM, tempRT);
	}
}
return tempRT;
}

int alu_br(int tempRS, int tempRT, int ALUCtrl){
	if(ALUCtrl == 6){
		printf("\n\nOperacao de BNE: Se checa se ambos os valores nos registradores não são iguais:");
		if(tempRS != tempRT){
			tempRT = 1;
		}
		else{
			tempRT = 0;
		}
	}
return tempRT;
}



int ALU(int tempRS, int tempRT, int tempRD, int tempIMM, int ALUscr, int ALUctrl){
    printf("\n\nA partir dos sinais de ALUscr para determinar se um dos operandos e um registrador ou imediato e de ALUctrl para determinar a operacao a ser realizada, a ALU realiza a operacao.");
    if(ALUscr == 0){
        tempRD = alu_r(tempRS, tempRT, tempRD, ALUctrl);
        return tempRD;
    }
    else{
        tempRT = alu_i(tempRS, tempIMM, tempRT, ALUctrl);
        return tempRT;
    }
    return tempRD;
}
int MUX_JR(int tempPC, int PC, int JRSignal, int tempRD){
    printf("\n\nDe acordo com um valor JRSignal mandado pela CU, o MUX escolhe o input para ser o novo valor de PC entre o valor recebido do Adder ou o valor contido num registrador se a operacao for de JR: ");
	if(JRSignal == 0){
        PC = PC_Write(tempPC, PC);
    }
    else{
        PC = tempRD;
        printf("Novo valor de PC: %d", tempPC);
    }
  return PC;  
}

int MUX_BR(int tempPC, int PC, int PCscr, int tempOffSet){
    printf("\n\nDe acordo com um valor PCscr mandado pela CU, o MUX escolhe o input para ser o novo valor de PC entre o valor recebido do Adder ou o valor do OffSet. ");
	if(PCscr == 0){
        PC = PC_Write(tempPC, PC);
    }
    else{
        PC = tempOffSet;
        printf("Novo valor de PC: %d", tempOffSet);
    }
  return PC;  
}

int PCscr_(int tempRT, int Branch, int PCscr){
	if (tempRT == Branch){
		PCscr = 1;
	}
	else{
		PCscr = 0;
	}
	return PCscr;
}
int alu_ctrl_r(char FUNCT[], int ALUctrl, int ALUop){
    printf("\nO ALU Control recebe o FUNCT e o ALUop, e usa do segundo para identificar como prosseguir.");
    printf("\nALUop = %d. (Usar o funct.)", ALUop);
    
    printf("\n\nPor fim, o segmento de funct da instrucao que foi enderecado para o ALU Control e usado para determinar a operacao a ser realizada pelo ALU com um sinal de ALUctrl.");
    if(strcmp(FUNCT, "100000") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: ADD", FUNCT);
        ALUctrl = 1;
    }
    else if(strcmp(FUNCT, "100010") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: SUB", FUNCT);
        ALUctrl = 2;
    }
    else if(strcmp(FUNCT, "100100") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: AND", FUNCT);
        ALUctrl = 3;
    }
    else if(strcmp(FUNCT, "100101") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: OR", FUNCT);
        ALUctrl = 4;
    }
    else if(strcmp(FUNCT, "100110") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: XOR", FUNCT);
        ALUctrl = 5;
    }
    else if(strcmp(FUNCT, "101010") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: SLT", FUNCT);
        ALUctrl = 6;
    }
    else if(strcmp(FUNCT, "100111") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: NOR", FUNCT);
        ALUctrl = 7;
    }
    else if(strcmp(FUNCT, "011000") == 0){
        printf("\n Funct = %s. Operacao a ser realizada: MUL", FUNCT);
        ALUctrl = 8;
    }
return ALUctrl;    
}

int alu_ctrl_i(int ALUctrl, int ALUop){
    printf("\nO ALU Control recebe o ALUop, e usa deste para identificar com qual operacao prosseguir, mandando um sinal de ALUctrl.");
    
    if(ALUop == 0){
        printf("\n ALUop = %d. Operacao a ser realizada: ADDI", ALUop);
        ALUctrl = 1;
    }
    if(ALUop == 1){
        printf("\n ALUop = %d. Operacao a ser realizada: ANDI", ALUop);
        ALUctrl = 2;
    }
    if(ALUop == 2){
        printf("\n ALUop = %d. Operacao a ser realizada: ORI", ALUop);
        ALUctrl = 3;
    }
    if(ALUop == 3){
        printf("\n ALUop = %d. Operacao a ser realizada: XORI", ALUop);
        ALUctrl = 4;
    }
    if(ALUop == 4){
        printf("\n ALUop = %d. Operacao a ser realizada: SLTI", ALUop);
        ALUctrl = 5;
    }
    if(ALUop == 5){
        printf("\n ALUop = %d. Operacao a ser realizada: BNE", ALUop);
        ALUctrl = 6;
    }
    if(ALUop == 6){
        printf("\n ALUop = %d. Operacao a ser realizada: BGTZ", ALUop);
        ALUctrl = 7;
    }
return ALUctrl;    
}


void rf_read_r(char r2[], char r3[], int tempRS, int tempRT){
    printf("\n\nA partir dos enderecos de leitura rs e rt, se identifica e guarda os valores nestes para a realizacao da operacao: ");
    printf("\n %s: %d", r2, tempRS);
    printf("\n %s: %d", r3, tempRT);
    return 0;
}

void rf_read_i(char r2[], int tempRS){
    printf("\n\nA partir do endereco de leitura rs, se identifica e guarda o valor neste para a realizacao da operacao: ");
    printf("\n %s: %d", r2, tempRS);
    return 0;
}

int control_unit_JRSignal(char operacao[], int JRSignal){
    printf("\n\n A partir do opcode da instrucao, se identifica o tipo de instrucao e gera um sinal de JRSignal para decidir o valor de PC posteriormente. ");
    if(strcmp(operacao, "JR") == 0){
       JRSignal = 1; 
       printf("\n JRSignal: %d .", JRSignal);
    }
    else{
        JRSignal = 0;
        printf("\n JRSignal: %d .", JRSignal);
    }
    return JRSignal;
}

int control_unit_ALUopR(char OPCODE[], int ALUop){
    printf("\n\nA instrucao e entao separada em segmentos que sao direcionados as outras partes da CPU. A partir do opcode da instrucao que e direcionado para a CU, se identifica o tipo de instrucao e gera-se um sinal de ALUop. ");
    
    printf("\n OPCODE: %s . Tipo de instrucao: R-tipo.", OPCODE);
        ALUop = 0;
        
    return ALUop;
}
int control_unit_ALUopI(char OPCODE[], int ALUop){
    printf("\n\nA instrucao e entao separada em segmentos que sao direcionados as outras partes da CPU. A partir do opcode da instrucao que e direcionado para a CU, se identifica o tipo de instrucao e gera-se um sinal de ALUop. ");
    
    if(strcmp(OPCODE, "001000") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 0;
    printf("\n ALUop = %d", ALUop);
}
    if(strcmp(OPCODE, "001100") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 1;
    printf("\n ALUop = %d", ALUop);
}
    if(strcmp(OPCODE, "001101") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 2;
    printf("\n ALUop = %d", ALUop);
}
    if(strcmp(OPCODE, "001110") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 3;
    printf("\n ALUop = %d", ALUop);
}
	if(strcmp(OPCODE, "001010") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 4;
    printf("\n ALUop = %d", ALUop);
}    
    if(strcmp(OPCODE, "000101") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 5;
    printf("\n ALUop = %d", ALUop);
}
    if(strcmp(OPCODE, "000111") == 0){
	printf("\n OPCODE: %s . Tipo de instrucao: I-tipo.", OPCODE);
    ALUop = 6;
    printf("\n ALUop = %d", ALUop);
}
    return ALUop;
}


int MUX_ALUscrR(int ALUscr){
    printf("\n\n Este proximo multiplexador decide se o ALU ira receber um RT ou um imediato como operando ao receber um sinal de controle ALUscr da CU:");
    ALUscr = 0;
    printf("\nALU ira receber RT como operando. ");
    return ALUscr;
    
}

int MUX_ALUscrI(int ALUscr){
    printf("\n\n Este proximo multiplexador decide se o ALU ira receber um RT ou um imediato como operando ao receber um sinal de controle ALUscr da CU:");
    ALUscr = 1;
    printf("\nALU ira receber o imediato como operando. ");
    return ALUscr;
    
}
int RegWrite1(int RegWrite){
    printf("\n\n O RF recebe um sinal da CU para determinar se havera ou nao escrita em registrador nesta instrucao:");
    RegWrite = 1;
    printf("\n O sinal de RegWrite e %d, logo havera write em um registrador.", RegWrite);
    return RegWrite;
}
    
int RegWrite0(int RegWrite){
	printf("\n\n O RF recebe um sinal da CU para determinar se havera ou nao escrita em registrador nesta instrucao:");
    RegWrite = 0;
    printf("\n O sinal de RegWrite e %d, logo nao havera write em um registrador.", RegWrite);
    return RegWrite;
	
}    

int MUX_RegDst_1(int RegDst){
    printf("\n\n Um multiplexador define se o registrador de destino sera o rd ou o rt, assim definindo se a operacao e do tipo R ou do tipo I.");
    RegDst = 1;
    printf("\nValor de RegDst: %d. Logo, o registrador de destino e o rd.", RegDst);
    return RegDst;
    
}
int MUX_RegDst_0(int RegDst){
    printf("\n\n Um multiplexador define se o registrador de destino sera o rd ou o rt, assim definindo se a operacao e do tipo R ou do tipo I.");
    RegDst = 0;
    printf("\nValor de RegDst: %d. Logo, o registrador de destino e o rt.", RegDst);
    return RegDst;
    
}

void decod_instrucao(char operacao[], char r1[], char r2[], char r3[], int PC){
    printf("\n\nO IM recebe o valor do PC (%d) e deste decodifica a instrucao a ser realizada: %s %s %s %s", PC, operacao, r1, r2, r3);
   return 0; 
}

void decod_instrucao_j(char operacao[], char r1[], int PC){
    printf("\n\nO IM recebe o valor do PC (%d) e deste decodifica a instrucao a ser realizada: %s %s %s %s", PC, operacao, r1);
   return 0; 
}


int adder(int PC, int tempPC){
    printf("\n\nAo mesmo tempo, o Adder realiza uma operacao aritmetica onde se incrementa o valor de PC com um valor fixo necessario para a passagem de um ciclo: Se acrescenta 4 a %d.", PC);
    tempPC = PC + 4;
    return tempPC;
}
int Ler_rd(char r1[], int $S0, int $S1, int $S2, int $S3, int $S4, int $S5, int $S6, int $S7, int $ra, int tempRD){
    if (strcmp(r1, "$S0") == 0){
        tempRD = $S0;
    }
    if (strcmp(r1, "$S1") == 0){
        tempRD = $S1;
    }
    if (strcmp(r1, "$S2") == 0){
        tempRD = $S2;
    }
    if (strcmp(r1, "$S3") == 0){
        tempRD = $S3;
    }
    if (strcmp(r1, "$S4") == 0){
        tempRD = $S4;
    }
    if (strcmp(r1, "$S5") == 0){
        tempRD = $S5;
    }
    if (strcmp(r1, "$S6") == 0){
        tempRD = $S6;
    }
    if (strcmp(r1, "$S7") == 0){
        tempRD = $S7;
    }
    if (strcmp(r1, "$ra") == 0){
        tempRD = $ra;
    }
return tempRD;
}
int Ler_rt1(char r1[], int $S0, int $S1, int $S2, int $S3, int $S4, int $S5, int $S6, int $S7, int tempRT){
    if (strcmp(r1, "$S0") == 0){
        tempRT = $S0;
    }
    if (strcmp(r1, "$S1") == 0){
        tempRT = $S1;
    }
    if (strcmp(r1, "$S2") == 0){
        tempRT = $S2;
    }
    if (strcmp(r1, "$S3") == 0){
        tempRT = $S3;
    }
    if (strcmp(r1, "$S4") == 0){
        tempRT = $S4;
    }
    if (strcmp(r1, "$S5") == 0){
        tempRT = $S5;
    }
    if (strcmp(r1, "$S6") == 0){
        tempRT = $S6;
    }
    if (strcmp(r1, "$S7") == 0){
        tempRT = $S7;
    }
return tempRT;
}
int Ler_rs(char r2[], int $S0, int $S1, int $S2, int $S3, int $S4, int $S5, int $S6, int $S7, int tempRS){
    if (strcmp(r2, "$S0") == 0){
        tempRS = $S0;
    }
    if (strcmp(r2, "$S1") == 0){
        tempRS = $S1;
    }
    if (strcmp(r2, "$S2") == 0){
        tempRS = $S2;
    }
    if (strcmp(r2, "$S3") == 0){
        tempRS = $S3;
    }
    if (strcmp(r2, "$S4") == 0){
        tempRS = $S4;
    }
    if (strcmp(r2, "$S5") == 0){
        tempRS = $S5;
    }
    if (strcmp(r2, "$S6") == 0){
        tempRS = $S6;
    }
    if (strcmp(r2, "$S7") == 0){
        tempRS = $S7;
    }
return tempRS;
}

int Ler_rt2(char r3[], int $S0, int $S1, int $S2, int $S3, int $S4, int $S5, int $S6, int $S7, int tempRT){
    if (strcmp(r3, "$S0") == 0){
        tempRT = $S0;
    }
    if (strcmp(r3, "$S1") == 0){
        tempRT = $S1;
    }
    if (strcmp(r3, "$S2") == 0){
        tempRT = $S2;
    }
    if (strcmp(r3, "$S3") == 0){
        tempRT = $S3;
    }
    if (strcmp(r3, "$S4") == 0){
        tempRT = $S4;
    }
    if (strcmp(r3, "$S5") == 0){
        tempRT = $S5;
    }
    if (strcmp(r3, "$S6") == 0){
        tempRT = $S6;
    }
    if (strcmp(r3, "$S7") == 0){
        tempRT = $S7;
    }
return tempRT;
}

int main() {
    int $S0 = 1, $S1 = 12, $S2 = 25, $S3 = 0, $S4 = 0, $S5 = 0, $S6 = 0, $S7 = 0, $ra = 0;
    char operacao[6];
    char r1[5] = "\0";
    char r2[5] = "\0";
    char r3[5] = "\0";
    int PC = 0, tempPC = 0, JRSignal = 0, ALUop = 0, i = 0, ALUscr = 0, RegDst = 0, RegWrite = 0, PCscr = 0, Branch = 0;
    int tempRD, tempRS, tempRT, ALUctrl, tempIMM, tempOffSet;
    do{
    printf("\n$S0 = %d, $S1 = %d, $S2 = %d, $S3 = %d, $S4 = %d, $S5 = %d, $S6 = %d, $S7 = %d , $ra = %d, PC = %d", $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, PC);
    
    printf("\nInforme a operacao em MIPS a ser lida: (Inpute a operacao, primeiro, segundo e terceiro registradores. Caso algum nao seja necessario, inpute ' no lugar. Se acidentalmente apertar enter de forma precoce, apenas inpute os valores restantes.) \n  ");
    scanf("%s %s %s %s", operacao, r1, r2, r3);
	
    
    if (strcmp(operacao, "ADD") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100000";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);  
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
        
    }
    
    if (strcmp(operacao, "SUB") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100010";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    
    if (strcmp(operacao, "AND") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100100";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    
    if (strcmp(operacao, "OR") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100101";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    
    
    if (strcmp(operacao, "XOR") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100110";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    if (strcmp(operacao, "NOR") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "100111";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    
    if (strcmp(operacao, "SLT") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "101010";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    if (strcmp(operacao, "MUL") == 0){
        char OPCODE[] = "000000";
        char FUNCT[] = "011000";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempRT = Ler_rt2(r3, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempPC = adder(PC, tempPC);   
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        RegWrite = RegWrite1(RegWrite);
        rf_read_r(r2, r3, tempRS, tempRT);
        ALUop = control_unit_ALUopR(OPCODE, ALUop);
        ALUctrl = alu_ctrl_r(FUNCT, ALUctrl, ALUop);
        ALUscr = MUX_ALUscrR(ALUscr);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        tempRD = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        
        
    }
    else if (strcmp(operacao, "JR") == 0){
   
        char OPCODE[] = "000000";
        char FUNCT[] = "001000";
        decod_instrucao_j(operacao, r1, PC);
        RegDst = MUX_RegDst_1(RegDst);
        tempRD = Ler_rd(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, $ra, tempRD);
        tempPC = adder(PC, tempPC);
        JRSignal = control_unit_JRSignal(operacao, JRSignal);
        control_unit_j(OPCODE);
        PC = MUX_JR(tempPC, PC, JRSignal, tempRD);
        
    }
    else if (strcmp(operacao, "ADDI") == 0){
        char OPCODE[] = "001000";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempIMM = Ler_IMM(r3, tempIMM);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite1(RegWrite);
        rf_read_i(r2, tempRS);
        SignalExtend(tempIMM, i);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        ALUscr = MUX_ALUscrI(ALUscr);
        tempRT = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        PC = PC_Write(tempPC, PC);
    }
    else if (strcmp(operacao, "ANDI") == 0){
        char OPCODE[] = "001100";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempIMM = Ler_IMM(r3, tempIMM);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite1(RegWrite);
        rf_read_i(r2, tempRS);
        SignalExtend(tempIMM, i);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        ALUscr = MUX_ALUscrI(ALUscr);
        tempRT = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        PC = PC_Write(tempPC, PC);
    }
    else if (strcmp(operacao, "ORI") == 0){
        char OPCODE[] = "001101";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempIMM = Ler_IMM(r3, tempIMM);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite1(RegWrite);
        rf_read_i(r2, tempRS);
        SignalExtend(tempIMM, i);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        ALUscr = MUX_ALUscrI(ALUscr);
        tempRT = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        PC = PC_Write(tempPC, PC);
    }
    else if (strcmp(operacao, "XORI") == 0){
        char OPCODE[] = "001110";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempIMM = Ler_IMM(r3, tempIMM);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite1(RegWrite);
        rf_read_i(r2, tempRS);
        SignalExtend(tempIMM, i);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        ALUscr = MUX_ALUscrI(ALUscr);
        tempRT = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        PC = PC_Write(tempPC, PC);
    }
    else if (strcmp(operacao, "SLTI") == 0){
        char OPCODE[] = "001010";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempIMM = Ler_IMM(r3, tempIMM);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite1(RegWrite);
        rf_read_i(r2, tempRS);
        SignalExtend(tempIMM, i);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        ALUscr = MUX_ALUscrI(ALUscr);
        tempRT = ALU(tempRS, tempRT, tempRD, tempIMM, ALUscr, ALUctrl);
        PC = PC_Write(tempPC, PC);
    }
    else if (strcmp(operacao, "BNE") == 0){
        char OPCODE[] = "000101";
        decod_instrucao(operacao, r1, r2, r3, PC);
        RegDst = MUX_RegDst_0(RegDst);
        tempRT = Ler_rt1(r1, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRT);
        tempRS = Ler_rs(r2, $S0, $S1, $S2, $S3, $S4, $S5, $S6, $S7, tempRS);
        tempOffSet = Ler_OffSetB(r3, tempOffSet);
        tempPC = adder(PC, tempPC);
        ALUop = control_unit_ALUopI(OPCODE, ALUop);
        RegWrite = RegWrite0(RegWrite);
        rf_read_i(r2, tempRS);
        Branch = Branch_(Branch);
        SignalExtendedOffSet(tempOffSet, i);
        tempOffSet = shifter(tempOffSet);
        ALUctrl = alu_ctrl_i(ALUctrl, ALUop);
        tempRT = alu_br(tempRS, tempRT, ALUctrl);
        PCscr = PCscr_(tempRT, Branch, PCscr);
        PC = MUX_BR(tempPC, PC, PCscr, tempOffSet);
    }
    
    
    
    
    else if (strcmp(operacao, "J") == 0){
   
         char OPCODE[] = "000010";
        decod_instrucao_j(operacao, r1, PC);
        tempOffSet = Ler_OffSetJ(r1, tempOffSet);
        tempPC = adder(PC, tempPC);
        tempOffSet = shifter(tempOffSet);
        control_unit_j(OPCODE);
        PC = concatenador(tempOffSet, tempPC, PC);
        
    }
    else if (strcmp(operacao, "JAL") == 0){
   
         char OPCODE[] = "000011";
        decod_instrucao_j(operacao, r1, PC);
        tempOffSet = Ler_OffSetJ(r1, tempOffSet);
        tempPC = adder(PC, tempPC);
        tempOffSet = shifter(tempOffSet);
        control_unit_j(OPCODE);
        RegWrite = RegWrite1(RegWrite);
        $ra = Link(tempPC, $ra,RegWrite);
        PC = concatenador(tempOffSet, tempPC, PC);
        
    }
    if(RegDst == 1){
    if(strcmp(r1, "$S0") == 0){
        $S0 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S1") == 0){
        $S1 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S2") == 0){
        $S2 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S3") == 0){
        $S3 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S4") == 0){
        $S4 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S5") == 0){
        $S5 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S6") == 0){
        $S6 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    if(strcmp(r1, "$S7") == 0){
        $S7 = rf_write_r(r1, tempRD);
        RegDst = -1;
    }
    }
    if(RegDst == 0){
    if(strcmp(r1, "$S0") == 0){
        $S0 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S1") == 0){
        $S1 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S2") == 0){
        $S2 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S3") == 0){
        $S3 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S4") == 0){
        $S4 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S5") == 0){
        $S5 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S6") == 0){
        $S6 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    if(strcmp(r1, "$S7") == 0){
        $S7 = rf_write_i(r1, tempRT);
        RegDst = -1;
    }
    }
    ALUop = 0;
    JRSignal = 0;
    ALUscr = 0;
    
    
}while($S0 != 999999);
    return 0;
}




