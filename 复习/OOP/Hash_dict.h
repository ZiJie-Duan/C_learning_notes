#ifndef HASH_DICT
#define HASH_DICT

const int Hash_Size = 100;

typedef struct hash_node
{
    /* data */
    const char *key;
    void *value;
    struct hash_node *next;
} Hash_node;

typedef Hash_node (*Hash_dict);

int hash_convert(const char * string);
void hash_linked_add(const char *key, void *value, int index, Hash_dict hdict);
Hash_dict hdict_create(void);
void hdict_add(const char *key, void *value, Hash_dict hdict);
void hdict_print(Hash_dict hdict);

#endif