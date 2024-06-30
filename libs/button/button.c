#include "button.h"


#define LED_PORT PORTB
#define BUTTON_PORT PORTC
#define BUTTON_PIN PINC
#define LED_DDR DDRB
#define BUTTON_DDR DDRC
#define BUTTON1 PC1
#define BUTTON2 PC2
#define BUTTON3 PC3
#define LED1 PB2
#define LED2 PB3
#define LED3 PB4
#define LED4 PB5







void enableButton( int button ) {

   DDRC &= ~_BV( button );

}





int buttonPushed( int button ) {

    //PORTC |= _BV( button );
    
   if (bit_is_clear( PINC, button )){
    
    return 1;

    }
    else if (!bit_is_clear( PINC, button )) {
        
        return 0;
        
    }


}






int buttonReleased( int button ) {
    
    if ( buttonPushed( button ) == 1){
        
        if ( bit_is_clear( PINC, button )){
            
            return 0;
            
        }
        else{
            return 1;
        }
    
    }else {
        
        return 0;
    
    }


}






void enableAllButtons() {


    DDRC &= ~_BV( BUTTON1);
    DDRC &= ~_BV( BUTTON2 );
    DDRC &= ~_BV( BUTTON3 );


}




void checkPressedButton() {


    enableAllButtons();
    

    while (1) 
    {

        initUSART();
            

        if (buttonPushed(BUTTON1) ==  0)   {
            
            

            printf( " - Button 1 pressed!\n" );

            _delay_ms(200);

            


            if (buttonReleased(BUTTON1) == 1) {
                
            printf(" - Button 1 Released!\n");
            _delay_ms(200);
            
            
            }

            
        

        }
        


        if (buttonPushed(BUTTON2) ==  0)   {

            printf( " - Button 2 pressed!\n" );



            _delay_ms(200);


            if (buttonReleased(BUTTON2) == 1) {
            printf(" - Button 2 Released!\n");
            _delay_ms(200);
            
            }

            
        

        }



        if (buttonPushed(BUTTON3) ==  0)   {

            printf( " - Button 3 pressed!\n" );



            _delay_ms(200);


            if (buttonReleased(BUTTON3) == 1) {
            printf(" - Button 3 Released!\n");
            _delay_ms(200);
            
            }

            
        

        }


        



    }


    
}



int returnPressedButton() {


    enableAllButtons();

    int volatile button = 0;
    
    

    while (1) 
    {

        _delay_ms(200);

        initUSART();
            

        if (buttonPushed(BUTTON1) ==  0)   {

            button = 1;
            
            return button;

        }
        


        if (buttonPushed(BUTTON2) ==  0)   {

           // printf( " - Button 2 pressed!\n" );

           button = 2;

            return button;

            
        

        }



        if (buttonPushed(BUTTON3) ==  0)   {

          // printf( " - Button 3 pressed!\n" );

          button = 3;

            return button;

        

        }



    }


    
}




void enableButtonInterrupt(int button) {
    
    PCICR |= _BV( PCIE1 );  
    PCMSK1 |= _BV( button );   
    sei();  

}





void enableAllButtonInterrupts() {
    
    
    PCICR |= _BV( PCIE1 );  
    PCMSK1 |= _BV( BUTTON1 ); 
    PCMSK1 |= _BV( BUTTON2 );   
    PCMSK1 |= _BV( BUTTON3 );   
    sei(); 

}




void trafficLight() {




    LED_DDR |= _BV( LED1 ) | _BV( LED2 ) | _BV( LED3 ) | _BV( LED4 );   // we'll use led1 and led2
    LED_PORT |= _BV( LED1 ) | _BV( LED2 ) | _BV( LED3 ) | _BV( LED4 );  // turn 2 leds off
    BUTTON_DDR &= ~_BV( BUTTON1 ) | ~_BV( BUTTON2 ) | ~_BV( BUTTON3 );          // we'll use button1
    BUTTON_PORT |= _BV( BUTTON1 ) | _BV( BUTTON2 ) | _BV( BUTTON3 ); 

    while (1)
    {

        int i = returnPressedButton();

        printf("%d", i);

        enableButtonInterrupt(i);
        
    }
    



}






