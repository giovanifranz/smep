#include <16f877a.h>
#device adc = 8
#FUSES NOWDT, HS, NOPUT, PROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NODEBUG
#use delay(clock = 20000000)
#define LCD_TYPE 2
#include <lcd.c>

int16 distance, time, ldr_a, ldr_b, ldr_c, ldr_d; // define variaveis

// Defining os pinos

#define trig0 pin_B0 //saida sinal sensor 0 ultassonico
#define echo0 pin_B1 //entrada sinal sensor 0 ultrassonico
#define trig1 pin_B2
#define echo1 pin_B3
#define stop_a pin_B4 //entrada sinal ldr
#define stop_b pin_B5
#define stop_c pin_B6
#define stop_d pin_B7

void main()
{
   lcd_init(); // Inicia LCD

   ldr_a = 0;
   ldr_b = 0;
   ldr_c = 0;
   ldr_d = 0;

   printf(LCD_PUTC, "\f Sensoriamento de Empilhadeira \n");
   delay_ms(1000);

   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8); // iniciando o timer

   while (0) //Corredor 1
   {
      ldr_a = stop_a;
      ldr_c = stop_c;

      output_high(trig0);
      delay_us(10);
      output_low(trig0);

      while (!input(echo0))
      {
      }
      set_timer1(0);

      while (input(echo0))
      {
      }

      time = get_timer1();
      distance = (time * 10) / (58.0); //"calcula a distancia em centimetros"

      printf(LCD_PUTC, "\fTime :%Lu \nDistancia = %Lu", time, distance);
      delay_ms(500);

      if (ldr_a == 0) //sensor ldr bloco a
      {
         if (distance = 10) //quando a distancia entre o veiculo e o sensor for 10cm aciona
         {
            output_high(pin_c0);
            delay_ms(1000);
            printf(LCD_PUTC, "\f Voce esta proximo ao cruzamento, cuidado \n");
         }
      }
      if (ldr_c == 0) //sensor ldr bloco c
      {
         if (distance = 30) //quando a distancia entre o veiculo e o sensor for 30cm
         {
            output_high(pin_c1);
            delay_ms(1000);
            printf(LCD_PUTC, "\f Voce esta proximo ao cruzamento, cuidado \n");
         }
      }
   }
   while (1) //Corredor B
   {
      ldr_b = stop_b;
      ldr_d = stop_d;

      output_high(trig1);
      delay_us(10);
      output_low(trig1);

      while (!input(echo1))
      {
      }
      set_timer1(0);

      while (input(echo1))
      {
      }

      time = get_timer1();
      distance = (time * 10) / (58.0); //"calcula a distancia em centimetros"

      printf(LCD_PUTC, "\fTime :%Lu \nDistancia = %Lu", time, distance);
      delay_ms(500);

      if (ldr_b == 0) //sensor ldr bloco b
      {
         if (distance = 10) //quando a distancia entre o veiculo e o sensor for 10cm
         {
            output_high(pin_c2);
            delay_ms(1000);
            printf(LCD_PUTC, "\f Voce esta proximo ao cruzamento, cuidado \n");
         }
      }
      if (ldr_d == 0) //sensor ldr bloco d
      {
         if (distance = 30) //quando a distancia entre o veiculo e o sensor for 30cm
         {
            output_high(pin_c3);
            delay_ms(1000);
            printf(LCD_PUTC, "\f Voce esta proximo ao cruzamento, cuidado \n");
         }
      }
   }
}
