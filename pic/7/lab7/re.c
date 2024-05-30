#include <stdlib.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) { 
  arena_t arena = malloc(sizeof(struct arena));
  arena->size = size;
  arena->current = 0;
  arena->exprs = malloc(size * sizeof(Regexp));

  return arena;
}

void arena_free(arena_t a) { 
  free(a->exprs);
  free(a);
}

Regexp *re_alloc(arena_t a) { 
  if (a->current < a->size) {
    Regexp *r = a->exprs + a->current;
    a->current += 1;
    return r;
  } else {
    return NULL;
  }
}

Regexp *re_chr(arena_t a, char c) { 
  Regexp *r = re_alloc(a);
  r->type = CHR;
  r->data.chr = c;

  return r;
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) { 
  Regexp *r = re_alloc(a);
  r->type = ALT;
  r->data.pair.fst = r1;
  r->data.pair.snd = r2;

  return r;
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) { 
  Regexp *r = re_alloc(a);
  r->type = SEQ;
  r->data.pair.fst = r1;
  r->data.pair.snd = r2;

  return r;
}

int re_match(Regexp *r, char *s, int i) { 
  int j;
  if (r != NULL) {
    switch (r->type) {
    case CHR:
      return r->data.chr == s[i] ? i+1 : -1;
    case SEQ:
      if (re_match(r->data.pair.fst, s, i) < 0) {
        return -1;
      } else {
        return re_match(r->data.pair.snd, s, i+1);
      }
    case ALT:
      j = re_match(r->data.pair.fst, s, i);
      if (j < 0) {
        return re_match(r->data.pair.snd, s, i);
      } else {
        return j;
      }
    default:
      return -1;
    }
  } else { 
    return -1;
  }
}

void re_print(Regexp *r) { 
  if (r != NULL) { 
    switch (r->type) {
    case CHR: 
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT) { 
	printf("(");
	re_print(r->data.pair.fst);
	printf(")");
      } else {
	re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT) { 
	printf("(");
	re_print(r->data.pair.snd);
	printf(")");
      } else {
	re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  } else { 
    printf("NULL");
  }
}    


      
  
