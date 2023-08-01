int count, i , left , right , counter=0;

void interrupt(){
if(INTF_bit){
INTF_bit = 0 ;
if(portb.b1){}      //to handle pressing on change button without entering the manual mode
else{
if(!counter==0 || !counter==1) counter=0 ;
counter++ ;
if(counter==1){ ;
portd = 0b00100001 ;
porta.b0 = 0 ; porta.b1 = 1 ;
for(count=3 ; count>=0 ; --count){
portc = count ;
delay_ms(1000) ;
}
porta.b0 = 1 ; porta.b1 = 1 ;
 portd = 0b0001010 ;
}
else if(counter==2){
portd = 0b00001100 ;
porta.b0 = 0 ; porta.b1 = 1 ;
for(count=3 ; count>=0 ; --count){
portc = count ;
delay_ms(1000) ;
}
porta.b0 = 1 ; porta.b1 = 1 ;
 portd = 0b00010001 ;

}


}
}     //if intf
}    //void interrupt


void main() {
adcon1 = 7 ;
trisc = trisa = trisd = 0 ;
trisb.b0 = 1 ;
trisb.b1 = 1 ;
portb = 1 ;
portd = portc = 0 ;
porta.b0 = 1 ;
porta.b1 = 1;
gie_bit = 1 ;
INTE_bit = 1 ;
intedg_bit = 0 ;
portd = 0b00010001 ; //to initialize red, green leds if started with manual mode.
//automatic mode
for(;;){
        if(portb.b1 && portb.b0){
                    //street1 auto control
                    for(count = 23 ; count >= 0 ; count--){
                              if(portb.b1 == 0 && portb.B0==1){
                                          portd = 0b00010001 ;
                                          porta.b0 = 1 ; porta.b1 = 1 ;
                                                   }
                              else{
                                   if(count==0)
                                                portd = 0b00001010 ;
                              else if(count<=3)
                                               portd = 0b00100001;

                               else {
                                                portd = 0b00010001 ;
                                     }

                                left = count/10;
                                right = count%10 ;
                                     }
      for( i = 0 ; i < 50 ; ++i){
              if(portb.b1 == 0 && portb.B0==1){
                          portd = 0b00010001 ;
                          porta.b0 = 1 ; porta.b1 = 1 ;
                                                  }
              else{
              porta.b1 = 1 ;   //tens tr is off
            porta.B0= 0 ;  //ones tr is on
            portc=right ;
            delay_ms(10);
              porta.b1  = 0 ;   //tens tr is off
            porta.B0= 1 ;
            portc =left ;


            delay_ms(10);
            }


              }
              }

              //street2 auto control
for(count = 15 ; count >= 0 ; count--){
if(portb.b1 == 0 && portb.B0==1){
portd = 0b00010001 ;
porta.b0 = 1 ; porta.b1 = 1 ;
}
else{
         if(count==0)
         portd = 0b00010001 ;
          else if(count<=3)
         portd = 0b00001100;

         else {
         portd = 0b00001010 ;
         }
      left = count/10;
      right = count%10 ;
     // portd = 0b00010001 ;
     }
      for( i = 0 ; i < 50 ; ++i){
            if(portb.b1 == 0 && portb.B0==1){
portd = 0b00010001 ;
porta.b0 = 1 ; porta.b1 = 1 ;
}
else{
            porta.b1 = 1 ;   //tens tr is off
            porta.B0= 0 ;  //ones tr is on
            portc=right ;
            delay_ms(10);
              porta.b1  = 0 ;   //tens tr is off
            porta.B0= 1 ;
            portc =left ;


            delay_ms(10);
            }


              }
              }

          



     
       }


      }


      }