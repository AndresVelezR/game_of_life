/**
 * @file game.h
 * @brief Lógica principal del Juego de la Vida.
 *
 * Define las funciones para ejecutar la simulación del Juego de la Vida.
 */

#ifndef GAME_H
#define GAME_H

#include "bitboard.h"

/**
 * @brief Ejecuta la simulación del Juego de la Vida, mostrando cada generación.
 * @param board Puntero al tablero de juego inicial.
 * @param generations Número de generaciones a simular.
 * @param is_manual Si es 1, espera entrada del usuario para avanzar; si es 0, usa retraso automático.
 */
void run_simulation(GameBoard *board, int generations, int is_manual);

#endif /* GAME_H */