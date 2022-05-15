
# **Seminario de Sistemas Embebidos (86.65) - Trabajo Práctico N°1**
## **Facultad de Ingeniería - U.B.A**

### **Integrantes:**

  *Calcagno Alan - 98617*

  *Colombo Mateo - 98615*

  *Primón Agustín - 99000*

## 1) Guía/instructivo - Ejemplo 1_toggle

Una vez instalado en Windows el **CIAA Launcher** con todos los programas necesarios para la materia, se configuró el IDE **Eclipse** y se cargó la carpeta **firmaware_v3**. Luego instalamos y licenciamos el plug in de **Yakindu**. Una vez conlcuido lo anterior podemos conectar la placa EDU-CIAA y continuar con los siguientes items:

#### 1.1) 
Seleccionar el Workspace: *C:\CIAA\CIAA_Software_1.1-Win\workspaces\eclipse-ws*

#### 1.2) 
En el archivo program.mk podrá configurar el programa en el que se trabajará: PROGRAM_PATH = examples/c/sapi/statecharts PROGRAM_NAME = 1_toggle

![Modificación del archivo program.mk](https://drive.google.com/file/d/1hE8M2wSAhxe6hy9bvr2JIXrwG9WaF74c/view?usp=sharing)


#### 1.3)
En el archivo board.mk podrá configurar la placa a utilizar: BOARD = edu_ciaa_nxp

![Modificación del archivo program.mk](https://drive.google.com/file/d/1hE8M2wSAhxe6hy9bvr2JIXrwG9WaF74c/view?usp=sharing)

#### 1.4)
Verifique tener en la carpeta examples/c/sapi/statcharts/1_toggle/ los archivos:

##### 1.4.1) 
**toggle.sct** Yakindu SCT Statechart Model file
##### 1.4.2)
**toggle.sgen** Yakindu SCT Code Generator Model file

![Modificación del archivo program.mk](https://drive.google.com/file/d/1hE8M2wSAhxe6hy9bvr2JIXrwG9WaF74c/view?usp=sharing)

#### 1.5)
Para Editar el modelo: Doble clic sobre **toggle.sct**

#### 1.6)
Para simular el modelo: Clic derecho sobre **toggle.sct**->Run Us->Statechart Simulation

![Modificación del archivo program.mk](https://drive.google.com/file/d/1hE8M2wSAhxe6hy9bvr2JIXrwG9WaF74c/view?usp=sharing)

#### 1.7)
Para editar la generación de modelo: Doble clic sobre **toggle.sgen**

#### 1.8)
Para Generar el código del modelo: Clic derecho sobre **toggle.sgen** -> Generate Code Artifacts (Artifacts => gen/Toggle.c, gen/Toggle.h, gen/ToggleRequired.h y inc/sc_types.h)

#### 1.9)
Compilar firmware_v3 => Configurar Debug => Probar Debug

#### 1.10)
Documentar mediante tablas c/texto e imágenes la estructura de archivos, su tipo/contenido (especialmente readme.txt) de c/proyecto importado

#### 1.11) Conflictos y errores a lo largo de la primera ejecución.





## 2) Ejemplo 2_blink

## 3) Ejemplo 3_buttons

## 4) Ejemplo para TPF




