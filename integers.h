#ifndef _INTEGERS_H
  #define _INTEGERS_H
/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
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
/* Function to sum the first n integers                                 */
/*                                                                      */ 

  unsigned uintSumFirstNIntegers(int n);

/*                                                                      */
/* Function to get if a interger is a prime number of not.              */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BAI_TRUE  -> Prime number                                       */
/*      BIA_FALSE -> Not a prime number                                 */
/*                                                                      */

  int isPrime(int intN);

/*                                                                      */
/* Function to get the first intNumber prime numbers                    */
/*                                                                      */
/* Prime numbers are stored in ptPrimes and in ptCalc the total amount  */
/* of primer numbers that was computed.                                 */
/*                                                                      */

  void getFirstNPrimes(unsigned int *ptPrimes, int intNumber, int *ptCalc);                                                                                                                                     
/*                                                                      */
/* Function to get a number factorial                                   */
/*                                                                      */
/*                                                                      */

  unsigned long int uliFactorial(int intN);


#endif
