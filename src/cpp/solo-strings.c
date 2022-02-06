#include "solo-strings.h"

// TODO: real error checking

/* =========== PRIVATE PROTOTYPES ========================================== */

unsigned int soloStringsStrncpy(
            char *destinationString,
            char *sourceString,
            size_t destinationMaxLength
            );

/* =========== PUBLIC FUNCTIONS ============================================ */

unsigned int soloStringsAmountFromLong(
            long int value,
            char *amountStringBuffer,
            unsigned int exponent,
            char decimalSeparator
)
{
    if(exponent > 0)
    {
        double asDouble = value / pow(10, exponent);
        soloStringsAmountFromDouble(asDouble, amountStringBuffer, exponent,
                                    decimalSeparator);
    }
    else
    {
        sprintf(amountStringBuffer, "%ld", value);
    }

    return SOLO_STRINGS_ERR_OK;
}

unsigned int soloStringsAmountFromDouble(
            double value,
            char *amountStringBuffer,
            unsigned int exponent,
            char decimalSeparator
)
{
    if(exponent > 0)
    {
        double decimalPlaceMoveValue = pow(10, exponent);
        double roundedValue = round(value * decimalPlaceMoveValue) / decimalPlaceMoveValue;
        unsigned int isNegative = roundedValue < 0;

        char tempStr[13];
        char sprintfArguments[7];
        sprintf(sprintfArguments, "%%.%df", exponent);
        sprintf(tempStr, sprintfArguments, fabs(value));

        // the strtok function breaks a string into a series of substrings using a delimiter
        char *beforeDecimal = strtok(tempStr, ".");
        char *afterDecimal = strtok(NULL, ".");

        if(isNegative)
        {
            sprintf(amountStringBuffer, "-%s%c%s", beforeDecimal, decimalSeparator, afterDecimal);
        }
        else
        {
            sprintf(amountStringBuffer, "%s%c%s", beforeDecimal, decimalSeparator, afterDecimal);
        }
    }
    else
    {
        sprintf(amountStringBuffer, "%ld", (long int)(round(value)));
    }

    return SOLO_STRINGS_ERR_OK;
}

unsigned int soloStringsAmountToDouble(
            double *valueBuffer,
            char *amountString,
            char decimalSeparator
)
{
    char *fromDecimal = strchr(amountString, decimalSeparator);

    if(fromDecimal != NULL)
    {
        unsigned int index = fromDecimal - amountString;
        amountString[index] = '.';
    }
    *valueBuffer = atof(amountString);

    return SOLO_STRINGS_ERR_OK;
}

/* =========== PRIVATE FUNCTIONS =========================================== */

unsigned int soloStringsStrncpy(
            char *destinationString,
            char *sourceString,
            size_t destinationMaxLength
)
{
    size_t sourceLength = strlen(sourceString) + 1;

    if(destinationMaxLength < sourceLength)
    {
        printf("Error copying string: the destination string's max length is "
               "%lu / the source string length is %lu\n",
               destinationMaxLength, sourceLength);

        return SOLO_STRINGS_ERR_BADPARAMETER;
    }

    strncpy(destinationString, sourceString, sourceLength);
    destinationString[sourceLength] = '\0';

    if(destinationString != NULL)
    {
        return SOLO_STRINGS_ERR_OK;
    }
    return SOLO_STRINGS_ERR_NO_DATA;
}