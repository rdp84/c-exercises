
// Preprcoessor will just do a simple expansion for this
#define forever(x) forever(forever(x))

int main(void)
{
  forever(more); // so preprocessor will replace this with forever(forever(more))
  return 0;
}
