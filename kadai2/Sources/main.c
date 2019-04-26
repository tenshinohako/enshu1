#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */


void init_device(void);
void main_control(void);
interrupt void IntKey(void);

void (* const_vect[])() @0xFFCE = {IntKey};

volatile char flag = 0;
unsigned char count = 0;

void main(void) {
  EnableInterrupts;
  /* include your code here */


  init_device();
  

  for(;;) {
	  main_control();
    //__RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}


void init_device(void){
/*
	SOPT1_COPE = 0;
	
	//LED output
	PTADD_PTADD0 = 1;
	PTADD_PTADD4 = 1;
	PTDDD_PTDDD0 = 1;
	PTDDD_PTDDD1 = 1;
	
	//KMD0 = 0
	PTCDD_PTCDD0 = 1;
	PTCD_PTCD0 = 0;
	
	//enable Key
	KBI1PE_KBIPE0 = 1;
	KBI1PE_KBIPE1 = 1;
	KBI1PE_KBIPE2 = 1;
	
	//Key input
	PTBDD_PTBDD0 = 0;
	PTBDD_PTBDD1 = 0;
	PTBDD_PTBDD2 = 0;
	
	//Key pullup
	PTBPE_PTBPE0 = 1;
	PTBPE_PTBPE1 = 1;
	PTBPE_PTBPE2 = 1;
	
	PTAD_PTAD0 = 1;
	PTAD_PTAD4 = 1;
	PTDD_PTDD0 = 1;
	PTDD_PTDD1 = 1;
	
	KBI1SC_KBIE = 1;
*/
	SOPT1_COPE=0;// Disable Watchdog
	
	PTCDD_PTCDD0 = 1; //Direction set for KMD0
	PTCD_PTCD0 = 0; // Set Value of KMD0
	
	PTBDD_PTBDD0 = 0; //Direction set for Key1
	PTBDD_PTBDD1 = 0;// Key2
	PTBDD_PTBDD2 = 0;// Key3
		
	KBI1PE_KBIPE0 = 1; //Enable Key1
	KBI1PE_KBIPE1 = 1; // Key2
	KBI1PE_KBIPE2 = 1; // Key3
	
	PTBPE_PTBPE0 = 1; //Pullup enable for Key1
	PTBPE_PTBPE1 = 1; // key2
	PTBPE_PTBPE2 = 1; // key3
		
	PTADD_PTADD0 = 1;//Direction set for LED1
	PTADD_PTADD4 = 1;//Direction set for LED2
	PTDDD_PTDDD0 = 1;//Direction set for LED3
	PTDDD_PTDDD1 = 1;//Direction set for LED3
	
	PTAD_PTAD0 = 1;
	PTAD_PTAD4 = 1;
	PTDD_PTDD0 = 1;
	PTDD_PTDD1 = 1;

	KBI1SC_KBIE = 1; // Enable Keyboard Interrupt
}

void main_control(void){
/*
	PTAD_PTAD0 = 1 & ~(count>>3);
	PTAD_PTAD4 = 1 & ~(count>>2);
	PTDD_PTDD0 = 1 & ~(count>>1);
	PTDD_PTDD1 = 1 & ~count;
	
	if(flag == 1){
		unsigned int i = 0;
		unsigned int j = 0;
		count++;
		for(i=0; i<300; i++)
			for(j=0; j<1000; j++);
	}
*/
	PTAD_PTAD0 = 0x1 & ~count;
	PTAD_PTAD4 = 0x1 & ~count>>1;
	PTDD_PTDD0 = 0x1 & ~count>>2;
	PTDD_PTDD1 = 0x1 & ~count>>3;
	
	if(flag==1){
		unsigned int i = 0;
		unsigned int j = 0;
		count++;
		for(i=0; i<300; i++)
			for(j=0; j<300; j++);
	}
}

interrupt void IntKey(void){
/*
	if (PTBD_PTBD0 == 0){ 
		flag = 1;
	}else if(PTBD_PTBD1 == 0){
		flag = 0;
	}else if (PTBD_PTBD2 == 0){
		count = 0;
	}
	KBI1SC_KBACK = 1;
*/
	if (PTBD_PTBD0==0){ //Check value of KB1
		flag=1;
	}else if(PTBD_PTBD1==0){
		flag=0;
	}else{
		count=0;
	}
	KBI1SC_KBACK = 1; //End interrupt
}
