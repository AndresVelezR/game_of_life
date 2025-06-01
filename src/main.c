/**
 * @file main.c
 * @brief Punto de entrada del programa Juego de la Vida.
 *
 * Este archivo inicializa el tablero y ejecuta la simulación.
 */

#include <string.h>
#include "bitboard.h"
#include "game.h"
#include "config.h"

int main(int argc, char *argv[]) {
    GameBoard game_board;
    int is_manual_mode = (argc > 1 && strcmp(argv[1], "manual") == 0);
    
    // Initialize the game with a random pattern
    initialize_random_board(&game_board);
    
    // Run the simulation
    run_simulation(&game_board, GENERATIONS, is_manual_mode);
    
    return 0;
}