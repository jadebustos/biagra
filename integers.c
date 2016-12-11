#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Function to sum the first n integers                                 */
/*                                                                      */ 
/* The forllowing codes are returned:                                   */
/*                                                                      */
/*      0 If sum is bigger than unsigned int maximum value              */
/*                                                                      */
/*      Sum of the first n integers                                     */
/*                                                                      */ 

unsigned uintSumFirstNIntegers(int n) {
	
  double dblHalf = .0,
	 dblSum  = .0;

  int intNum = abs(n);

  unsigned intSum = 0;

  if ( (intNum % 2) == 0 ) {
    dblHalf = ((double)intNum)/2.;
    dblSum  = dblHalf*(1.+(double)intNum);
  }
  else {
    dblHalf = (((double)intNum)-1.)/2.;
    dblSum  = (dblHalf)*(2.+((double)intNum))+1.;
  }

  intSum = (unsigned)dblSum;

  if ( dblHalf > intSum )
    intSum = 0;
		
  return (intSum);
}

/*                                                                      */
/* Function to get if a interger is a prime number of not.              */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BAI_TRUE  -> Prime number                                       */
/*      BIA_FALSE -> Not a prime number                                 */
/*                                                                      */

int isPrime(int intN) {

  int i,
      intRes  = BIA_TRUE,
      intAbsN = abs(intN),
      intBoundary = (int)floor(sqrt(intAbsN));

  for(i=2;i<=intBoundary;i++) {
    if ( (intAbsN % i) == 0  ) {
      intRes = BIA_FALSE;
      break;
    }
  }
  return intRes;
}

/*                                                                      */
/* Function to get the first intNumber prime numbers                    */
/*                                                                      */
/* Prime numbers are stored in ptPrimes and in ptCalc the total amount  */
/* of primer numbers that was computed.                                 */
/*                                                                      */

void getFirstNPrimes(unsigned int *ptPrimes, int intNumber, int *ptCalc) {

  unsigned int i,
               uintRemainder;

  int  intCalc = 0, /* number of primes that were calculed */
       intNumAbs = abs(intNumber),
       j;

  if ( intNumAbs != 0  )
    ptPrimes[intCalc++] = 2;

  for(i=3;(i<UINT_MAX-1) && (intCalc<intNumAbs);i+=2) {
    for(j=1;j<intCalc;j++) {
      uintRemainder = i % ptPrimes[j];
      if ( uintRemainder == 0  )
        break;
    }
  if ( uintRemainder != 0  )
    ptPrimes[intCalc++] = i;
  }
  *ptCalc = intCalc;
  return;
} 
