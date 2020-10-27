
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NDEALS    3000 /* Number of deals */
#define NPLAYERS  6    /* Number of players */

typedef enum {clubs, diamonds, hearts, spades} cdhs;

typedef struct {
  int   pips;
  cdhs  suit;
} card;

card  assign_values(int pips, cdhs suit);
void  prn_card_values(card *);
void  play_poker(card deck[52]);
void  shuffle(card deck[52]);
void  swap(card *p, card *q);
void  deal_the_cards(card deck[52], card hand[NPLAYERS][5]);
int   is_flush(card h[5]);
