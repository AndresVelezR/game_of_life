/**
 * @file util.c
 * @brief Implementación de funciones utilitarias.
 *
 * Este archivo contiene funciones para entrada/salida, manejo del tablero y control de pausas.
 */

#include <stdio.h>
#include <unistd.h> // Para usleep
#include "util.h"
#include "config.h"

/**
 * @brief Imprime el tablero en la consola.
 * @param board Puntero al tablero a imprimir.
 */
void display_board(const GameBoard *board) {
    printf("\033[H\033[J"); // Limpiar consola (código de escape ANSI)
    for (int row = 0; row < BOARD_ROWS; row++) {
        for (int col = 0; col < BOARD_COLS; col++) {
            printf("%c ", (board->grid[row] >> col) & 1 ? 'O' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Pausa la ejecución entre generaciones.
 * @param manual Si es 1, espera entrada del usuario; si es 0, usa retraso automático.
 */
void pause_execution(int is_manual) {
    if (is_manual) {
        printf("Press Enter to continue to the next generation...\n");
        getchar(); // Esperar entrada del usuario
    } else {
        usleep(500000); // Retraso de 0.5 segundos (500,000 microsegundos)
    }
}