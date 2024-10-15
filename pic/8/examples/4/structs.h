struct datavec {
  int *is;
  double *ds;
  char *cs;
};
typedef struct datavec DataVec;

DataVec *iota_array(int);
void traverse(int, DataVec *);
void print_data_vec(DataVec *);
void free_vec(DataVec *);
