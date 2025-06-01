/**
 * @file config.h
 * @brief Configuraciones globales para el Juego de la Vida.
 *
 * Define constantes y parámetros configurables para el proyecto.
 */

#ifndef CONFIG_H
#define CONFIG_H

/** @brief Tamaño del tablero en filas. */
#define BOARD_ROWS 64
/** @brief Tamaño del tablero en columnas. */
#define BOARD_COLS 64
/** @brief Número de generaciones por simular. */
#define GENERATIONS 100
/** @brief Número de hilos para paralelismo con OpenMP. */
#define NUM_THREADS 4

#endif /* CONFIG_H */