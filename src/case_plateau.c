#include <case_plateau.h>

CasePlateau construct_CasePlateau(int x, int y)
{
  CasePlateau casePlateau;
  casePlateau.x = x;
  casePlateau.y = y;
  casePlateau.p_pionCase = NULL;
  casePlateau.typeDeCase = NORMAL;

  return casePlateau;
}
