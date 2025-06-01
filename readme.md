# Juego de la Vida en C

Este proyecto implementa el Juego de la Vida de Conway en C, utilizando operaciones a nivel de bits para optimizar el uso de memoria y paralelismo con OpenMP para mejorar el rendimiento.

---

## Requisitos

- Compilador C con soporte para OpenMP (e.g., GCC)  
- Biblioteca estándar de C  
- Sistema operativo compatible con ANSI escape codes para la salida en consola  
- Biblioteca `unistd.h` para pausas automáticas (disponible en sistemas POSIX)  

---

## Compilación

1. Clonar el repositorio o descargar los archivos.
2. Ejecutar el siguiente comando en el directorio raíz:

   ```bash
   make
   ```

Esto generará el ejecutable `game_of_life`.

---

## Ejecución

Ejecutar el programa con:

```bash
./game_of_life [manual]
```

- Si se pasa `manual` como argumento (e.g., `./game_of_life manual`), el programa espera que presiones Enter para avanzar a la siguiente generación.  
- Sin argumentos, usa un retraso automático de 0.5 segundos entre generaciones.

---

## Configuración

Las constantes del proyecto (tamaño del tablero, generaciones, hilos) se encuentran en:

```text
include/config.h
```

---

## Estructura del Proyecto

- `include/`: Archivos de cabecera con definiciones.  
- `src/`: Implementaciones de las funciones.  
- `Makefile`: Script para compilación.  
- `README.md`: Este archivo.  

---

## Características

- Representación del tablero con operaciones a nivel de bits (`uint64_t`).  
- Paralelismo con OpenMP para cálculos de generaciones.  
- Visualización generación por generación con pausa automática o manual.  
- Documentación completa siguiendo estándares de C.  