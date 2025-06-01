/**
 * @file game.c
 * @brief Implementación de la lógica del Juego de la Vida.
 *
 * Este archivo contiene la lógica principal para ejecutar la simulación, mostrando
 * el tablero generación por generación.
 */

#include <stdio.h>
#include <string.h>
#include "game.h"
#include "util.h"

/**
 * @brief Ejecuta la simulación del Juego de la Vida, mostrando cada generación.
 * @param board Puntero al tablero inicial.
 * @param generations Número de generaciones a simular.
 * @param manual Si es 1, espera entrada del usuario para avanzar; si es 0, usa retraso automático.
 */
void run_simulation(GameBoard *board, int generations, int is_manual) {
    GameBoard next_gen;
    memset(&next_gen, 0, sizeof(GameBoard));

    for (int current_gen = 0; current_gen < generations; current_gen++) {
        display_board(board); // Show current board state
        printf("Generation %d/%d\n", current_gen + 1, generations);
        
        // Calculate next generation
        compute_next_generation(board, &next_gen);

        // Copy next generation back to current board
        #pragma omp parallel for num_threads(NUM_THREADS)
        for (int row = 0; row < BOARD_ROWS; row++) {
            board->grid[row] = next_gen.grid[row];
        }

        // Pause to visualize the generation
        pause_execution(is_manual);
    }
    
    // Display the final generation
    display_board(board);
    printf("Simulation completed (%d generations).\n", generations);
}