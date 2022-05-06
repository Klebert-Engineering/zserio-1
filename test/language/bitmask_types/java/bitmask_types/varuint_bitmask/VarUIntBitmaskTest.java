package bitmask_types.varuint_bitmask;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.io.File;
import java.math.BigInteger;

import zserio.runtime.io.BitStreamReader;
import zserio.runtime.io.ByteArrayBitStreamReader;
import zserio.runtime.io.ByteArrayBitStreamWriter;
import zserio.runtime.io.FileBitStreamReader;
import zserio.runtime.io.FileBitStreamWriter;
import zserio.runtime.BitSizeOfCalculator;

public class VarUIntBitmaskTest
{
    @Test
    public void emptyConstructor()
    {
        final Permission permission = new Permission();
        assertEquals(BigInteger.ZERO, permission.getValue());
    }

    @Test
    public void valueConstructor()
    {
        final Permission permission = new Permission(WRITE_VALUE);
        assertTrue(permission.and(Permission.Values.WRITE).equals(Permission.Values.WRITE));
    }

    @Test
    public void valueConstructorUnderLowerBound()
    {
        assertThrows(IllegalArgumentException.class, () -> new Permission(BigInteger.ONE.negate()));
    }

    @Test
    public void valueConstructorAboveUpperBound()
    {
        assertThrows(IllegalArgumentException.class, () -> new Permission(BigInteger.ONE.shiftLeft(64)));
    }

    @Test
    public void readConstructor() throws IOException
    {
        final ByteArrayBitStreamWriter writer = new ByteArrayBitStreamWriter();
        writer.writeBigInteger(Permission.Values.WRITE.getValue(),
                BitSizeOfCalculator.getBitSizeOfVarUInt(Permission.Values.WRITE.getValue()));
        final ByteArrayBitStreamReader reader = new ByteArrayBitStreamReader(writer.toByteArray());
        final Permission readPermission = new Permission(reader);
        assertEquals(Permission.Values.WRITE, readPermission);
    }

    @Test
    public void bitSizeOf()
    {
        assertEquals(BitSizeOfCalculator.getBitSizeOfVarUInt(Permission.Values.NONE.getValue()),
                Permission.Values.NONE.bitSizeOf());
        assertEquals(BitSizeOfCalculator.getBitSizeOfVarUInt(Permission.Values.NONE.getValue()),
                Permission.Values.NONE.bitSizeOf(1));
    }

    @Test
    public void initializeOffsets()
    {
        final int bitPosition = 1;
        assertEquals(bitPosition + BitSizeOfCalculator.getBitSizeOfVarUInt(Permission.Values.READ.getValue()),
                Permission.Values.READ.initializeOffsets(bitPosition));
    }

    @Test
    public void equals()
    {
        assertTrue(Permission.Values.NONE.equals(Permission.Values.NONE));
        assertTrue(Permission.Values.READ.equals(Permission.Values.READ));
        assertTrue(Permission.Values.WRITE.equals(Permission.Values.WRITE));

        final Permission read = Permission.Values.READ;
        assertTrue(read.equals(Permission.Values.READ));
        assertTrue(Permission.Values.READ.equals(read));
        assertFalse(read.equals(Permission.Values.WRITE));
        assertFalse(Permission.Values.WRITE.equals(read));

        final Permission write = new Permission(WRITE_VALUE);
        assertTrue(write.equals(Permission.Values.WRITE));
        assertTrue(Permission.Values.WRITE.equals(write));
        assertFalse(write.equals(Permission.Values.READ));
        assertFalse(Permission.Values.READ.equals(write));

        assertTrue(read.equals(read));
        assertTrue(write.equals(write));
        assertFalse(read.equals(write));
    }

    @Test
    public void hashCodeMethod()
    {
        final Permission read = Permission.Values.READ;
        final Permission write = Permission.Values.WRITE;
        assertEquals(read.hashCode(), Permission.Values.READ.hashCode());
        assertEquals(read.hashCode(), new Permission(READ_VALUE).hashCode());
        assertEquals(write.hashCode(), Permission.Values.WRITE.hashCode());
        assertEquals(write.hashCode(), new Permission(WRITE_VALUE).hashCode());
        assertFalse(read.hashCode() == write.hashCode());
        assertFalse(read.hashCode() == Permission.Values.NONE.hashCode());
    }

