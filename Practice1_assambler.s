PROCESSOR 16F887
#include <xc.inc>
config FOSC = INTRC_CLKOUT
 config WDTE = OFF       
 config PWRTE = OFF       
 config MCLRE = ON       
 config CP = OFF        
 config CPD = OFF        
 config BOREN = ON       
 config IESO = ON        
 config FCMEN = ON       
 config LVP = OFF        
 config DEBUG=ON
// CONFIG2
 config BOR4V = BOR40V   
 config WRT = OFF       
 
PSECT udata
tick:
    DS 1
counter:
    DS 1    
counter2:
    DS 1
RESULTLO:
    DS 1
RESULTHI:
    DS 1

PSECT code
delay2:
movlw 0x08
movwf counter
counter_loop2:
movlw 0xff
movwf tick
tick_loop2:
decfsz tick,f
goto tick_loop2
decfsz counter,f
goto counter_loop2
return
    
PSECT resetVec,class=CODE,delta=2
resetVec:
goto main
        
PSECT main,class=CODE,delta=2
main:
BANKSEL TRISA ;
BSF TRISA,0 
BANKSEL ANSEL ;
BSF ANSEL,0 
BANKSEL ADCON0 ;
MOVLW 0B10000001 
MOVWF ADCON0 
BANKSEL ADCON1 
MOVLW 0b00000000 
MOVWF ADCON1 
BANKSEL OSCCON
movlw 0b01110000
Movwf OSCCON
BANKSEL TRISC
movlw 0b00000000
movwf TRISC
movlw 0b00000000
movwf TRISD
BANKSEL PORTC
movlw 0b00000000
movwf PORTC
    movlw 0b00000000
movwf PORTD
INICIO:
call delay2
BSF ADCON0,1 
BTFSC ADCON0,1 
GOTO $-1 
BANKSEL ADRESH 
MOVF ADRESH,W 
movwf PORTD
goto INICIO
END resetVec


