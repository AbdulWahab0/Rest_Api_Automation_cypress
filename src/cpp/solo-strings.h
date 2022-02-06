/*****************************************************************************/
/*! \file solo-strings.h
 *
 * copyright SumUp Services
 *
 * \addtogroup SOLO_STRINGS
 */
/*****************************************************************************/

/*!
 * \defgroup SOLO_STRINGS Amount Strings for SOLO
 *
 * APIs and defines for amount strings in the Solo project
 */

/*!
 * \ingroup SOLO_STRINGS
 * \defgroup SOLO_STRINGS_ERRORS SOLO Strings errors
 */

/*!
 * \ingroup SOLO_STRINGS
 * \defgroup SOLO_STRINGS_API_FUNCTIONS SOLO Strings API functions
 */

// TODO: implement a group separator as an optional addition (to future proof this)

#ifndef _SOLOSTRINGS_H_
#define _SOLOSTRINGS_H_

/* =========== INCLUDES ==================================================== */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* =========== DEFINES ===================================================== */

/*!
 * \addtogroup SOLO_STRINGS_ERRORS
 * \{
 */

/*! \brief The command executed successfully. */
#define SOLO_STRINGS_ERR_OK 0x0000

/*! \brief No data was found/populated. */
#define SOLO_STRINGS_ERR_NO_DATA 0xFF62

/*! \brief Unable to process the parameters provided. */
#define SOLO_STRINGS_ERR_BADPARAMETER 0xFFAB

/*!
 * \}
 */

/* =========== PUBLIC PROTOTYPES =========================================== */

/*!
 * \addtogroup SOLO_STRINGS_API_FUNCTIONS
 * \{
 */

/*!
 * \brief Function that converts a double to an amount string.
 *
 * Example:
 * soloStringsAmountFromDouble(15.59999, bufferString, 2, ',');
 * bufferString would then contain the string: "15,60"
 *
 * \param [in] value The value to convert to an amount string.
 * \param [out] amountStringBuffer Upon completion, this will contain the amount string.
 * \param [in] exponent The number of decimal places the amount string should have.
 * \param [in] decimalSeparator The character that will separate the whole numbers from
 * the decimal numbers.
 *
 * \return Return 0 if success, otherwise will return appropriate error code.
 */
unsigned int soloStringsAmountFromDouble(
         double value,
         char *amountStringBuffer,
         unsigned int exponent,
         char decimalSeparator
         );

/*!
 * \brief Function that converts an unformatted integer to an amount string.
 *
 * Example:
 * soloStringsAmountFromLong(1234567, bufferString, 3, '.');
 * bufferString would then contain the string: "1234.567"
 *
 * \param [in] value The value to convert to an amount string.
 * \param [out] amountStringBuffer Upon completion, this will contain the amount string.
 * \param [in] exponent The number of decimal places the amount string should have.
 * \param [in] decimalSeparator The character that will separate the whole numbers from
 * the decimal numbers.
 *
 * \return Return 0 if success, otherwise will return appropriate error code.
 */
unsigned int soloStringsAmountFromLong(
         long int value,
         char *amountStringBuffer,
         unsigned int exponent,
         char decimalSeparator
         );

/*!
 * \brief Function that converts an amount string to a double.
 *
 * Example:
 * soloStringsAmountToDouble(valueBuffer, "-987,65", 2, ',');
 * valueBuffer would then contain the double: -987.65
 *
 * \param [out] valueBuffer Upon completion, this will contain the amount as a double.
 * \param [in] amountString The string to convert to a double.
 * \param [in] exponent The number of decimal places the amount string has.
 * \param [in] decimalSeparator The character that separates the whole numbers from
 * the decimal numbers.
 *
 * \return Return 0 if success, otherwise will return appropriate error code.
 */
unsigned int soloStringsAmountToDouble(
         double *valueBuffer,
         char *amountString,
         char decimalSeparator
         );

#if defined(__cplusplus)
}
#endif
#endif
