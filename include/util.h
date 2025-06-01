/**
 * @file util.h
 * @brief Funciones utilitarias para entrada/salida y manejo del tablero.
 */

#ifndef UTIL_H
#define UTIL_H

#include "bitboard.h"

/**
 * @brief Prints the game board to the console.
 * @param board Pointer to the board to be printed.
 */
void display_board(const GameBoard *board);

/**
 * @brief Pauses execution between generations.
 * @param is_manual If 1, waits for user input; if 0, uses automatic delay.
 */
void pause_execution(int is_manual);

#endif /* UTIL_H */