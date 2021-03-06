/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

#ifdef FLA_ENABLE_NON_CRITICAL_CODE

FLA_Error FLA_Syr2k_ln_unb_var9( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, FLA_Obj beta, FLA_Obj C )
{
  FLA_Obj AL,    AR,       A0,  a1t,  A2;

  FLA_Obj BL,    BR,       B0,  b1t,  B2;

  FLA_Scalr_external( FLA_LOWER_TRIANGULAR, beta, C );

  FLA_Part_1x2( A,    &AL,  &AR,      0, FLA_LEFT );

  FLA_Part_1x2( B,    &BL,  &BR,      0, FLA_LEFT );

  while ( FLA_Obj_width( AL ) < FLA_Obj_width( A ) ){


    FLA_Repart_1x2_to_1x3( AL,  /**/ AR,        &A0, /**/ &a1t, &A2,
                           1, FLA_RIGHT );

    FLA_Repart_1x2_to_1x3( BL,  /**/ BR,        &B0, /**/ &b1t, &B2,
                           1, FLA_RIGHT );

    /*------------------------------------------------------------*/

    /* C = C + a1t * b1t' + b1t * a1t' */
    FLA_Syr2_external( FLA_LOWER_TRIANGULAR, alpha, a1t, b1t, C );

    /*------------------------------------------------------------*/

    FLA_Cont_with_1x3_to_1x2( &AL,  /**/ &AR,        A0, a1t, /**/ A2,
                              FLA_LEFT );

    FLA_Cont_with_1x3_to_1x2( &BL,  /**/ &BR,        B0, b1t, /**/ B2,
                              FLA_LEFT );

  }

  return FLA_SUCCESS;
}

#endif
