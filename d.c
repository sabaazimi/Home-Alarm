#include <wiringPi.h>
#include <stdio.h>
#include "ifttt.h"


void alarm_init();
void alarm_off();
void alarm_arming();
void alarm_armed();
void alarm_triggered();
void email_submission();
void alarm_init(){
	 printf("start Init\n");
  wiringPiSetup () ;
  pinMode (0, INPUT);
  pinMode (1, OUTPUT) ;
  pinMode (2, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (3, INPUT) ;
  pullUpDnControl(3, PUD_UP) ;
  digitalWrite (1, HIGH) ;
  digitalWrite (2,  LOW) ;
  digitalWrite (4,  LOW) ;
  
  
  printf("end init\n");
	}

void alarm_off()
{
	alarm_init();
	delay(1000);
	for(;;){
		int x = digitalRead(3);
		if(x ==0){
		alarm_arming();
		}
	}
 
}
void alarm_arming(){
	int i ;
	digitalWrite(1, LOW);
  for (i=0;i<3;i++) {
    digitalWrite (1, HIGH) ; delay (500) ;
    digitalWrite (1,  LOW) ; delay (500) ;
  }
  digitalWrite (2,  HIGH) ;
  digitalWrite (4,  LOW) ;
  alarm_armed();
	}


void alarm_armed(){
	printf("inside alarm_armed\n");
	wiringPiSetup () ;
	digitalWrite (2,HIGH) ;
	pinMode(0, INPUT);
	
	for(;;){
		int x = digitalRead(3);
		if(x ==0){
		alarm_off();	
		}
		if(digitalRead(0) == 1){
			printf("sensor Detected\n");
			for (int i=0;i < 10000;i++) {
				delay(1);
			int x = digitalRead(3);
				if(x ==0){
				alarm_off();	
			}
		}
		printf("time is up\n");
		alarm_triggered();
			} 
		
	}
	/*while(1) {
		int x = digitalRead(3);
		if(x == 0){
			alarm_off();
		}
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    /*alarm_triggered();
    printf("Alarm\n");
  }*/
	}



void alarm_triggered(){
	
	digitalWrite (1, HIGH) ;
	digitalWrite (2,  HIGH) ;
	digitalWrite (4,  HIGH) ;
	delay(2000);
	digitalWrite (1, LOW) ;
	digitalWrite (2,  LOW) ;
	digitalWrite (4,  LOW) ;
	printf("email submission is initiated\n");
	email_submission();
	for(;;){
		int x = digitalRead(3);
		if(x ==0){
		alarm_off();
		}
	}
	
	}

void email_submission(){
	
	printf("Trying to connect to server\n");
  ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/cOHWoBOVnz2E_7xPiNLBga", "my1", "my 2", "my 33333");
	
	}

