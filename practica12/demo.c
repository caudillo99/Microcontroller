//#include Your libraries

#define LED_P (1<<PF4)
#define LED_M (1<<PF5)

#define DISCHARGE_VALUE 300

void ADC_Init(void){
  ADMUX = (1<<REFS0) | (5<<MUX0); // VREF = AVCC
  ADCSRA = (1<<ADEN) | (7<<ADPS0); // ADC On, PS=128
  ADCSRB = 0;//(1<<MUX5); // AMUX = ADC5
}

uint16_t ADC_Read(){
  ADCSRA |= 1<<ADSC; // ADC Start Convertion
  while ((ADCSRA>>ADSC)&1)
    ;
  return ADC;
}

void blink(void){
  PORTF|=LED_P;
  PORTF&=~LED_M;
  delay(1);
  PORTF&=~LED_P;
  delay(99);
}

void PrintAdc(void){
  uint16_t adcValue = 0; 
  adcValue = ADC_Read();
  for(uint8_t i = 0; i<(adcValue/25); i++){
    UART_putchar(0,'.');
  }
  UART_puts(0,adcValue);
}

int main(){
  uint32_t timestamp = 0;
  char string[8];
  // Configure as output both pins
  DDRF |= (LED_M|LED_P);
  ADC_Init();
  //UART_Init
  
  while(1){

    if (ADC_Read()<DISCHARGE_VALUE)
    {
      PrintAdc();
      UART_puts(0,"\t[");
      // Measure the discharge time
      itoa(millis()-timestamp,string,10);
      UART_puts(0,string);
      UART_puts(0,"]");
      
      //Configure '-' pin as output
      DDRF |= (LED_M);
      // Visual queue, needed only for debugging
      blink();
      // Inverse polarization of the LED
      PORTF&=~LED_P;
      PORTF|=LED_M;
      // Small delay to "charge" it
      delay(1);
      // Float the charging pin
      DDRF&=~LED_M;
      PORTF&=~LED_M;
      // Timestamp to measure the discharge time
      timestamp = millis();
      PrintAdc();  
      UART_puts(0,"\n");
    }    
  }
  
  return 0;
}