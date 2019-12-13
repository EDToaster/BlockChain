#include <string.h>

#include "block.h"


int main(int argc, char **argv) {
  struct block blocks[3];

  struct block *genesis = blocks;

  reset_hash(genesis->previous_hash);
  generate_random(genesis);
  hash_block(genesis);

  copy_hash(blocks[1].previous_hash, genesis->current_hash);
  generate_random(&blocks[1]);
  hash_block(&blocks[1]);

  copy_hash(blocks[2].previous_hash, blocks[1].previous_hash);
  generate_random(&blocks[2]);
  hash_block(&blocks[2]);

  print_block(&blocks[2]);

  // alter genesis block

  reset_hash(genesis->previous_hash);
  generate_random(genesis);
  genesis->transactions[0].amount = 1;
  hash_block(genesis);

  copy_hash(blocks[1].previous_hash, genesis->current_hash);
  generate_random(&blocks[1]);
  hash_block(&blocks[1]);

  copy_hash(blocks[2].previous_hash, blocks[1].previous_hash);
  generate_random(&blocks[2]);
  hash_block(&blocks[2]);

  print_block(&blocks[2]);
}