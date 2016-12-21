#include <stdlib.h>
#include <limits.h>
#include <omp.h>
#include <gmp.h>
#include <string.h>

#include <biagra/numintegr.h>
#include <biagra/const.h>
#include <biagra/pi.h>

#include <stdio.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*
   The following are deliberately forbidden:
     - Attempt World domination
     - Using this software as compiling massive weapon
     - Translating into Klingon
     - Ask for /home nationalisms
     - Reverse spelling of this source code
*/

/*                                                                      */
/* This function is used to compute pi used the midpoint rule.          */
/*                                                                      */

long double pifunc(double x) {
  return (1./(1. + (x*x)));
}

/*                                                                      */
/* Function to get a pi approximation using the mid-point rule.         */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads -> Number of threads to be used                        */
/*    intN       -> Number of used subintervals                         */                                                                          
/*                                                                      */
/* Pi approximation is returned as long double.                         */
/*                                                                      */

long double threadedPiMidPointRule(int intThreads, int intN) {

  long double pifunc(double x);
  
  long double pi;

  pi = threadedMidPointRule(intThreads, intN, .0, 1., &pifunc);

  return pi;
}

/*                                                                      */
/* Function to get a pi approximation using the Chudnovsky algorithm.   */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads  -> Number of threads to be used                       */
/*    intPiDigits -> Number of pi digits to be computed                 */
/*    ptPi        -> Char pointer to store pi                           */
/*                                                                      */

int chudnovskyPi(int intThreads, int intPiDigits, char *ptPi) {

  /* bits per decimal digit, log2(10) */
  double bits_digit = 3.3219280948873626; 
	    
  unsigned long int i              = 0,
                    iters          = 0,
                    triplei        = 0,
                    precision_bits = (intPiDigits * bits_digit) + 1;

  char *pistr;        /* to store pi as a string as computed */

  mpf_t pi,  /* pi aproximation */
        num; /* numerator */

  mpf_set_default_prec(precision_bits); /* default precision in bits */

  /* allocation and initialitation, mpf_inits does not work on RHEL 6.x due to gmp version */
  mpf_init(pi);
  mpf_init(num);

  /* pi */
  mpf_set_ui(pi, 0);

  /* numerator */
  mpf_sqrt_ui(num, 10005);
  mpf_mul_ui(num, num, 426880);

  iters = (intPiDigits/DIGITS_ITERATION) + 1;

  #pragma omp parallel num_threads(intThreads) private(triplei, i) shared(pi, num)
  { /* begin - pragma parallel */
     /* integer gmp variables */
     mpz_t f6i,     /* (6*i)! */
           f3i,     /* /3*i)! */
           fi3,     /* (i!)^3 */
           sumnumi, /* (13591409 + 545140134 * i) */
           sumdeni; /* (-640320)^(3*k) */
   
     /* double gmp variables */
     mpf_t sumnum,
           sumden,
           sumterm,
           sumterm_tmp,
           numi;
   
     mp_exp_t exp;
   
     /* allocation and initialitation, mpf_inits does not work on RHEL 6.x due to gmp version */
     mpz_init(f6i);
     mpz_init(f3i);
     mpz_init(fi3);
     mpz_init(sumnumi);
     mpz_init(sumdeni);
     mpf_init(sumnum);
     mpf_init(sumden);
     mpf_init(sumterm);
     mpf_init(sumterm_tmp);
     mpf_init(numi);
       
     mpf_set_ui(sumterm, 0);
   
    #pragma omp for ordered
    for(i=0;i<iters;i++) { /* begin for - i */
      triplei = 3*i;
      mpz_fac_ui(f6i, 6*i);       /* (6*i)! */
      mpz_fac_ui(f3i, triplei);   /* /3*i)! */
      mpz_fac_ui(fi3, i);         /* i! */
      mpz_pow_ui(fi3, fi3, 3);    /* (i!)^3 */
      
      /* 13591409 + 545140134 * i */
      mpz_set_ui(sumnumi, 545140134);
      mpz_mul_ui(sumnumi, sumnumi, i);
      mpz_add_ui(sumnumi, sumnumi, 13591409);
     
      /* (-640320)^(3*i) */
      mpz_ui_pow_ui(sumdeni, 640320, triplei);
      
      if ( (triplei&1) == 1  ) {
        mpz_neg(sumdeni, sumdeni);
      }

      /* sumnumi */
      mpz_mul(sumnumi, sumnumi, f6i);

      /* sumdeni */
      mpz_mul(sumdeni, sumdeni, fi3);
      mpz_mul(sumdeni, sumdeni, f3i);

      /* sumterm */
      mpf_set_z(sumnum, sumnumi);
      mpf_set_z(sumden, sumdeni);

      mpf_div(sumterm_tmp, sumnum, sumden);
      mpf_add(sumterm, sumterm, sumterm_tmp);

    } /* end for - i */

    #pragma omp critical
    {
      mpf_add(pi, pi, sumterm);
    }
    #pragma omp barrier
    #pragma omp single
    {
      /* final calcs */
      mpf_ui_div(pi, 1, pi);
      mpf_mul(pi, pi, num);
   
      /* converting pi to string */
      pistr = (char *)mpf_get_str(NULL, &exp, 10, intPiDigits, pi);
   
    }
    # pragma omp barrier
    /* freeing gmp variables, mpf_clears does not work on RHEL 6.x due to gmp version */
    mpz_clear(f6i);
    mpz_clear(f3i);
    mpz_clear(fi3);
    mpz_clear(sumnumi);
    mpz_clear(sumdeni);
    mpf_clear(sumnum);
    mpf_clear(sumden);
    mpf_clear(sumterm);
    mpf_clear(sumterm_tmp);
    mpf_clear(numi);
  } /* end - pragma parallel */

  /* freeing gmp variables, mpf_clears does not work on RHEL 6.x due to gmp version */
  mpf_clear(pi);
  mpf_clear(num);

  /* adding decimal dot */
  strncpy(ptPi, pistr, 1);
  ptPi[1] = '.';
  strcpy(ptPi + 2, pistr +1);

  return BIA_TRUE;
}
