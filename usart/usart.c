#include <mega8.h>

#include <delay.h>

#include <stdio.h>
 float Humidity1=0,Humidity2=0,adc[3];  
 eeprom float  DailyAverage1=0,DailyAverage2=0,Sample1[2],Sample2[2];
 int Graph1[7],Graph2[7];
 int tenth=0,Min=0,Sec=0,Min1=0,Hour=0,Day=0;
// External Interrupt 0 service routine



#ifndef RXB8
#define RXB8 1
#endif

#ifndef TXB8
#define TXB8 0
#endif

#ifndef UPE
#define UPE 2
#endif

#ifndef DOR
#define DOR 3
#endif

#ifndef FE
#define FE 4
#endif

#ifndef UDRE
#define UDRE 5
#endif

#ifndef RXC
#define RXC 7
#endif

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)

// USART Receiver buffer
#define RX_BUFFER_SIZE 64
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index,rx_rd_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;

status=UCSRA;
data=UDR;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   rx_buffer[rx_wr_index++]=data;
#if RX_BUFFER_SIZE == 256
   // special case for receiver buffer size=256
   if (++rx_counter == 0) rx_buffer_overflow=1;
#else
   if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
   if (++rx_counter == RX_BUFFER_SIZE)
      {
      rx_counter=0;
      rx_buffer_overflow=1;
      }
#endif
   } 

   
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;
while (rx_counter==0);
data=rx_buffer[rx_rd_index++];
#if RX_BUFFER_SIZE != 256
if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
#endif
#asm("cli")
--rx_counter;
#asm("sei")
return data;
}
#pragma used-
#endif

// USART Transmitter buffer
#define TX_BUFFER_SIZE 100
char tx_buffer[TX_BUFFER_SIZE];

#if TX_BUFFER_SIZE <= 256
unsigned char tx_wr_index,tx_rd_index,tx_counter;
#else
unsigned int tx_wr_index,tx_rd_index,tx_counter;
#endif

// USART Transmitter interrupt service routine
interrupt [USART_TXC] void usart_tx_isr(void)
{
if (tx_counter)
   {
   --tx_counter;
   UDR=tx_buffer[tx_rd_index++];
#if TX_BUFFER_SIZE != 256
   if (tx_rd_index == TX_BUFFER_SIZE) tx_rd_index=0;
#endif
   }
}

#ifndef _DEBUG_TERMINAL_IO_
// Write a character to the USART Transmitter buffer
#define _ALTERNATE_PUTCHAR_
#pragma used+
void putchar(char c)
{
while (tx_counter == TX_BUFFER_SIZE);
#asm("cli")
if (tx_counter || ((UCSRA & DATA_REGISTER_EMPTY)==0))
   {
   tx_buffer[tx_wr_index++]=c;
#if TX_BUFFER_SIZE != 256
   if (tx_wr_index == TX_BUFFER_SIZE) tx_wr_index=0;
#endif
   ++tx_counter;
   }
else
   UDR=c;
#asm("sei")
}
#pragma used-
#endif

// Standard Input/Output functions


// Timer2 output compare interrupt service routine


#define ADC_VREF_TYPE 0x00

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}

interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
  tenth++;
    if(tenth==10){
      Sec++,tenth=0;
      if(Sec==60){ 
        Min1++,Min++,Sec=0; 
        if(Min==2){
         adc[0]=read_adc(0);        
         adc[1]=read_adc(1);       
         adc[2]=read_adc(2);
         Min=0;   
         } 
         
         if(Min1==60){
          Hour++,Min1=0; 
          if(Hour==12){
          Sample1[0]=adc[0];
          Sample2[0]=adc[1];
          }
           
            if(Hour==24){
             Sample1[1]=adc[0];
             Sample2[1]=adc[1];           
             Day++,Hour=0;
             if(Day==7){
              Day=0;
           }
          }
        }


    }
 }
}
 interrupt [EXT_INT0] void ext_int0_isr(void)
{

        adc[0]=read_adc(0);        
        adc[1]=read_adc(1);       
        adc[2]=read_adc(2);  
        Humidity1=(adc[0]-560)/5.6;
        Humidity2=(adc[1]-560)/5.6;  
        printf("Humidity1=%7.2f",Humidity1);
        delay_ms(3000);
        printf("Humidity2=%7.2f",Humidity2); 
       

}



// Declare your global variables here
void main(void)
{
  //  printf("welcom");

// Declare your local variables here

// Input/Output Ports initialization
// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=0 State5=0 State4=0 State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0xF0;

// Port C initialization
// Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x0F;
TCNT2=0x00;
OCR2=0x60;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
GICR|=0x40;
MCUCR=0x02;
GIFR=0x40;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x80;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 4800
UCSRA=0x00;
UCSRB=0xD8;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x0C;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC Clock frequency: 500.000 kHz
// ADC Voltage Reference: AREF pin
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x81;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Global enable interrupts
#asm("sei")



while (1)
   { 

         
          if(Min==1) {
            Humidity1=(adc[0]-580)/5.6;
            Humidity2=(adc[1]-580)/5.6;
            printf("Humidity1=%7.2f",Humidity1);
            delay_ms(3000);
            printf("Humidity2=%7.2f",Humidity2);
            while(Min==1){}
          }  
                    
          if(Min==0||Min==1||Min==2){       
           DailyAverage1=(Sample1[0]+Sample1[1])/2;       
           DailyAverage2=(Sample2[0]+Sample2[1])/2;               
           Graph1[6]=DailyAverage1;       
           Graph2[6]=DailyAverage2;       
           printf("Graph1=%d",Graph1[6]);
           delay_ms(3000);
           printf("Graph2=%d",Graph2[6]);
           Graph1[6]<<1;       
           Graph2[6]<<1;      
                  
                  
                  
          }           
    }
 }
