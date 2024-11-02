#ifndef tp11_8_h
#define tp11_8_h

typedef char * elemType;
typedef struct setCDT *setADT;
typedef int (*cmp) (elemType, elemType);

setADT newSet(cmp);
int addElement(setADT, elemType);
int deleteElement(setADT, elemType);
int setContains(setADT, elemType);
int isEmptySet(setADT);
int sizeSet(setADT);
setADT unionSet(setADT, setADT);
setADT intersectionSet(setADT, setADT);
setADT diffSet(setADT, setADT);
void freeSet(setADT);

#endif