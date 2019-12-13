#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>
#include <openssl/sha.h>

#define TRANSACTIONS_PER_BLOCK 32
#define PAYLOAD_SIZE 64

typedef uint64_t addr_t;


struct transaction {
  addr_t from;
  addr_t to;
  uint64_t amount;
  char payload[PAYLOAD_SIZE];
};

struct block {
  struct transaction transactions[32];

  unsigned char previous_hash[SHA512_DIGEST_LENGTH];

  // needs to be 0 when you calculate the hash of the block
  unsigned char current_hash[SHA512_DIGEST_LENGTH];
};

void hash_block(struct block *);
void reset_hash(unsigned char *);
void copy_hash(unsigned char *dest, unsigned char *src);
void generate_random(struct block *);

void print_transaction(struct transaction *transaction);
void print_hash(unsigned char *hash);
void print_block(struct block *block);


#endif