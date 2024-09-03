#include "gc.h"

Node *complete(int n, Alloc *a) {
  if (n == 0) {
    return NULL;
  } else {
    Node *sub = complete(n-1, a);
    Node *result = node(n, sub, sub, a);
    return result;
  }
}

int main(void) {
  Alloc *a = make_allocator();
  complete(5, a);
  gc(a);

  return 0;
}
