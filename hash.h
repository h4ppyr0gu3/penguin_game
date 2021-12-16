typedef struct {
  char* key;
  int value;
} item;

item* linear_search(item* items, size_t size, const char* key) {
  for (size_t i=0; i<size; i++) {
    if (strcmp(items[i].key, key) == 0) {
      return &items[i];
    }
  }
  return NULL;
}

// USE CASE !!

//   item variables[] = {
//     {"x_value", 0}, {"y_value", 0}, {"penguin_count", 3000}, {"player_count", 0}, {"fish_count", 0}
//   };
//   size_t num_items = sizeof(variables) / sizeof(item);
//   item* found = linear_search(variables, num_items, "penguin_count");
//     if (!found) {
//         return 1;
//     }
//   printf("linear_search: value of 'bob' is %d\n", found->value);
//   return 0;
