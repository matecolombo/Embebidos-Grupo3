# Trabajo Práctico n°2 - Uso de GPIOs

En el presente trabajo se muestra como configurar y utilizar el perisférico GPIO, basandonos en el ejemplo Blinky.c
El mismo hace uso de las siguientes librerias siguiendo una jerarquia de incluciones: 

* **sapi.h:** Incluye todas las librerias de sapi, que configuran perisfericos u otras funcionalidades.
* **sapi_board.h:** Define la función *BoardConfig/BoardInit*, declarada en **sapi_board.c**, que inicializa ciertos pines como GPIO definiendolos como entradas o salidas.
* **sapi_gpio.h:** Definen las funciones que configuran directamente los pines.
* **sapi_datatype.h, sys_config.h, cmsis.h:** Actúan el la ultima capa de abstracción accediendo a los registros. Son definidas por ARM y NXP.

Nuestro trabajo se basa en la utilización de un motor paso a paso NEMA17, que necesita para su control dos pines configurados como salida. Por ende, en nuestra implementación nosotros configuramos dos pines extra (GPIO2 y GPIO4) como salida, 
además de los configurados en *BoardInit*. El primero lo utilizaremos para indicar la cantidad de pasos que debe dar el motor, y el segundo pin indica la dirección de giro del mismo. 
Para mayor entendimiento del código definiremos en **NEMA17.h** el GPIO2 como DIR y GPIO4 como STEP.
