package zserio.extension.common;

/**
 * Converts escape sequences in strings.
 *
 * This is currently used for C++ extension (converts problematic unicode escape sequences to hexadecimal) and
 * for Java extension (converts not supported hexadecimal sequences to unicode).
 */
public final class StringEscapeConverter
{
    /**
     * Converts unicode escape sequences to hexadecimal in given string.
     *
     * Only unicode escape sequences from interval &lt;'\u0000', '\u00FF'&gt; are converted.
     *
     * @param stringToConvert String for escape sequences conversion.
     *
     * @return String with converted escape sequences.
     */
    public static String convertUnicodeToHexEscapes(String stringToConvert)
    {
        final StringBuilder buffer = new StringBuilder();
        final int endIndex = stringToConvert.length();
        int index = 0;
        while (index < endIndex)
        {
            final char character = stringToConvert.charAt(index);
            int newIndex = index + 1;
            buffer.append(character);
            if (character == STRING_ESCAPE_CHARACTER && newIndex + ESCAPE_UNICODE_LENGTH < endIndex)
            {
                final char escapeSpecifier = stringToConvert.charAt(newIndex);
                if (escapeSpecifier == STRING_ESCAPE_CHARACTER)
                {
                    buffer.append(STRING_ESCAPE_CHARACTER);
                    newIndex++;
                }
                else if (escapeSpecifier == ESCAPE_UNICODE_SPECIFIER)
                {
                    final char firstUnicodeChar = stringToConvert.charAt(newIndex + 1);
                    final char secondUnicodeChar = stringToConvert.charAt(newIndex + 2);
                    if (firstUnicodeChar == '0' && secondUnicodeChar == '0')
                    {
                        final char thirdUnicodeChar = stringToConvert.charAt(newIndex + 3);
                        final char fourthUnicodeChar = stringToConvert.charAt(newIndex + 4);
                        buffer.append(ESCAPE_HEXADECIMAL_SPECIFIER);
                        buffer.append(thirdUnicodeChar);
                        buffer.append(fourthUnicodeChar);
                        newIndex += ESCAPE_UNICODE_LENGTH;
                    }
                }
            }

            index = newIndex;
        }

        return buffer.toString();
    }

    /**
     * Converts hexadecimal escape sequences to unicode in given string.
     *
     * @param stringToConvert String for escape sequences conversion.
     *
     * @return String with converted escape sequences.
     */
    public static String convertHexToUnicodeToEscapes(String stringToConvert)
    {
        final StringBuilder buffer = new StringBuilder();
        final int endIndex = stringToConvert.length();
        int index = 0;
        while (index < endIndex)
        {
            final char character = stringToConvert.charAt(index);
            int newIndex = index + 1;
            buffer.append(character);
            if (character == STRING_ESCAPE_CHARACTER && newIndex + ESCAPE_HEXADECIMAL_LENGTH < endIndex)
            {
                final char escapeSpecifier = stringToConvert.charAt(newIndex);
                if (escapeSpecifier == STRING_ESCAPE_CHARACTER)
                {
                    buffer.append(STRING_ESCAPE_CHARACTER);
                    newIndex++;
                }
                else if (escapeSpecifier == ESCAPE_HEXADECIMAL_SPECIFIER)
                {
                    final char firstHexChar = stringToConvert.charAt(newIndex + 1);
                    final char secondHexChar = stringToConvert.charAt(newIndex + 2);
                    buffer.append(ESCAPE_UNICODE_SPECIFIER);
                    buffer.append("00");
                    buffer.append(firstHexChar);
                    buffer.append(secondHexChar);
                    newIndex += ESCAPE_HEXADECIMAL_LENGTH;
                }
            }

            index = newIndex;
        }

        return buffer.toString();
    }

    /**
     * Converts Zserio octal escape sequences to portable octal escapes in given string.
     *
     * Zserio octal escapes have the form '\0' followed by one to three octal digits (e.g. "\0156"). This
     * form is not a valid escape sequence in C++, Java or Python, which expect '\ooo' (one to three octal
     * digits without the leading '0' marker). This method rewrites the Zserio escapes to the canonical
     * three-digit '\ooo' form which is parsed identically in all target languages and, being always three
     * digits, cannot accidentally absorb a following octal digit from the string.
     *
     * @param stringToConvert String for escape sequences conversion.
     *
     * @return String with converted escape sequences.
     */
    public static String convertOctalEscapes(String stringToConvert)
    {
        final StringBuilder buffer = new StringBuilder();
        final int endIndex = stringToConvert.length();
        int index = 0;
        while (index < endIndex)
        {
            final char character = stringToConvert.charAt(index);
            int newIndex = index + 1;
            buffer.append(character);
            if (character == STRING_ESCAPE_CHARACTER && newIndex < endIndex)
            {
                final char escapeSpecifier = stringToConvert.charAt(newIndex);
                if (escapeSpecifier == STRING_ESCAPE_CHARACTER)
                {
                    // escaped backslash, keep it so that e.g. "\\0156" is not treated as an octal escape
                    buffer.append(escapeSpecifier);
                    newIndex++;
                }
                else if (escapeSpecifier == ESCAPE_OCTAL_MARKER)
                {
                    // Zserio octal escape '\0' + up to three octal digits (the escaped byte value is at
                    // most 255, mirroring the maximal munch done by the lexer)
                    newIndex++; // skip the '0' marker
                    int octalValue = 0;
                    int octalDigits = 0;
                    while (octalDigits < ESCAPE_OCTAL_MAX_DIGITS && newIndex < endIndex)
                    {
                        final int digit = stringToConvert.charAt(newIndex) - '0';
                        if (digit < 0 || digit > ESCAPE_OCTAL_MAX_DIGIT)
                            break;
                        final int nextValue = octalValue * ESCAPE_OCTAL_BASE + digit;
                        if (nextValue > MAX_BYTE_VALUE)
                            break;
                        octalValue = nextValue;
                        octalDigits++;
                        newIndex++;
                    }
                    // emit exactly three octal digits so that the escape is self-delimiting
                    buffer.append((char)('0' + ((octalValue >> 6) & ESCAPE_OCTAL_MAX_DIGIT)));
                    buffer.append((char)('0' + ((octalValue >> 3) & ESCAPE_OCTAL_MAX_DIGIT)));
                    buffer.append((char)('0' + (octalValue & ESCAPE_OCTAL_MAX_DIGIT)));
                }
            }

            index = newIndex;
        }

        return buffer.toString();
    }

    private static final char STRING_ESCAPE_CHARACTER = '\\';
    private static final char ESCAPE_HEXADECIMAL_SPECIFIER = 'x';
    private static final char ESCAPE_UNICODE_SPECIFIER = 'u';
    private static final char ESCAPE_OCTAL_MARKER = '0';

    private static final int ESCAPE_HEXADECIMAL_LENGTH = 3;
    private static final int ESCAPE_UNICODE_LENGTH = 5;

    private static final int ESCAPE_OCTAL_BASE = 8;
    private static final int ESCAPE_OCTAL_MAX_DIGIT = 7;
    private static final int ESCAPE_OCTAL_MAX_DIGITS = 3;
    private static final int MAX_BYTE_VALUE = 255;
}
