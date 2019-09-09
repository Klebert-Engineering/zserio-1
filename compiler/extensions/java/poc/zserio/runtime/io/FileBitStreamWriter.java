package zserio.runtime.io;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

/**
 * A bit stream writer using file.
 */
public class FileBitStreamWriter extends ByteArrayBitStreamWriter
{
    /**
     * Creates a new file bit stream writer for the given file name.
     *
     * @param filename File to create bit stream writer from.
     */
    public FileBitStreamWriter(final String filename)
    {
        this(new File(filename));
    }

    /**
     * Creates a new file bit stream writer for the given file.
     *
     * @param file File to create bit stream writer from.
     */
    public FileBitStreamWriter(final File file)
    {
        this.file = file;
    }

    @Override
    public void close() throws IOException
    {
        final byte[] bytes = toByteArray();
        final OutputStream os = new FileOutputStream(file);

        try
        {
            os.write(bytes, 0, bytes.length);
            os.flush();
        }
        finally
        {
            os.close();
        }
    }

    /**
     * The file for the bit stream writer.
     */
    private final File file;
}
