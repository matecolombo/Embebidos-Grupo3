
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

![Debug]()

#### 1.10)
Documentar mediante tablas c/texto e imágenes la estructura de archivos, su tipo/contenido (especialmente readme.txt) de c/proyecto importado

![Resumen de las clases de archivos implicados en los proyectos](https://github.com/matecolombo/Robot-Jardinero/blob/57b0ff8d08d4ad0bed0c01417424829bffd83e38/TP1/Imagenes_TP1/Item%201/diagrama%20de%20archivos.drawio.png)

#### 1.11) Conflictos y errores a lo largo de la primera ejecución.

**Primera compilación.**

Luego de la primera instalación y configuración inicial cuando se trató de compilar el projecto, salieron errores relacionados a las ubicaciones de ciertos archivos. Comparando mi pantalla con las capturas del instructivo me di cuenta que habia iniciado el Eclipse con otra direccion para rl workspace.

**Primer debug**

Luego de haber compilado sin errores y configurar el debuggeo, al precionar debug aparecia una ventana mencionando un error con respecto al OCD. Repasando el instructivo me di cuenta que habia olvidado ejecutar el zadig por lo que no me estaba reconociendo el puerto correcto. 

**Version de Yakindu**

La licencia que tenemos de Yakindu no funciona en la última versión (4.0.5) del software disponible como plug in de Eclipse ingresando a *Help->Eclipse->Marketplace*, por lo que tuvimos que instalar la versión anterior (3.4.1) desde *Help->Istall New Software*.


## 2) Ejemplo 2_blink

## 3) Ejemplo 3_buttons

## 4) Ejemplo para TPF




