#include "queen_attack.h"
#include <stdint.h>
#include <stdio.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    int q1r = queen_1.row;
    int q1c = queen_1.column;
    int q2r = queen_2.row;
    int q2c = queen_2.column;

    /* Validar rangos primero */
    if (q1r < 0 || q1r >= 8 || q1c < 0 || q1c >= 8 ||
        q2r < 0 || q2r >= 8 || q2c < 0 || q2c >= 8)
    {
        printf("Invalid position\n");
        return INVALID_POSITION;
    }

    /* Misma casilla */
    if (q1r == q2r && q1c == q2c)
    {
        printf("Invalid position\n");
        return INVALID_POSITION;
    }

    /* Inicializar tablero para evitar leer basura */
    char board[8][8];
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            board[r][c] = '.';

    /* Colocar reinas */
    board[q1r][q1c] = 'q';
    board[q2r][q2c] = 'q';

    /* Misma fila o columna */
    if (q1r == q2r || q1c == q2c)
    {
        printf("Same row or column. CAN ATTACK!\n");
        return CAN_ATTACK;
    }

    /* Buscar en las cuatro diagonales (moviendo primero, comprobando límites, luego accediendo) */

    /* 1ª diagonal: arriba-izquierda */
    {
        int i = q1r;
        int j = q1c;
        while (1)
        {
            i--; j--;
            if (i < 0 || j < 0 || i >= 8 || j >= 8) break;
            printf("Queen moving to %d %d\n", i, j);
            if (board[i][j] == board[q2r][q2c])
            {
                printf("Same diagonal. CAN ATTACK!\n");
                return CAN_ATTACK;
            }
        }
        printf("Can not attack on first diagonal\n");
    }

    /* 2ª diagonal: arriba-derecha */
    {
        int k = q1r;
        int l = q1c;
        while (1)
        {
            k--; l++;
            if (k < 0 || l < 0 || k >= 8 || l >= 8) break;
            printf("Queen moving to %d %d\n", k, l);
            if (board[k][l] == board[q2r][q2c])
            {
                printf("Same diagonal. CAN ATTACK!\n");
                return CAN_ATTACK;
            }
        }
        printf("Can not attack on second diagonal\n");
    }

    /* 3ª diagonal: abajo-derecha */
    {
        int m = q1r;
        int n = q1c;
        while (1)
        {
            m++; n++;
            if (m < 0 || n < 0 || m >= 8 || n >= 8) break;
            printf("Queen moving to %d %d\n", m, n);
            if (board[m][n] == board[q2r][q2c])
            {
                printf("Same diagonal. CAN ATTACK!\n");
                return CAN_ATTACK;
            }
        }
        printf("Can not attack on third diagonal\n");
    }

    /* 4ª diagonal: abajo-izquierda */
    {
        int o = q1r;
        int p = q1c;
        while (1)
        {
            o++; p--;
            if (o < 0 || p < 0 || o >= 8 || p >= 8) break;
            printf("Queen moving to %d %d\n", o, p);
            if (board[o][p] == board[q2r][q2c])
            {
                printf("Same diagonal. CAN ATTACK!\n");
                return CAN_ATTACK;
            }
        }
        printf("Can not attack on fourth diagonal\n");
    }

    printf("Can not attack!\n");
    return CAN_NOT_ATTACK;
}
