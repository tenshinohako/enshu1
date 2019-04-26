#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

void init_device(void);
void main_control(void);
void printChar(void);
interrupt void IntKey(void);  /* for key interruption */

//System Clock
#define gSystemClock_d     16000000

//Calculation of Baud rate
#define Uart_BrVal(baudrate) (gSystemClock_d/(baudrate*16))


void (* const _vect[])() @0xFFCE = { IntKey };  //Register at Interruption Vector

volatile char flag=0; //flag
volatile unsigned char c='A';

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
	SOPT1_COPE=0;// Disable Watchdog
	
	SCIBDH=( (Uart_BrVal(38400) >>8) & 0xFF); //Set Baud Rate 
	SCIBDL=(Uart_BrVal(38400) & 0xFF); //Set Baud Rate
	SCIC1=0;
	SCIC2=0xc;
	SCIC3=0;
	
	PTCDD_PTCDD0 = 1; //Direction set for KMD0
	PTCD_PTCD0 = 0; // Set Value of KMD0
	
	PTBDD_PTBDD0 = 0; //Direction set for Key1
	PTBDD_PTBDD1 = 0;// Key2
		
	KBI1PE_KBIPE0 = 1; //Enable Key1
	KBI1PE_KBIPE1 = 1; // Key2
	
	PTBPE_PTBPE0 = 1; //Pullup enable for Key1
	PTBPE_PTBPE1 = 1; // key2
		
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
	int i,j;
//	char d=0;
	
	for(i=0; i<300; i++)
		for(j=0; j< 300; j++);
	
	if(flag==1){
		/*
		while (SCIS1_TDRE == 0){d ++;} // 送信バッファのクリア待ち
		SCID = c++;
		if(c>'Z') c = 'A';
		*/
		printChar();
		PTAD_PTAD0 = ~PTAD_PTAD0;
		PTAD_PTAD4 = ~PTAD_PTAD4;
		PTDD_PTDD0 = ~PTDD_PTDD0;
		PTDD_PTDD1 = ~PTDD_PTDD1;
	}
}

void printChar(void) {
	while (SCIS1_TDRE == 0);// 送信バッファのクリア待ち
	SCID = c++;
	if(c>'Z') c = 'A';
}

interrupt void IntKey(void) {
	if (PTBD_PTBD0==0){ //Check value of KB1
		flag=1;
	}else{
		flag=0;
	}
	KBI1SC_KBACK = 1; //End interrupt
}
