#ifndef OUTPUT_H
#define OUTPUT_H


#include "espa_metadata.h"


/* Structure for the 'output' data type */
typedef struct
{
    bool open;            /* Flag to indicate whether output file is open
                             for access; 'true' = open, 'false' = not open */
    Img_coord_int_t size; /* Output image size */
    int nband;            /* Number of output image bands */
    Espa_internal_meta_t metadata; /* metadata container to hold the band
                                      metadata for the output band; global
                                      metadata won't be valid */
    FILE *fp_bin;         /* File pointer for binary output file */
} Output_t;


/* Prototypes */
Output_t *OpenOutputCFmask
(
    Espa_internal_meta_t *in_meta,
    Input_t *input,
    float clear_percent,
    float cloud_percent,
    float cloud_shadow_percent,
    float water_percent,
    float snow_percent
);

Output_t *OpenOutputConfidence(Espa_internal_meta_t *in_meta, Input_t *input);

bool PutOutput(Output_t *output, unsigned char *final_mask);

bool CloseOutput(Output_t *output);

bool FreeOutput(Output_t *output);


#endif
