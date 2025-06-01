/**
 * @file bitboard.h
 * @brief Definiciones para el manejo del tablero utilizando operaciones a nivel de bits.
 *
 * Este archivo contiene las definiciones de estructuras y funciones para representar
 * el tablero del Juego de la Vida como un arreglo de bits, optimizando memoria y
 * operaciones mediante manipulación bit a bit.
 */

#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>
#include "config.h"

/** @brief Data type for a single row of the game board (64 bits). */
typedef uint64_t BoardRow;

/** @brief Structure representing the complete game board. */
typedef struct {
    BoardRow grid[BOARD_ROWS]; /**< Array of rows, each represented as a 64-bit integer. */
} GameBoard;

/**
 * @brief Inicializa el tablero con un patrón aleatorio.
 * @param board Puntero al tablero a inicializar.
 */
void initialize_random_board(GameBoard *board);

/**
 * @brief Cuenta los vecinos vivos de una celda utilizando operaciones bit a bit.
 * @param board Puntero al tablero.
 * @param row Fila de la celda.
 * @param col Columna de la celda.
 * @return Número de vecinos vivos.
 */
int count_living_neighbors(const GameBoard *board, int row, int col);

/**
 * @brief Actualiza el tablero a la siguiente generación utilizando paralelismo.
 * @param current Puntero al tablero actual.
 * @param next Puntero al tablero de la siguiente generación.
 */
void compute_next_generation(const GameBoard *current, GameBoard *next);

#endif /* BITBOARD_H */