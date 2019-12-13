#include <string.h>
#include <stdio.h>

#include "block.h"


void hash_block(struct block *block) {
  memset(block->current_hash, 0, SHA512_DIGEST_LENGTH);

  size_t size = sizeof(struct block);
  unsigned char hash[SHA512_DIGEST_LENGTH];
  SHA512((void *) block, size, hash);

  memcpy(block->current_hash, hash, SHA512_DIGEST_LENGTH);
}

void reset_hash(unsigned char *hash) {
  memset(hash, 0, SHA512_DIGEST_LENGTH);
}

void copy_hash(unsigned char *dest, unsigned char *src) {
  memcpy(dest, src, SHA512_DIGEST_LENGTH);
}

void generate_random(struct block *block) {
  struct transaction *transactions = block->transactions;

  for (int i = 0; i < TRANSACTIONS_PER_BLOCK; i++) {
    struct transaction *transaction = &transactions[i];
    transaction->from = i * 3;
    transaction->to = i * 3 + 1;
    transaction->amount = i * 3 + 2;
    memset(transaction->payload, 0, PAYLOAD_SIZE);
  }
}

void print_transaction(struct transaction *transaction) {
  printf("%ld to %ld of %ld\n", transaction->from, transaction->to, transaction->amount);
}

void print_hash(unsigned char *hash) {
  for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
    printf("%02x ", hash[i]);
  }
}


void print_block(struct block *block) {
  printf("prev: "); 
  print_hash(block->previous_hash); 
  printf("\n");
  printf("curr: "); 
  print_hash(block->current_hash); 
  printf("\n");

  // struct transaction *transaction = block->transactions;

  // for (int i = 0; i < TRANSACTIONS_PER_BLOCK; i++) {
  //   print_transaction(&transaction[i]);
  // }
}