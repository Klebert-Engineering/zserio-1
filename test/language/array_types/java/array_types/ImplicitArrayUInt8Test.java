package array_types;

import static org.junit.Assert.*;

import java.io.IOException;
import java.io.File;

import org.junit.Test;

import array_types.implicit_array_uint8.ImplicitArray;

import zserio.runtime.ZserioError;
import zserio.runtime.array.UnsignedByteArray;
import zserio.runtime.io.BitStreamReader;
import zserio.runtime.io.BitStreamWriter;
import zserio.runtime.io.FileBitStreamReader;
import zserio.runtime.io.FileBitStreamWriter;

public class ImplicitArrayUInt8Test
{
    @Test
    public void bitSizeOf() throws IOException, ZserioError
    {
        final int numElements = 44;
        UnsignedByteArray array = new UnsignedByteArray(numElements);
        for (short i = 0; i < numElements; ++i)
            array.setElementAt(i, i);

        final ImplicitArray implicitArray = new ImplicitArray(array);
        final int bitPosition = 2;
        final int implicitArrayBitSize = numElements * 8;
        assertEquals(implicitArrayBitSize, implicitArray.bitSizeOf(bitPosition));
    }

    @Test
    public void initializeOffsets() throws IOException, ZserioError
    {
        final int numElements = 66;
        UnsignedByteArray array = new UnsignedByteArray(numElements);
        for (short i = 0; i < numElements; ++i)
            array.setElementAt(i, i);

        final ImplicitArray implicitArray = new ImplicitArray(array);
        final int bitPosition = 2;
        final int expectedEndBitPosition = bitPosition + numElements * 8;
        assertEquals(expectedEndBitPosition, implicitArray.initializeOffsets(bitPosition));
    }

    @Test
    public void read() throws IOException, ZserioError
    {
        final File file = new File("test.bin");
        final int numElements = 99;
        writeImplicitArrayToFile(file, numElements);
        final BitStreamReader stream = new FileBitStreamReader(file);
        final ImplicitArray implicitArray = new ImplicitArray(stream);
        stream.close();

        final UnsignedByteArray array = implicitArray.getArray();
        assertEquals(numElements, array.length());
        for (short i = 0; i < numElements; ++i)
            assertEquals(i, array.elementAt(i));
    }

    @Test
    public void write() throws IOException, ZserioError
    {
        final int numElements = 55;
        UnsignedByteArray array = new UnsignedByteArray(numElements);
        for (short i = 0; i < numElements; ++i)
            array.setElementAt(i, i);

        ImplicitArray implicitArray = new ImplicitArray(array);
        final File file = new File("test.bin");
        final BitStreamWriter writer = new FileBitStreamWriter(file);
        implicitArray.write(writer);
        writer.close();

        final ImplicitArray readImplicitArray = new ImplicitArray(file);
        final UnsignedByteArray readArray = readImplicitArray.getArray();
        assertEquals(numElements, readArray.length());
        for (short i = 0; i < numElements; ++i)
            assertEquals(i, readArray.elementAt(i));
    }

    private void writeImplicitArrayToFile(File file, int numElements) throws IOException
    {
        final FileBitStreamWriter writer = new FileBitStreamWriter(file);

        for (short i = 0; i < numElements; ++i)
            writer.writeUnsignedByte(i);

        writer.close();
    }
}
