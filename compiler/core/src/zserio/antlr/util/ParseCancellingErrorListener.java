package zserio.antlr.util;

import org.antlr.v4.runtime.BaseErrorListener;
import org.antlr.v4.runtime.InputMismatchException;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Recognizer;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.misc.ParseCancellationException;

import zserio.antlr.ZserioParser;
import zserio.ast.AstLocation;

/**
 * ANTLR4 error listener implementation which terminates parsing in case of an error.
 */
public class ParseCancellingErrorListener extends BaseErrorListener
{
    /**
     * Empty constructor, expects that the input is parsed from a file.
     */
    public ParseCancellingErrorListener()
    {
        this(null, 0, 0);
    }

    /**
     * Constructor from ANTLR4 token, expects that the input is parsed from a token
     * (e.g. documentation comment).
     *
     * @param token Token which text content is being parsed.
     */
    public ParseCancellingErrorListener(Token token)
    {
        this(token.getInputStream().getSourceName(), token.getLine(), token.getCharPositionInLine());
    }

    @Override
    public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol,
            int line, int charPositionInLine, String msg,
            RecognitionException e) throws ParseCancellationException
    {
        if (sourceName != null)
        {
            throw new ParserException(new AstLocation(this.sourceName,
                    this.line + line - 1, // lines are numbered from 1
                    (line == 1 ? this.charPositionInLine + charPositionInLine : charPositionInLine)), msg);
        }
        else
        {
            if (e instanceof InputMismatchException && isKeyword(e.getOffendingToken()))
            {
                final String message = msg + " ('" + e.getOffendingToken().getText() +
                        "' is a reserved keyword)!";
                throw new ParserException(new AstLocation(recognizer.getInputStream().getSourceName(), line,
                        charPositionInLine), message);
            }
            else
            {
                throw new ParserException(new AstLocation(recognizer.getInputStream().getSourceName(), line,
                        charPositionInLine), msg);
            }
        }
    }

    private boolean isKeyword(Token token)
    {
        if (token == null)
            return false;

        // according to keywords defined in ZserioLexer.g4
        if (token.getType() >= ZserioParser.ALIGN && token.getType() <= ZserioParser.VARUINT64)
            return true;

        return false;
    }

    private ParseCancellingErrorListener(String sourceName, int line, int charPositionInLine)
    {
        this.sourceName = sourceName;
        this.line = line;
        this.charPositionInLine = charPositionInLine;
    }

    final private String sourceName;
    final private int line;
    final private int charPositionInLine;
}