    @Test
    public void toStringMethod()
    {
        assertEquals("0[NONE]", Permission.Values.NONE.toString());
        assertEquals("2[READ]", Permission.Values.READ.toString());
        assertEquals("4[WRITE]", Permission.Values.WRITE.toString());
        assertEquals("6[READ | WRITE]", Permission.Values.READ.or(Permission.Values.WRITE).toString());
        assertEquals("7[READ | WRITE]", new Permission(BigInteger.valueOf(7)).toString());
        assertEquals("255[READ | WRITE]", new Permission(BigInteger.valueOf(255)).toString());
    }

    @Test
    public void writeRead() throws IOException
    {
        final Permission permission = Permission.Values.READ;
        final ByteArrayBitStreamWriter writer = new ByteArrayBitStreamWriter();
        permission.write(writer);

        final ByteArrayBitStreamReader reader = new ByteArrayBitStreamReader(writer.toByteArray());
        final Permission readPermission = new Permission(reader);
        assertEquals(permission, readPermission);
    }

    @Test
    public void writeReadFile() throws IOException
    {
        final Permission permission = Permission.Values.READ;
        final File file = new File(BLOB_NAME);
        final FileBitStreamWriter writer = new FileBitStreamWriter(file);
        permission.write(writer);
        writer.close();

        final FileBitStreamReader reader = new FileBitStreamReader(file);
        final Permission readPermission = new Permission(reader);
        reader.close();
        assertEquals(permission, readPermission);
    }

    @Test
    public void getValue()
    {
        assertEquals(NONE_VALUE, Permission.Values.NONE.getValue());
        assertEquals(READ_VALUE, Permission.Values.READ.getValue());
        assertEquals(WRITE_VALUE, Permission.Values.WRITE.getValue());
    }

    @Test
    public void getGenericValue()
    {
        assertEquals(NONE_VALUE, Permission.Values.NONE.getGenericValue());
        assertEquals(READ_VALUE, Permission.Values.READ.getGenericValue());
        assertEquals(WRITE_VALUE, Permission.Values.WRITE.getGenericValue());
    }

    @Test
    public void or()
    {
        final Permission read = Permission.Values.READ;
        final Permission write = Permission.Values.WRITE;

        assertEquals(read.or(write), Permission.Values.READ.or(Permission.Values.WRITE));
        assertEquals(read, read.or(Permission.Values.NONE));
        assertEquals(write, Permission.Values.NONE.or(write));
        assertEquals(READ_VALUE.or(WRITE_VALUE), read.or(write).getValue());
    }

    @Test
    public void and()
    {
        final Permission read = Permission.Values.READ;
        final Permission write = Permission.Values.WRITE;
        final Permission readwrite = Permission.Values.READ.or(Permission.Values.WRITE);

        assertEquals(read, readwrite.and(read));
        assertEquals(write, readwrite.and(write));
        assertEquals(Permission.Values.NONE, readwrite.and(Permission.Values.NONE));
        assertEquals(Permission.Values.NONE, read.and(Permission.Values.NONE));
        assertEquals(Permission.Values.NONE, write.and(Permission.Values.NONE));
        assertEquals(Permission.Values.NONE, read.and(write));
        assertEquals(read, read.and(read).and(read).and(read));
    }

    @Test
    public void xor()
    {
        final Permission read = Permission.Values.READ;
        final Permission write = Permission.Values.WRITE;

        assertEquals(read.xor(write), Permission.Values.READ.xor(Permission.Values.WRITE));
        assertEquals(READ_VALUE.xor(WRITE_VALUE), read.xor(write).getValue());
        assertEquals(read, (read.xor(write)).and(read));
        assertEquals(write, (read.xor(write)).and(write));
        assertEquals(Permission.Values.NONE, read.xor(read));
        assertEquals(Permission.Values.NONE, write.xor(write));
    }

    @Test
    public void not()
    {
        final Permission none = Permission.Values.NONE;
        final Permission read = Permission.Values.READ;
        final Permission write = Permission.Values.WRITE;

        assertEquals(write, read.not().and(write));
        assertEquals(none, read.not().and(read));
        assertEquals(write, none.not().and(write));
        assertEquals(read, none.not().and(read));
        assertEquals(read.or(write), none.not().and(read.or(write)));
    }

    private static final String BLOB_NAME = "varuint_bitmask.blob";
    private static final BigInteger NONE_VALUE = BigInteger.ZERO;
    private static final BigInteger READ_VALUE = BigInteger.valueOf(2);
    private static final BigInteger WRITE_VALUE = BigInteger.valueOf(4);
}
