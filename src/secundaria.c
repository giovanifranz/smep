//Utensilios
#include <16f877a.h>
#fuses hs, nolvp, nowdt, nobrownout
#use delay(clock = 20000000)
#include <lcd.c>
//Seta Variaveis
int A=0;
int B=0;

// Procedimento Principal
void Main()
{
   set_tris_b(0b00001111); // Determina que b0,b1,b2,b3 sao entradas e b4,b5,b6 e b7 saidas
   set_tris_c(0b00000000); // Determina que c0,c1,c2,c3,c4,c5,c6,c7 sao saidas
   while(true) 
   {
      // Primeito Botao!
      //Liga todos os LEDS
      if(input(pin_b0))
      {
      output_c(0b11111111);
      }
      //FIM do primeiro botao
      
      //Segundo Botao!
      //pisca
      if(input(pin_b1))
      {
      A=1;         
         while(A) // executa While enquanto A for verdadeiro.
         {
            output_c(0b11111111);
            delay_ms(300);
            output_c(0b00000000);
            delay_ms(300);
               if(input(pin_b0)) // Leitura do Primeiro botao
               {
               output_c(0b11111111);
               A=0;// A = 0 para sair do While
               }
               if(input(pin_b2)) //leitura do terceiro botao
               {
               output_c(0b10000000);
               delay_ms(200);
               output_c(0b01000000);
               delay_ms(200);
               output_c(0b00100000);
               delay_ms(200);
               output_c(0b00010000);
               delay_ms(200);
               output_c(0b00001000);
               delay_ms(200);
               output_c(0b00000100);
               delay_ms(200);
               output_c(0b00000010);
               delay_ms(200);
               output_c(0b00000001);
               delay_ms(200);
               A=0;// A = 0 para sair do While
               } // fim do terceiro botao
               if (input(pin_b3)) //leitura do quarto botao
               {
               output_c(0b00000000);
               A=0;// A = 0 para sair do While
               } // fim do quarto botao
           }
      }
      // Fim do segundo botao
      
      //Terceiro botao!
      //Trilha de LEDs
      if(input(pin_b2))
         {
         B=1; // B = 1 para iniciar o While
         while(B) // Executa while enquanto B for verdadeiro
            {
            output_c(0b10000000);
            delay_ms(200);
            output_c(0b01000000);
            delay_ms(200);
            output_c(0b00100000);
            delay_ms(200);
            output_c(0b00010000);
            delay_ms(200);
            output_c(0b00001000);
            delay_ms(200);
            output_c(0b00000100);
            delay_ms(200);
            output_c(0b00000010);
            delay_ms(200);
            output_c(0b00000001);
            delay_ms(200);
            if(input(pin_b0))// leitura botao 1
               {
               output_c(0b11111111);
               B=0;// B = 0 para sair do While
               }
            if(input(pin_b1))// leitura botao 2
               {
               output_c(0b11111111);
               delay_ms(300);
               output_c(0b00000000);
               delay_ms(300);
               B=0;// B = 0 para sair do While
               }
            if (input(pin_b3)) // leitura botao 3
               {
               output_c(0b00000000);
               B=0; // B = 0 para sair do While
               }
            }
         }                               
         // fim do botao 3
                    
         //Botao 4!
         //Desliga todos LEDS
                                
      if (input(pin_b3))
         {
         output_c(0b00000000);
         }
      //Fim do botao 4
   }                              
}
