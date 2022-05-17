
# **Seminario de Sistemas Embebidos (86.65) - Trabajo Práctico N°1**
## **Facultad de Ingeniería - U.B.A**

### **Integrantes:**

  *Calcagno Alan - 98617*

  *Colombo Mateo - 98615*

  *Primón Agustín - 99082*

## 1) Guía/instructivo - Ejemplo 1_toggle

Una vez instalado en Windows el **CIAA Launcher** con todos los programas necesarios para la materia, se configuró el IDE **Eclipse** y se cargó la carpeta **firmaware_v3**. Luego instalamos y licenciamos el plug in de **Yakindu**. Una vez conlcuido lo anterior podemos conectar la placa EDU-CIAA y continuar con los siguientes items:

#### 1.1) 
Seleccionar el Workspace: *C:\CIAA\CIAA_Software_1.1-Win\workspaces\eclipse-ws*

#### 1.2) 
En el archivo program.mk podrá configurar el programa en el que se trabajará: PROGRAM_PATH = examples/c/sapi/statecharts PROGRAM_NAME = 1_toggle

![Modificación del archivo program.mk](https://github.com/matecolombo/Robot-Jardinero/blob/6bf8ad108e5bf607c34b56a1e7538894aaca3426/TP1/Imagenes_TP1/Item%201/select_program.PNG)


#### 1.3)
En el archivo board.mk podrá configurar la placa a utilizar: BOARD = edu_ciaa_nxp

![Includes en archivo board.mk](https://github.com/matecolombo/Robot-Jardinero/blob/67263f8ae2f6c72e95644966950391462b45893e/TP1/Imagenes_TP1/Item%201/includes.PNG)

#### 1.4)
Verifique tener en la carpeta examples/c/sapi/statcharts/1_toggle/ los archivos:

##### 1.4.1) 
**toggle.sct** Yakindu SCT Statechart Model file
##### 1.4.2)
**toggle.sgen** Yakindu SCT Code Generator Model file

![Archivos del Yakindu](https://github.com/matecolombo/Robot-Jardinero/blob/67263f8ae2f6c72e95644966950391462b45893e/TP1/Imagenes_TP1/Item%201/1_Toggle.PNG)

#### 1.5)
Para Editar el modelo: Doble clic sobre **toggle.sct**

![Diagrama de estados del modelo](https://github.com/matecolombo/Robot-Jardinero/blob/67263f8ae2f6c72e95644966950391462b45893e/TP1/Imagenes_TP1/Item%201/modelo.PNG)

#### 1.6)
Para simular el modelo: Clic derecho sobre **toggle.sct**->Run Us->Statechart Simulation

![Secuancia de pasos para simular el modelo](https://github.com/matecolombo/Robot-Jardinero/blob/67263f8ae2f6c72e95644966950391462b45893e/TP1/Imagenes_TP1/Item%201/Simulacion.png)

#### 1.7)
Para editar la generación de modelo: Doble clic sobre **toggle.sgen**

![...](https://github.com/matecolombo/Robot-Jardinero/blob/67263f8ae2f6c72e95644966950391462b45893e/TP1/Imagenes_TP1/Item%201/generador.PNG)

#### 1.8)
Para Generar el código del modelo: Clic derecho sobre **toggle.sgen** -> Generate Code Artifacts (Artifacts => gen/Toggle.c, gen/Toggle.h, gen/ToggleRequired.h y inc/sc_types.h)

![Secuancia de pasos para generar código a partir del modelo de Yakindu](https://github.com/matecolombo/Robot-Jardinero/blob/57b0ff8d08d4ad0bed0c01417424829bffd83e38/TP1/Imagenes_TP1/Item%201/code_artifacts.png)

![Archivos generados](https://github.com/matecolombo/Robot-Jardinero/blob/57b0ff8d08d4ad0bed0c01417424829bffd83e38/TP1/Imagenes_TP1/Item%201/archivos_generados.PNG)

#### 1.9)
Compilar firmware_v3 => Configurar Debug => Probar Debug

![Debug en el inicio del programa.](https://github.com/matecolombo/Robot-Jardinero/blob/36db7542b412ec276b2664d99ce9734db73080a2/TP1/Imagenes_TP1/Item%201/debug_1.PNG)
![Debug en el inicio del programa.](https://github.com/matecolombo/Robot-Jardinero/blob/36db7542b412ec276b2664d99ce9734db73080a2/TP1/Imagenes_TP1/Item%201/debug_2.PNG)

#### 1.10)
Documentar mediante tablas c/texto e imágenes la estructura de archivos, su tipo/contenido (especialmente readme.txt) de c/proyecto importado

A continuacion seguiremos paso a paso la ejecución del programa de ejemplo **1_toggle**. En las imagenes anteriores se puede ver la invocación de las funciones de inicialización del programa. El *main()* funciona como el *setup()* del programa.
Comenzamos con la inicializacion de la placa llamando a *boardConfig()*, función declarada en **sapi_board.h** y definida en **sapi_board.c**. La misma llama internamente a *boardInit()* que configura el hardware directamente.

![Función *boardInit()*](https://github.com/matecolombo/Robot-Jardinero/blob/889549c8f92f1e6cd3b2c1c34f5afff307796310/TP1/Imagenes_TP1/Item%201/board_config_init.PNG)

Luego se invoca a la función *tickConfig(TICKRATE_MS)*, función declarada en **sapi_tick.h** y definida en **sapi_tick.c**. La misma llama internamente a *tickInit()* que configura la frecuencia de los ticks de la placa. El define TICKRATE_MS esta seteada en 1000 tick por segundos.

![Función *tickInit()*](https://github.com/matecolombo/Robot-Jardinero/blob/889549c8f92f1e6cd3b2c1c34f5afff307796310/TP1/Imagenes_TP1/Item%201/tick_config_init.PNGG)

Lo siguiente que se ejecuta es la función *tickCallBackSet(myTickHook, (void)\* NULL)*, función que define una rutina de interrupción a utilizar. (Chequear!)

![Función *tickCallBackSet()*](https://github.com/matecolombo/Robot-Jardinero/blob/99fdcd19ee16df4198bfac966046ea52dddea712/TP1/Imagenes_TP1/Item%201/tick_hook.PNG)

A continuación se llamarán dos funciones definidas y declaradas en **Toggle.h/c**. Tanto estos archivos como las funciones dentro son generadas a partir del diagrama de estados hecho en Yakindu. Se les pasará a las funciones *toggle_init(&statechart)* y *toggle_enter(&statechart)* el modelo generado para ser alterado dentro de las mismas.

![Definición del objeto](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/statechart_toggle.PNG)

![Declaración del objeto y primitivas](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/toggle_struct.PNG)

*toggle_init()* inicializa en cero todas las posiciones de un vector de estados y limpia eventos entrantes o salientes inicializando tales campos en cero.

![Función *toggle_init()*](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/toggle_init_statemachine.PNG)

Habiendo concluido el "*setup*" del programa, ingresamos en el *loop* principal del programa implementado mediante un *while(1)*. A continuación comentaremos las funciones que se invocan dentro:

![*While()*](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/main_while.PNG)

Lo primero que aparece es la función *__WFI()* (Wait For Interruption) definida en **cmsis_gcc.h**. Esta mantiene al microcontrolador en estado sleep hasta recibir una interrupción y cuando sale de este estado, mediante un condicional *if()*, preguntamos si la interrupción es la asociada al SysTick. Si es así, bajamos el flag, encolamos en evento con *toggleIface_raise_evTick(&statechart)* y luego lo ejecutamos con *toggle_RunCycle(&statechart)*.

![*toggleIface_raise_evTick()*](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/toggle_raise_interface.PNG)

![*toggle_RunCycle()*](https://github.com/matecolombo/Robot-Jardinero/blob/9165a3e5d080afb3b05dfdab4dced4ebeee688fe/TP1/Imagenes_TP1/Item%201/toggle_run_cycle.PNG)

En resumen la jerarquia de archivos puede resumirse con el siguiente esquema:

![Resumen de las clases de archivos implicados en los proyectos](https://github.com/matecolombo/Robot-Jardinero/blob/57b0ff8d08d4ad0bed0c01417424829bffd83e38/TP1/Imagenes_TP1/Item%201/diagrama%20de%20archivos.drawio.png)

#### 1.11) Conflictos y errores a lo largo de la primera ejecución.

**Primera compilación.**

Luego de la primera instalación y configuración inicial cuando se trató de compilar el projecto, salieron errores relacionados a las ubicaciones de ciertos archivos. Comparando mi pantalla con las capturas del instructivo me di cuenta que habia iniciado el Eclipse con otra direccion para rl workspace.

**Primer debug**

Luego de haber compilado sin errores y configurar el debuggeo, al precionar debug aparecia una ventana mencionando un error con respecto al OCD. Repasando el instructivo me di cuenta que habia olvidado ejecutar el zadig por lo que no me estaba reconociendo el puerto correcto. 

**Version de Yakindu**

La licencia que tenemos de Yakindu no funciona en la última versión (4.0.5) del software disponible como plug in de Eclipse ingresando a *Help->Eclipse->Marketplace*, por lo que tuvimos que instalar la versión anterior (3.4.1) desde *Help->Istall New Software*.


## 2) Ejemplo 2_blink

Este ejemplo empieza desde el punto n.8 ya que se comparte el método de subida del programa con el Toggle. Se empieza analizando desde el main: 

![blink_main](https://github.com/matecolombo/Robot-Jardinero/blob/b919a02cd5acdf047bea4c8e16bf737f2a81b7da/TP1/Imagenes_TP1/Item%202/blink_main.PNG)

Comenzamos con la inicializacion de la placa llamando a *boardConfig()*, función declarada en **sapi_board.h** y definida en **sapi_board.c**. La misma llama internamente a *boardInit()* que configura el hardware directamente.

Luego se invoca a la función *tickConfig(TICKRATE_MS)*, función declarada en **sapi_tick.h** y definida en **sapi_tick.c**. La misma llama internamente a *tickInit()* que configura la frecuencia de los ticks de la placa. El define TICKRATE_MS esta seteada en 1000 tick por segundos. Siguiendo con *TickCallbackSet( myTickHook , tickCallbackParams)* que recibe un puntero tickHook que define la interrupción a utilizar. Para finalizar las interrupciones por timer, la función *InitTimerTicks* que incializa los timers.

Por ultimo, antes del ciclo *while* se inicializa y definen los estados del sistema, pasandole el diagrama de estados realizado con Yakindu:

![blink_init&enter](https://github.com/matecolombo/Robot-Jardinero/blob/b919a02cd5acdf047bea4c8e16bf737f2a81b7da/TP1/Imagenes_TP1/Item%202/blin_init_&_enter.PNG)

Se puede ver en estas dos funciones mofidican el estado del sitema, init hace la inicilizacion del vector de estados y luego enter activa un estado.

Luego, adentrandonos al *while*, aparece *__WFI()* que pone al micro en estado *sleep* a la espera de una interrupción.

Siguiendo, nos encontramos con el if que evalua si hay alguna flag de interrupcion, entramos se baja el flag para hablilitar una nueva y se updatean los timers.

A continuación, nos encontramos con un ciclo *for*

![blink_raise_time](https://github.com/matecolombo/Robot-Jardinero/blob/b919a02cd5acdf047bea4c8e16bf737f2a81b7da/TP1/Imagenes_TP1/Item%202/blink_raise_time_event.PNG)



![blink_mark_asAtt_event](https://github.com/matecolombo/Robot-Jardinero/blob/b919a02cd5acdf047bea4c8e16bf737f2a81b7da/TP1/Imagenes_TP1/Item%202/mark_as_at_event_blink.PNG)

![blink_run_cycle](https://github.com/matecolombo/Robot-Jardinero/blob/b919a02cd5acdf047bea4c8e16bf737f2a81b7da/TP1/Imagenes_TP1/Item%202/blin_run_cycle.PNG)

## 3) Ejemplo 3_buttons

La funcion tickCallbackSet es una funcion que llama a la rutina de interrupcion que se llevara a cabo, en este caso será setear SysTick_Time_Flag en true.

![Funcion mytickhook](https://github.com/matecolombo/Robot-Jardinero/blob/main/TP1/Imagenes_TP1/Item%203/mytickhook.png?raw=true)

Otra función que cabe destacar es Buttons_GetStatus.

![Funcion buttons_getstatus](https://github.com/matecolombo/Robot-Jardinero/blob/main/TP1/Imagenes_TP1/Item%203/buttons_getstatus.png)

Esta función nos retorna la variable *"Ret"* que nos indica que pulsador fue apretado seteando un 1 lógico en dicha posición (leido de derecha a izquierda), en caso de pulsarse dos o mas botones, estos quedan registrados.

En el main esta variable se llama BUTTON_Status, y de no ser nula, se toma como evento *evTECXOprimido* en la máquina de estados (caso contrario) *evTECXNoOprimido*, y se corre un ciclo de la máquina de estados buttons_runCycle.

![Captura Main](https://github.com/matecolombo/Robot-Jardinero/blob/main/TP1/Imagenes_TP1/Item%203/main.png)

**Aquí existen dos escenarios posibles:**

### Boton pulsado

Si se oprimen uno o mas pulsadores, la máquina de estados espera 100ms (a fin de evitar un rebote o error de lectura) y de seguir pulsado activa el estado opLED (prende el LED3), caso contrario vuelve al estado **no oprimido**.

### Boton no pulsado

No se modifica el estado **No oprimido**.

Se puede ver que el diagrama de estados que tiene el programa es el explicado anteriormente.

![Captura Main](https://github.com/matecolombo/Robot-Jardinero/blob/main/TP1/Imagenes_TP1/Item%203/estados_buttons.png)

## 4) Ejemplo para TPF




