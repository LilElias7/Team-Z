#include <xc.h>
#define _XTAL_FREQ 8000000
// CONFIG1
#pragma config FOSC = INTRC_CLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

int adc=0;
int adc1=0;
void main(void) {
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    ANSEL=0B00000001;
    ANSELH=0B00000000;
    ADCON0bits.ADON=1;
    ADCON0bits.GO_nDONE=0;
    ADCON0bits.CHS=0000;
    ADCON0bits.ADCS=10;
    ADCON1bits.ADFM=0;
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    TRISA=0b00000001;
    TRISD=0b00000000;
    TRISB=0b00000000;
     TRISC=0b00000000;
    PORTD=0b00000000;
    PORTB=0b00000000;
    PORTC=0b00000000;
    __delay_ms(100);
    while(1){
        ADCON0bits.GO_nDONE=1;
        while(ADCON0bits.GO_nDONE){
        adc=ADRESH;
        PORTD=ADRESH;
        adc1=ADRESL;
        PORTC=adc1;
        }
    }
    return;
}