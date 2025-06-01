/**
 * @file util.h
 * @brief Funciones utilitarias para entrada/salida y manejo del tablero.
 */

#ifndef UTIL_H
#define UTIL_H

#include "bitboard.h"

/**
 * @brief Imprime el tablero de juego en la consola.
 * @param board Puntero al tablero que se va a imprimir.
 */
void display_board(const GameBoard *board);

/**
 * @brief Pausa la ejecución entre generaciones.
 * @param is_manual Si es 1, espera entrada del usuario; si es 0, usa retraso automático.
 */
void pause_execution(int is_manual);

#endif /* UTIL_H */