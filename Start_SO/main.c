/* ###################################################################
**     Filename    : main.c
**     Project     : visualizacion
**     Processor   : MC9S08PT60VLH
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2022-05-17, 15:31, # CodeGen: 1
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LCD1.h"
#include "GI2C1.h"
#include "MCUC1.h"
#include "WAIT1.h"
#include "EI2C1.h"
#include "DataPin1.h"
#include "ClockPin1.h"
#include "WAIT2.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

int dx=-1;
int dy=-1;
int i;
int j;
int ball_x;
int ball_y;
int H = 128,V = 64;
int bandera_x=0, bandera_y=0;



void FuncionTarea1();
void ball();
void posicion();
/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  FuncionTarea1();
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
void FuncionTarea1(){

	
	LCD1_Clear();
	(void)LCD1_DisplayOn(TRUE);
	
	ball_x = 64;
	ball_y = 32;
	
	
	/*pelooota*/
	
	for(i = ball_x; i < ball_x+3; i++){
		for(j= ball_y; j < ball_y+3; j++){
		LCD1_PutPixel(i,j,TRUE); 
		}
	}
	//////////////////
	
	
	for (i = 0;i<H;i++){
		for(j = 0 ; j < V; j++){
			if( i == 1 || i == H - 3 || j == 1 || j == V-3){
			LCD1_PutPixel(i,j,TRUE);
			}
		}
	}
	
	
	for (j = 4 ; j < 7; j++){
			for(i = 24;i<39;i++){			
				LCD1_PutPixel(j,i,TRUE);
				
			}
		}
		
	for (j = 123 ; j < 126; j++){
				for(i = 24;i<39;i++){			
					LCD1_PutPixel(j,i,TRUE);
					
				}
			}

	LCD1_UpdateFull();
	//posicion(&ball_x,&ball_y,V,H,&dx,&dy);
	
	
	while(1){
		bandera_x = ball_x;
		bandera_y = ball_y;
		//Verificación
		if(ball_y == 1 || ball_y == V-3)
		{
			dy *= -1;
		}
		
		if(ball_x == 1 || ball_x == H-3)
		{
			dx *= -1;
		}
		//Modificar
		ball_x += (dx);
		ball_y += (dy);
		
		LCD1_PutPixel(ball_x,ball_y,TRUE);
	
		if(dx == -1 && dy == -1)
		{
			for(i = ball_x; i<=(bandera_x+3); i++)
			{
				for(j= ball_y; j<=(bandera_y+3); j++){
					if(i < ball_x + 2 && i >= ball_x)
					{
						if(j < ball_y + 2)
						{
							LCD1_PutPixel(i,j,TRUE);
						}
					}
					else {
						LCD1_PutPixel(i,j,FALSE);
					}
				}
				
			}
		}else if(dx == -1 && dy == 1)
		{
			for(i = ball_x; i<=(bandera_x+3); i++)
			{
				for(j= bandera_y; j<=(ball_y+3); j++){
					if(i <= ball_x + 2  && j <= ball_y + 2 && j >= ball_y)
					{
						LCD1_PutPixel(i,j,TRUE);	
					}
					else {
						LCD1_PutPixel(i,j,FALSE);
					}
				}
			}
		}else if(dx == 1 && dy == 1)
		{
			for(i = bandera_x; i<=(ball_x+3); i++)
			{
				for(j= bandera_y; j<=(ball_y+3); j++){
					if(i >= ball_x && j >= ball_y)
					{
						LCD1_PutPixel(i,j,TRUE);	
					}
					else {
						LCD1_PutPixel(i,j,FALSE);
					}
				}
			}
		}
	LCD1_UpdateFull();
	}
}


	
/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
