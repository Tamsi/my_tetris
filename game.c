/*
** game.c for  in /home/tbesson/projet_psu/Tetris
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Mar  3 14:20:16 2017 Tamsi Besson
** Last update Fri Mar  3 18:03:26 2017 Tamsi Besson
*/

#include "tetris.h"

char **malloc_map2d(int size, int len, char **map)
{
  int i;

  i = 0;
  map = malloc (len * sizeof(char *));
  while (i < size + 1)
    {
      map[i] = malloc (size * sizeof(char) + 1);
      i++;
    }
  return (map);
}

char **game_map(char **tetris, char **av)
{
  int x;
  int y;
  int i;
  int j;

  x = my_getnbr(av[2]) - 1;
  y = my_getnbr(av[1]) - 1;
  tetris = malloc_map2d(y, x, tetris);
  i = 0;
  while (i < y)
    {
      j = 0;
      while  (j < x)
        {
          tetris[i][j] = ' ';
          j++;
        }
      i++;
    }
  return (tetris);
}

char **set_tetrimino(char **map, int k, char *tetrimino)
{
  int i;
  int j;

  i = my_strlen(map[1]) / 2;
  j = 0;
  while (tetrimino[j])
  {
    if (tetrimino[j] == '\n')
      k++;
    else
      map[k][i] = tetrimino[j];
    if (tetrimino[j] == '*' && tetrimino[j + 1] != '\n')
      i++;
    j++;
  }
  return (map);
}

char **erase_tetrimino(char **map, int k, char *tetrimino)
{
  int i;
  int j;

  i = my_strlen(map[1]) / 2;
  j = 0;
  while (tetrimino[j])
  {
    if (tetrimino[j] == '\n')
      k++;
    else
      map[k][i] = ' ';
    if (tetrimino[j] == '*' && tetrimino[j + 1] != '\n')
      i++;
    j++;
  }
  return (map);
}

char **disp_map(char **map, WINDOW *game)
{
  int i;
  int j;

  i = 1;
  while (map[i])
    {
      j = 1;
      while  (map[i][j] != '\0')
        {
          mvwaddch(game, i, j, map[i][j]);
          j++;
        }
      i++;
    }
  return (map);
}

void ii(char **map, WINDOW *game)
{
  int k;

  k = 1;
  while (map[k + 2] != NULL)
  {
    map = disp_map(map, game);
    map = set_tetrimino(map, k, "*\n*\n**");
    printf("%i\n", k);
    if (map[k + 4] != NULL)
      map = erase_tetrimino(map, k, "*\n*\n**");
    k++;
  }
}
