/*
    Aluno: Marcelo Barbosa Tadini Patta
    Matrícula: 2019000439
*/

#include "config.h"
#include "pic18f4520.h"
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "stdio.h"


unsigned int atrasoMin = 20;
unsigned int atrasoMed = 500;
unsigned int atrasoMax = 1000;

void main() {


    char codigo [4];
    char palavra [16];

    char * input[37]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----.","/"};

    char output[37]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
                   'P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3',
                    '4','5','6','7','8','9','\0'};

    int aux = 0;
    int i = 0;
    int TAM = 0;
    int lenght = 0;

    ADCON1 = 0x06;
    TRISB = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;

    lcd_init();
    TRISA = 0x20;
    TRISB = 0x3F;


    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Digite o Codigo");
    BitClr(PORTB, 1);
    BitClr(PORTB, 3);

    while (BitTst(PORTB, 0)) {



        if (!BitTst(PORTB, 1) && aux == 0) {
            lcd_cmd(L_L2);
            lcd_str("-");

            codigo[0] = '-';

            atraso_ms(500);
            aux++;
            lenght++;

        }
        if (!BitTst(PORTB, 3) && aux == 0) {
            lcd_cmd(L_L2);
            lcd_str(".");
            codigo[0] = '.';

            atraso_ms(500);
            aux++;
            lenght++;
        }
        if (!BitTst(PORTB, 1) && aux == 1) {

            lcd_cmd(L_L2 + 1);
            lcd_str("-");

            codigo[1] = '-';
            atraso_ms(500);
            aux++;
            lenght++;


        }
        if (!BitTst(PORTB, 3) && aux == 1) {
            lcd_cmd(L_L2 + 1);
            lcd_str(".");
            codigo[1] = '.';
            atraso_ms(500);
            aux++;
            lenght++;

        }
        if (!BitTst(PORTB, 1) && aux == 2) {

            lcd_cmd(L_L2 + 2);
            lcd_str("-");
            codigo[2] = '-';
            atraso_ms(500);
            aux++;
            lenght++;


        }
        if (!BitTst(PORTB, 3) && aux == 2) {
            lcd_cmd(L_L2 + 2);
            lcd_str(".");
            codigo[2] = '.';
            atraso_ms(500);
            aux++;
            lenght++;

        }
        if (!BitTst(PORTB, 1) && aux == 3) {

            lcd_cmd(L_L2 + 3);
            lcd_str("-");
            codigo[3] = '-';
            atraso_ms(500);
            aux++;
            lenght++;


        }
        if (!BitTst(PORTB, 3) && aux == 3) {
            lcd_cmd(L_L2 + 3);
            lcd_str(".");
            codigo[3] = '.';
            atraso_ms(500);
            aux++;
            lenght++;

        }

        if (!BitTst(PORTB, 5)) {
            if (lenght == 1) {
                codigo[1] = 'V';
                codigo[2] = 'V';
                codigo[3] = 'V';


            }
            if (lenght == 2) {

                codigo[2] = 'V';
                codigo[3] = 'V';


            }
            if (lenght == 3) {


                codigo[3] = 'V';


            }
            lcd_cmd(L_L1);
            lcd_cmd(L_CLR);
            palavra[i] = traduzMorse(codigo);
            i++;
            TAM++;
            atraso_ms(2000);
            aux = 0;

            lcd_cmd(L_CLR);
            lcd_cmd(L_L1);
            lcd_str("Digite o Codigo");

        }
        if (!BitTst(PORTB, 4)) {
            aux = 10;
            i = 0;
            lcd_cmd(L_L1);
            lcd_cmd(L_CLR);
            lcd_str("TRADUCAO");
            atraso_ms(2000);
            lcd_cmd(L_L2);
            lcd_str(palavra);
        }


    }
}












