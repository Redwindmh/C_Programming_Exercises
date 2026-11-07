#include <stdio.h>

typedef struct {
  char name[20];
  char type[10];
  int level;
} Pokemon;

void returnPokemonName(Pokemon pokemon);

int main() {
  Pokemon Pikachu = {"Pikachu", "Electric", 10};
  returnPokemonName(Pikachu);

  return 0;
}

void returnPokemonName(Pokemon pokemon) {
  printf("This pokemon's name is %s.\n", pokemon.name);
  printf("This pokemon's type is %s.\n", pokemon.type);
}
