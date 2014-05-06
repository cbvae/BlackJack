#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>


#define MAX_NUM_CARDS_IN_HAND (11)
#define MAX_LEN_OF_NAME (31)
#define MAX_BET (100)
#define MIN_BET (10)
#define INITIAL_MONEY (1000)

typedef enum
{
    ACE = 0,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,

    /* Number of face */
    NUM_FACES
} Face;

typedef enum
{
    /* Spade, heart, club and diamond */
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND,

    /* Number of suits */
    NUM_SUITS
} Suit;

/* Total number of cards */
#define NUM_CARDS_IN_DECK (NUM_FACES * NUM_SUITS)

/* A card */
typedef struct
{
	Face face; // Card face
    Suit suit; // Card suit
} Card;

Card deck[NUM_CARDS_IN_DECK];

typedef struct
{
	unsigned int num_card;
	Card* cards;
} Dealer;

typedef struct
{
	unsigned int bet;
	unsigned int insurance;
	unsigned int num_card;
	Card* cards;
} Hand;

typedef struct
{
    char* name; // Player's name
    unsigned long money; // Player's money
    unsigned int num_hand;
    Hand* hand;
} Player;

typedef struct
{
	Dealer dealer;

	unsigned int num_player;
	Player* players;

	unsigned int cur_card_index;
	unsigned int total_cards;
	Card* decks;
} Global;

int rand_num(int num);

void init_deck(void);
void print_deck(void);
void shuffle_deck(void);

void init_dealer(Global* game);
void clean_dealer(Global* game);

void init_players(Global* game);
void clean_players(Global* game);

void init_game_decks(Global* game);
void clean_game_decks(Global* game);

void init_game(Global* game);
void clean_game(Global* game);

bool is_blackjack(Card* cards);
unsigned int get_cards_points(Card* cards, unsigned int num);




void play_game(Global* game);


void deal_card_to_player(Player* player, unsigned int index, Card card);
void deal_card_to_dealer(Dealer* dealer, Card card);

void bet_hand(Player* player, unsigned int index);
void insurance_hand(Player* player, unsigned int index);
void split_hand(Player* player, unsigned int index, Card card1, Card card2);
void double_hand(Player* player, unsigned int index, Card card);
void surrender_hand(Player* player, unsigned int index);
void stand_hand(Player* player, unsigned int index);

void find_winner_hand(Global* game, Player* player, unsigned int index);

void print_player(Player* player);
void print_hand(Hand* hand, unsigned int index);

#endif /* BLACKJACK_H_ */
