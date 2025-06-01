/**
 * @file bitboard.c
 * @brief Implementación de operaciones a nivel de bits para el tablero.
 *
 * Este archivo implementa las funciones para manipular el tablero utilizando
 * operaciones bit a bit y paralelismo con OpenMP.
 */

#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "bitboard.h"
#include "config.h"

/**
 * @brief Inicializa el tablero con un patrón aleatorio.
 * @param board Puntero al tablero a inicializar.
 */
void initialize_random_board(GameBoard *board) {
    srand((unsigned)time(NULL));
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int row_idx = 0; row_idx < BOARD_ROWS; row_idx++) {
        BoardRow current_row = 0;
        for (int col_idx = 0; col_idx < BOARD_COLS; col_idx++) {
            if (rand() % 2) {
                current_row |= (1ULL << col_idx); // Set bit at position col_idx
            }
        }
        board->grid[row_idx] = current_row;
    }
}

/**
 * @brief Cuenta los vecinos vivos de una celda utilizando operaciones bit a bit.
 * @param board Puntero al tablero.
 * @param row Fila de la celda.
 * @param col Columna de la celda.
 * @return Número de vecinos vivos.
 */
int count_living_neighbors(const GameBoard *board, int row, int col) {
    int count = 0;
    // Adjust indices for toroidal (wraparound) boundaries
    int prev_row_idx = (row - 1 + BOARD_ROWS) % BOARD_ROWS;
    int next_row_idx = (row + 1) % BOARD_ROWS;
    int prev_col_idx = (col - 1 + BOARD_COLS) % BOARD_COLS;
    int next_col_idx = (col + 1) % BOARD_COLS;

    // Check all 8 neighboring cells
    count += (board->grid[prev_row_idx] >> prev_col_idx) & 1;
    count += (board->grid[prev_row_idx] >> col) & 1;
    count += (board->grid[prev_row_idx] >> next_col_idx) & 1;
    count += (board->grid[row] >> prev_col_idx) & 1;
    count += (board->grid[row] >> next_col_idx) & 1;
    count += (board->grid[next_row_idx] >> prev_col_idx) & 1;
    count += (board->grid[next_row_idx] >> col) & 1;
    count += (board->grid[next_row_idx] >> next_col_idx) & 1;

    return count;
}

/**
 * @brief Actualiza el tablero a la siguiente generación utilizando paralelismo.
 * @param current Puntero al tablero actual.
 * @param next Puntero al tablero de la siguiente generación.
 */
void compute_next_generation(const GameBoard *current, GameBoard *next) {
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int row_idx = 0; row_idx < BOARD_ROWS; row_idx++) {
        BoardRow next_gen_row = 0;
        for (int col_idx = 0; col_idx < BOARD_COLS; col_idx++) {
            int neighbor_count = count_living_neighbors(current, row_idx, col_idx);
            int is_alive = (current->grid[row_idx] >> col_idx) & 1;
            
            // Game of Life rules
            if (is_alive && (neighbor_count == 2 || neighbor_count == 3)) {
                next_gen_row |= (1ULL << col_idx); // Cell stays alive
            } else if (!is_alive && neighbor_count == 3) {
                next_gen_row |= (1ULL << col_idx); // Cell is born
            }
        }
        next->grid[row_idx] = next_gen_row;
    }
}