// ref:
// * src/nvim/api/private/defs.h
// * src/nvim/api/vim.c

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool Boolean;
typedef int64_t Integer;
typedef double Float;
typedef int LuaRef;

typedef struct {
  char const *data;
  size_t size;
} String;

typedef enum {
  kErrorTypeNone = -1,
  kErrorTypeException,
  kErrorTypeValidation,
} ErrorType;

typedef struct {
  ErrorType type;
  char *msg;
} Error;

// the `KeyValuePair item` is too complex, just make it a pointer
typedef struct {
  size_t size;
  size_t capacity;
  void **items;
} Dictionary;

// no plans to access the array, so a pointer to a `void *` is enough
typedef struct {
  size_t size;
  size_t capacity;
  void **items;
} Array;

typedef enum {
  kObjectTypeNil = 0,
  kObjectTypeBoolean,
  kObjectTypeInteger,
  kObjectTypeFloat,
  kObjectTypeString,
  kObjectTypeArray,
  kObjectTypeDictionary,
  kObjectTypeLuaRef,
} ObjectType;

typedef struct {
  ObjectType type;
  union {
    Boolean boolean;
    Integer integer;
    Float floating;
    String string;
    Array array;
    Dictionary dictionary;
    LuaRef luaref;
  } data;
} Object;

void nvim_err_writeln(String str);

Object nvim_notify(String msg, Integer log_level, Dictionary opts,
                   Error *error);
