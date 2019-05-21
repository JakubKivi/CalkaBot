#include "header.h"
#include "motor.h"
#include "programs/program0.h"
#include "programs/program1.h"
#include "programs/program2.h"
#include "programs/program3.h"
#include "programs/program4.h"
#include "programs/program5.h"
#include "programs/program6.h"
#include "programs/program7.h"

void setup(){
	//pin mode
	pins();

	irrecv.enableIRIn();

	//turning on boarD
	//showStart();
	//delay(4500);
	//switch checking
	//builtLed2_ON;
	if(!status_but1) program |= (1<<0);
	if(!status_but2) program |= (1<<1);
	if(!status_but3) program |= (1<<2);
	//Serial.begin(9600);

	start = millis();
}



void loop(){


	while(readButton()){
		switch(program){
			case 0:
				program0();
				break;
			case 1:
				program1();
				break;
			case 2:
				program2();
				break;
			case 3:
				program3();
				break;
			case 4:
				program4();
				break;
			case 5:
				program5();
				break;
			case 6:
				program6();
				break;
			case 7:
				program7();
				break;
			default:
				error(3);
				break;
		}
	}
	builtLed1_OFF;
	builtLed2_OFF;
	slowStop();
	//showStart();
	byte check = irRemoute();
	program = 0x0;

	if(!status_but1) program |= (1<<0);
	if(!status_but2) program |= (1<<1);
	if(!status_but3) program |= (1<<2);
	if(check){
		while(readButton()){
			switch(program){
				case 0:
					program0();
					break;
				case 1:
					program1();
					break;
				case 2:
					program2();
					break;
				case 3:
					program3();
					break;
				case 4:
					program4();
					break;
				case 5:
					program5();
					break;
				case 6:
					program6();
					break;
				case 7:
					program7();
					break;
				default:
					error(3);
					break;
			}
		}
	}
	builtLed1_OFF;
	builtLed2_OFF;
	slowStop();
}