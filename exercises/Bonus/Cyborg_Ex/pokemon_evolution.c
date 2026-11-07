/*
   We're building a pokemon clone and need a POC for the evolution system.
   For now, we only need a headless solution of pure game logic.

   A pokemon evolves during a level up event and their new level matches the
   next tier of the evolution line level requirement. Evolving a pokemon should
   entail the following:
   - Increase in stats
   - Change in species
   - If the pokemon's name is the same as its species, change its name to
   the name of the species


   Write a level-up function that does the following:
   - Apply a stat and level increase
   - Evolve the pokemon if the level matches the minimum requirement in the
   next evolution line

   Bonus:
   - Implement items and evolution stones
   - Logic/Architecture for cancelling evolutions
   - Delta mathematics
   - Latency/UX considerations
   - Branching Evolutions (IE Eevee)

   -- Try getting rid of strings, perhaps by using enums
   -- Be deliberate with number type
   -- Avoid using the heap when doing things dynamically
   -- Species name == user selected for pokemon?
   -- Deevolutions
   -- Items

  --------------
  --- Create branching logic for Polywag (Gold & Silver) and classic Eevee
  --- Perhaps use the pokedex id
  --- Might also help to create a evolution_conditions struct and a check to
  ensure all conditions are met
  --------------

  char: 8 bits (1 byte)
  int: 32 bits (4 bytes)
  float: 32 bits (4 bytes)
  double: 64 bits (8 bytes)

  --------------

  WRITE UNIT TESTS FOR THE STRUCTS
  Create
  Read
  Update
  Delete
  Model
  Query

  Modeling refers to looking at the performance and tradeoffs of various data
  structures


   */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum { FIRE, GRASS, WATER, LIGHTNING, NORMAL } Type;
typedef enum { HEALING, EVOLUTION, STAT_BOOST, SKILL } Item_Type;

typedef struct {
  int attack;
  int defense;
  int speed;
} Stats;

typedef struct {
  double pokedex_id;
  int required_level;
  int required_item_id;
  char species_name[15];
} EvolutionStage;

typedef struct {
  int item_id;
  char name[15];
  int item_index;
  Type type;
} Item;

typedef struct {
  int id;
  int pokedex_id;
  char name[15];
  int species_index;
  char species_name[15];
  int level;
  Type type;
  Stats stats;
  EvolutionStage evolution_line[5];
} Pokemon;

Pokemon create_test_eevee();
Pokemon create_test_squirtle();
Pokemon level_up(Pokemon *pokemon);
void use_evolution_item_on_pokemon(Item item, Pokemon pokemon);

int main() {
  Pokemon squirtle = create_test_squirtle();
  level_up(&squirtle);

  return 0;
}

Pokemon create_test_squirtle() {
  Pokemon pokemon = {
      0}; // Be sure to zero-initialize this, otherwise garbage values

  pokemon.id = 42;
  pokemon.pokedex_id = 1;
  strcpy(pokemon.name, "Squirtle");
  pokemon.species_index = 0;
  strcpy(pokemon.species_name, "Squirtle");
  pokemon.level = 19;
  pokemon.type = WATER;
  pokemon.stats.attack = 30;
  pokemon.stats.defense = 40;
  pokemon.stats.speed = 20;

  pokemon.evolution_line[1].pokedex_id = 2;
  pokemon.evolution_line[1].required_level = 20;
  strcpy(pokemon.evolution_line[1].species_name, "Warturtle");

  pokemon.evolution_line[2].pokedex_id = 3;
  pokemon.evolution_line[2].required_level = 35;
  strcpy(pokemon.evolution_line[2].species_name, "Blastoise");

  return pokemon;
}

Pokemon create_test_eevee() {
  Pokemon pokemon = {0};

  pokemon.id = 67;
  pokemon.pokedex_id = 33;
  strcpy(pokemon.name, "Eve");
  pokemon.species_index = 0;
  strcpy(pokemon.species_name, "Eevee");
  pokemon.level = 19;
  pokemon.type = NORMAL;
  pokemon.stats.attack = 25;
  pokemon.stats.defense = 30;
  pokemon.stats.speed = 30;

  pokemon.evolution_line[1].pokedex_id = 34;
  pokemon.evolution_line[1].required_level = 0;
  pokemon.evolution_line[1].required_item_id = 20;
  strcpy(pokemon.evolution_line[1].species_name, "Vaporeon");

  pokemon.evolution_line[2].pokedex_id = 35;
  pokemon.evolution_line[2].required_level = 0;
  pokemon.evolution_line[2].required_item_id = 21;
  strcpy(pokemon.evolution_line[2].species_name, "Jolteon");

  pokemon.evolution_line[3].pokedex_id = 36;
  pokemon.evolution_line[3].required_level = 0;
  pokemon.evolution_line[3].required_item_id = 22;
  strcpy(pokemon.evolution_line[3].species_name, "Flareon");

  return pokemon;
}

Pokemon level_up(Pokemon *pokemon) {
  pokemon->level++;
  printf("%s leveled up to %d!\n", pokemon->name, pokemon->level);

  if (pokemon->level >=
          pokemon->evolution_line[pokemon->species_index + 1].required_level &&
      !pokemon->evolution_line[pokemon->species_index + 1].required_item_id) {
    pokemon->stats.attack = pokemon->stats.attack + pokemon->stats.attack * .15;
    pokemon->stats.defense =
        pokemon->stats.defense + pokemon->stats.defense * .18;
    pokemon->stats.speed = pokemon->stats.speed + pokemon->stats.speed * .12;
    pokemon->species_index++; // The species index is used to keep track of what
                              // level evolution the pokemon is on

    printf("What? %s is evolving!\n", pokemon->name);
    printf("...%s evolved into %s!\n", pokemon->species_name,
           pokemon->evolution_line[pokemon->species_index].species_name);
    printf("Attack +%.0f\n", round(pokemon->stats.attack * .15));
    printf("Defense +%.0f\n", round(pokemon->stats.defense * .18));
    printf("Speed +%.0f\n", round(pokemon->stats.speed * .12));

    strcpy(pokemon->name,
           pokemon->evolution_line[pokemon->species_index].species_name);
    strcpy(pokemon->species_name,
           pokemon->evolution_line[pokemon->species_index].species_name);

  } else {
    pokemon->stats.attack = pokemon->stats.attack + pokemon->stats.attack * .1;
    pokemon->stats.defense =
        pokemon->stats.defense + pokemon->stats.defense * .15;
    pokemon->stats.speed = pokemon->stats.speed + pokemon->stats.speed * .08;

    printf("Attack +%.0f\n", round(pokemon->stats.attack * .1));
    printf("Defense +%.0f\n", round(pokemon->stats.defense * .15));
    printf("Speed +%.0f\n", round(pokemon->stats.speed * .08));
  }

  return *pokemon;
}

void use_evolution_item_on_pokemon(Item item, Pokemon pokemon) {
  // for (int i = 1; i <)
  if (pokemon.level >=
      pokemon.evolution_line[pokemon.species_index + 1].required_level) {
    pokemon.species_index++;

    printf("What? %s is evolving!\n", pokemon.name);
    printf("...%s evolved into %s!\n", pokemon.species_name,
           pokemon.evolution_line[pokemon.species_index].species_name);
  } else {
    printf("It has no effect...");
  }
}
