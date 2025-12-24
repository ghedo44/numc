#ifndef NUMC_H
#define NUMC_H

#include <stddef.h>  // size_t

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque ND array type */
typedef struct ncarr ncarr_t;

ncarr_t* new_vec(); 

#ifdef __cplusplus
}
#endif

#endif /* NUMC_H */
