#include <stddef.h>

typedef struct {
  char *data;
  size_t size;
} String;

void nvim_err_writeln(String str);
