#include <16F877A.h>
#use delay ( clock = 20 M )
#fuses XT,NOLVP,NOWDT,NOWRT,NOPUT,NOPROTECT,NODEBUG
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

int i=0;

int x[]={0,0,0,0};

int durum=0;

void main()
{
   set_tris_a(0b11100); // PORT.A I/O
   output_low(pin_a0);
   output_low(pin_a1);
   
   set_tris_b(0xff); // PORT.B I/0
   
   set_tris_c(0xff); // PORT.C I/O
   
   set_tris_d(0x00); // PORT.D I/O  
   output_d(0x00);
   
   set_tris_e(0x00);
   output_e(0x00);
                 
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   while(TRUE)
{

if(input(pin_b0))  // sorgulama
   {
   while(input(pin_b0));
   
   if(x[0]==1 && x[1]==2 && x[2]==3 && x[3]==4)   // þifre yanlýþ
   {   
   output_high(pin_a1);
   output_high(pin_d0);
   i=0;
   }
      
   else
   {                                             // þifre doðru
   output_high(pin_a0);
   output_low(pin_d0);
   i=1;
   }  
   }



   if(input(pin_b1))  // reset
   {
   while(input(pin_b1));
   i=0;
   durum=0;
   x[0]=0;
   x[1]=0;
   x[2]=0;
   x[3]=0;   
   
    output_low(pin_a0);
    output_low(pin_a1);
    
    output_low(pin_d0);
    output_low(pin_d4);
    output_low(pin_d5);
    output_low(pin_d6);
    output_low(pin_d7);    
   }


   if(i==1)  // þifre yanlýþ
   {
   output_high(pin_e0);
   delay_ms(250);
   output_low(pin_e0);
   delay_ms(250);      
   }
   
   if(i==0)   // þifre doðru
   {
   output_low(pin_e0);
   }
   
   

   if(durum==0){

         // TUÞ TAKIMI
   if(input(pin_a2)) // TUÞ "1" BASILDI
   {
   while(input(pin_a2));
   x[0]=1;
   durum=durum+1;
   }
   
      if(input(pin_a3))// TUÞ "2" BASILDI
   {
   while(input(pin_a3));
   x[0]=2;
   durum=durum+1;
   }
   
         if(input(pin_a4))// TUÞ "3" BASILDI
   {
   while(input(pin_a4));
   x[0]=3;
   durum=durum+1;
   }
   
         if(input(pin_a5))// TUÞ "4" BASILDI
   {
   while(input(pin_a5));
   x[0]=4;
   durum=durum+1;
   }
 
       if(input(pin_c0))// TUÞ "5" BASILDI
   {
   while(input(pin_c0));
   x[0]=5;
   durum=durum+1;
   }
   
          if(input(pin_c1))// TUÞ "6" BASILDI
   {
   while(input(pin_c1));
   x[0]=6;
   durum=durum+1;
   }
   
          if(input(pin_c2))// TUÞ "7" BASILDI
   {
   while(input(pin_c2));
   x[0]=7;
   durum=durum+1;
   }
 
        if(input(pin_c3))// TUÞ "8" BASILDI
   {
   while(input(pin_c3));
   x[0]=8;
   durum=durum+1;
   }
   
          if(input(pin_c4))// TUÞ "9" BASILDI
   {
   while(input(pin_c4));
   x[0]=9;
   durum=durum+1;
   }
   
          if(input(pin_c5))// TUÞ "#" BASILDI
   {
   while(input(pin_c5));
   x[0]=10;
   durum=durum+1;
   }
   
          if(input(pin_c6))// TUÞ "0" BASILDI
   {
   while(input(pin_c6));
   x[0]=0;
   durum=durum+1;
   }
   
          if(input(pin_c7))// TUÞ "*" BASILDI
   {
   while(input(pin_c7));
   x[0]=11;
   durum=durum+1;
   }
   }



   if(durum==1){

         // TUÞ TAKIMI
   if(input(pin_a2)) // TUÞ "1" BASILDI
   {
   while(input(pin_a2));
   x[1]=1;
   durum=durum+1;
   }
   
      if(input(pin_a3))// TUÞ "2" BASILDI
   {
   while(input(pin_a3));
   x[1]=2;
   durum=durum+1;
   }
   
         if(input(pin_a4))// TUÞ "3" BASILDI
   {
   while(input(pin_a4));
   x[1]=3;
   durum=durum+1;
   }
   
         if(input(pin_a5))// TUÞ "4" BASILDI
   {
   while(input(pin_a5));
   x[1]=4;
   durum=durum+1;
   }
 
       if(input(pin_c0))// TUÞ "5" BASILDI
   {
   while(input(pin_c0));
   x[1]=5;
   durum=durum+1;
   }
   
          if(input(pin_c1))// TUÞ "6" BASILDI
   {
   while(input(pin_c1));
   x[1]=6;
   durum=durum+1;
   }
   
          if(input(pin_c2))// TUÞ "7" BASILDI
   {
   while(input(pin_c2));
   x[1]=7;
   durum=durum+1;
   }
 
        if(input(pin_c3))// TUÞ "8" BASILDI
   {
   while(input(pin_c3));
   x[1]=8;
   durum=durum+1;
   }
   
          if(input(pin_c4))// TUÞ "9" BASILDI
   {
   while(input(pin_c4));
   x[1]=9;
   durum=durum+1;
   }
   
          if(input(pin_c5))// TUÞ "#" BASILDI
   {
   while(input(pin_c5));
   x[1]=10;
   durum=durum+1;
   }
   
          if(input(pin_c6))// TUÞ "0" BASILDI
   {
   while(input(pin_c6));
   x[1]=0;
   durum=durum+1;
   }
   
          if(input(pin_c7))// TUÞ "*" BASILDI
   {
   while(input(pin_c7));
   x[1]=11;
   durum=durum+1;
   }
   }
   
   
      if(durum==2){

         // TUÞ TAKIMI
   if(input(pin_a2)) // TUÞ "1" BASILDI
   {
   while(input(pin_a2));
   x[2]=1;
   durum=durum+1;
   }
   
      if(input(pin_a3))// TUÞ "2" BASILDI
   {
   while(input(pin_a3));
   x[2]=2;
   durum=durum+1;
   }
   
         if(input(pin_a4))// TUÞ "3" BASILDI
   {
   while(input(pin_a4));
   x[2]=3;
   durum=durum+1;
   }
   
         if(input(pin_a5))// TUÞ "4" BASILDI
   {
   while(input(pin_a5));
   x[2]=4;
   durum=durum+1;
   }
 
       if(input(pin_c0))// TUÞ "5" BASILDI
   {
   while(input(pin_c0));
   x[2]=5;
   durum=durum+1;
   }
   
          if(input(pin_c1))// TUÞ "6" BASILDI
   {
   while(input(pin_c1));
   x[2]=6;
   durum=durum+1;
   }
   
          if(input(pin_c2))// TUÞ "7" BASILDI
   {
   while(input(pin_c2));
   x[2]=7;
   durum=durum+1;
   }
 
        if(input(pin_c3))// TUÞ "8" BASILDI
   {
   while(input(pin_c3));
   x[2]=8;
   durum=durum+1;
   }
   
          if(input(pin_c4))// TUÞ "9" BASILDI
   {
   while(input(pin_c4));
   x[2]=9;
   durum=durum+1;
   }
   
          if(input(pin_c5))// TUÞ "#" BASILDI
   {
   while(input(pin_c5));
   x[2]=10;
   durum=durum+1;
   }
   
          if(input(pin_c6))// TUÞ "0" BASILDI
   {
   while(input(pin_c6));
   x[2]=0;
   durum=durum+1;
   }
   
          if(input(pin_c7))// TUÞ "*" BASILDI
   {
   while(input(pin_c7));
   x[2]=11;
   durum=durum+1;
   }
   }


   if(durum==3){

         // TUÞ TAKIMI
   if(input(pin_a2)) // TUÞ "1" BASILDI
   {
   while(input(pin_a2));
   x[3]=1;
   durum=durum+1;
   }
   
      if(input(pin_a3))// TUÞ "2" BASILDI
   {
   while(input(pin_a3));
   x[3]=2;
   durum=durum+1;
   }
   
         if(input(pin_a4))// TUÞ "3" BASILDI
   {
   while(input(pin_a4));
   x[3]=3;
   durum=durum+1;
   }
   
         if(input(pin_a5))// TUÞ "4" BASILDI
   {
   while(input(pin_a5));
   x[3]=4;
   durum=durum+1;
   }
 
       if(input(pin_c0))// TUÞ "5" BASILDI
   {
   while(input(pin_c0));
   x[3]=5;
   durum=durum+1;
   }
   
          if(input(pin_c1))// TUÞ "6" BASILDI
   {
   while(input(pin_c1));
   x[3]=6;
   durum=durum+1;
   }
   
          if(input(pin_c2))// TUÞ "7" BASILDI
   {
   while(input(pin_c2));
   x[3]=7;
   durum=durum+1;
   }
 
        if(input(pin_c3))// TUÞ "8" BASILDI
   {
   while(input(pin_c3));
   x[3]=8;
   durum=durum+1;
   }
   
          if(input(pin_c4))// TUÞ "9" BASILDI
   {
   while(input(pin_c4));
   x[3]=9;
   durum=durum+1;
   }
   
          if(input(pin_c5))// TUÞ "#" BASILDI
   {
   while(input(pin_c5));
   x[3]=10;
   durum=durum+1;
   }
   
          if(input(pin_c6))// TUÞ "0" BASILDI
   {
   while(input(pin_c6));
   x[3]=0;
   durum=durum+1;
   }
   
          if(input(pin_c7))// TUÞ "*" BASILDI
   {
   while(input(pin_c7));
   x[3]=11;
   durum=durum+1;
   }
   }


   if(durum==1)  // durum çubuklarý
   {
   output_high(pin_d4);
   }
   
      if(durum==2)
   {
   output_high(pin_d5);
   }
   
      if(durum==3)
   {
   output_high(pin_d6);
   }
   
      if(durum==4)
   {
   output_high(pin_d7);
   }  
}        
}
