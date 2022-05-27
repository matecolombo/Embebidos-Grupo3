/*Ejemplo que moverá un motor NEMA17 alimentado con 12VDC*/

/*
 * Date: 2022-05-25
 */

/*==================[inclusions]=============================================*/

#include "sapi.h"       // <= sAPI header
#include "sapi_board.h"

#include "sapi_tick.h"
#include "sapi_gpio.h"
#include "sapi_cyclesCounter.h"
#include "Nema17.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();
   gpioInit( GPIO2, GPIO_OUTPUT);
   gpioInit( GPIO4, GPIO_OUTPUT);

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

	   gpioWrite( DIR, ON );
	   for(int i = 0; i < 200; i++)
	   {
		   gpioWrite( STEP, ON );
		   delay(10);
		   gpioWrite( STEP, OFF );
		   delay(10);
	   }

	   delay(2000);

	   gpioWrite(DIR, OFF);

	   for(int i = 0; i < 200; i++)
	   {
	  		   gpioWrite( STEP, ON );
	  		   delay(10);
	  		   gpioWrite( STEP, OFF );
	  		   delay(10);
	   }

	   delay(2000);

   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
