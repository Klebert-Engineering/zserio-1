package zserio.runtime;

import zserio.runtime.array.PackingContext;

/**
 * Interface for a size calculation for packable classes generated by Zserio.
 *
 * This interface is used only internally for generated code.
 */
public interface PackableSizeOf extends SizeOf
{
    /**
     * Initializes whole packing context subtree.
     *
     * @param context Packing context node.
     */
    public void initPackingContext(PackingContext context);

    /**
     * Gets the bit length of packed object stored in bit stream.
     *
     * @param context Packing context node.
     * @param bitPosition Current bit stream position.
     *
     * @return Length of the packed object in number of bits.
     */
    public int bitSizeOf(PackingContext context, long bitPosition);
}
