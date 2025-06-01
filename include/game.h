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
 * @param board Pointer to the initial game board.
 * @param generations Number of generations to simulate.
 * @param is_manual If 1, waits for user input to advance; if 0, uses automatic delay.
 */
void run_simulation(GameBoard *board, int generations, int is_manual);

#endif /* GAME_H */