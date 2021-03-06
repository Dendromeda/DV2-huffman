/*
 * Copyright 2015 Johan Eliasson (johane@cs.umu.se). Tillåtelse ges för 
 * användning på kurserna i Datastrukturer och algoritmer vid Umeå Universitet 
 * (inklusive DV1 och DV2). All annan användning kräver författarens tillstånd.
 *
 * Copyright 2016 Johan Eliasson (johane@cs.umu.se). Permission is given for 
 * usage of this file wihtin the courses Datastrukturer och algoritmer, DV1 and 
 * DV2 at Umeå University. All other usage requires the authors permission.
 * 
 *
 * Changelog
 * 2017-01-20 Updated comments, Joanthan Westin
 * 2017-02-10 Setting value to zero on new realloc'ed bytes in bitset-array, 
 *            Jonathan Westin
 *
 */

/* The datatype saves binary values within a bitset. The bitset is stored
 * using character-datatype.
 *
 * No mathematical sum-operations exist in the datatypes. 
 * Some extra operations has been added to the datatype for easier usage. 
 *
 */
#include "bitset.h"
#include <stdlib.h>


/* Creates a new empty bitset of length 0.
 * 
 * @return  New empty allocated bitset datatype.
 */
bitset *bitset_empty() {
    bitset *b;
    b=malloc(sizeof(bitset));
    b->length=0;
    b->capacity=0;
    b->array=NULL;
    return b;
}


/* Sets the given value of the bitnumber on the bitset.
 * Set bit bitno to value (true=1, false=0) in the bitset b. bitNo should be 
 * >= 0. If bitNo >= bitset_size(b) the bitset will be extended up to that bit. 
 * If the bitset is to be extended, the new bits of the bitset to bitNo will be
 * set to zero/false.
 *
 * @param b         The bitset.
 * @param bitNo     The bit index within the bitset to be set.
 * @param values    The boolean value to be set.
 */
void bitset_setBitValue(bitset *b,int bitNo,bool value) {
    if(bitNo>=bitset_size(b)) {
        b->length=bitNo+1;
        while(b->capacity < b->length) {
            b->array=realloc(b->array,(b->capacity/8+1));
            b->capacity+=8;
            b->array[(b->capacity/8)-1]=0;
        }
    }
    int byteNo=bitNo/8;
    int bit=bitNo%8;
    char theByte=b->array[byteNo];
    if(value) {
        theByte = (theByte | 1 << bit);
    }
    else {
        theByte = theByte & ~(1<<bit);
    }
    b->array[byteNo] = theByte;
}


/* Gives the size of the bitset (bits)).
 * 
 * @return the size of the bitset.
 */
int bitset_size(bitset *b) {
    return b->length;
}


/* Returns the value of the given bitNo within the bitset. 
 * If the given bitNo is not a member of the bitset (bitNo >= bitset_size(b))
 * the behaviour is undefined.
 *
 * @param b         The bitset
 * @param bitNo     The bit number to check. 
 * @return          The value of the bit (bitNo) the bitset.
 */
bool bitset_memberOf(bitset *b,int bitNo) {
    int byteNo=bitNo/8;
    int bit=bitNo%8;
    char theByte=b->array[byteNo];
    return ((theByte)&(1<<bit)) > 0;
}


/* Converts the bitset to an array of bytes. The array will contain all bits 
 * existing within the array. If the bitset_size is not a multiple of 8 bits,
 * the last byte of the array will be padded with bits of value 0. 
 * Memory is allocated for the array. The user is responsible for deallocating
 * the returned array.
 * 
 * @param b     The bitset that will be read.
 * @return      The byte(char)-array of the bitset.
 */
char *bitset_toByteArray(bitset *b) {
    char *res=calloc(b->capacity/8, sizeof(char));
    for (int i=0; i<b->capacity/8; i++) {
        res[i]=b->array[i];
    }
    return res;
    
}




/* Deallocates all memory used by the given bitset.
 *
 * @param b The bitset to be freed.
 */
void bitset_free(bitset *b){
    free(b->array);
    free(b);
}

