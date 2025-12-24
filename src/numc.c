#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numc.h"

typedef enum {
    NC_DTYPE_F64,
    NC_DTYPE_F32,
    NC_DTYPE_I32,
} nc_dtype;

/* Internal representation */
struct ncarr {
    void        *data;
    nc_dtype     dtype;
    size_t       itemsize;

    size_t       ndim;
    size_t      *shape;
    size_t      *strides;   /* in elements, not bytes */

    size_t       size;      /* total elements */
    void        *base;      /* owner/base object for views (NULL if owns data)
                             * Views: keep `base` pointing to 
                             * the owning allocation (or an
                             * owning object) so slices/transposes
                             * don't free the underlying 
                             * buffer prematurely
                             */
    size_t       refcount;
};

ncarr_t* new_vec() {
    ncarr_t *v = malloc(sizeof(ncarr_t));
    if (v == NULL) {
        return NULL;
    }

    return v;
}

