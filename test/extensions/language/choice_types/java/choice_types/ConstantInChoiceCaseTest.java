package choice_types;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import zserio.runtime.io.BitBuffer;
import zserio.runtime.io.SerializeUtil;

import choice_types.constant_in_choice_case.ConstantInChoiceCase;
import choice_types.constant_in_choice_case.UINT8_CONST;

public class ConstantInChoiceCaseTest
{
    @Test
    public void writeRead()
    {
        final ConstantInChoiceCase constantInChoiceCase = new ConstantInChoiceCase(UINT8_CONST.UINT8_CONST);
        constantInChoiceCase.setConstCase((short)42);

        final BitBuffer bitBuffer = SerializeUtil.serialize(constantInChoiceCase);

        final ConstantInChoiceCase readConstantInChoiceCase =
                SerializeUtil.deserialize(ConstantInChoiceCase.class, bitBuffer, UINT8_CONST.UINT8_CONST);
        assertEquals(constantInChoiceCase, readConstantInChoiceCase);
    }

    @Test
    public void writeReadValueOfCase()
    {
        // selector 1 = valueof(ValueOfEnum.ONE)
        final ConstantInChoiceCase constantInChoiceCase = new ConstantInChoiceCase((short)1);
        constantInChoiceCase.setValueOfCase((short)42);

        final BitBuffer bitBuffer = SerializeUtil.serialize(constantInChoiceCase);

        final ConstantInChoiceCase readConstantInChoiceCase =
                SerializeUtil.deserialize(ConstantInChoiceCase.class, bitBuffer, (short)1);
        assertEquals(constantInChoiceCase, readConstantInChoiceCase);
    }

    @Test
    public void writeReadValueOfConstCase()
    {
        // selector 2 = VALUEOF_CONST (defined via valueof)
        final ConstantInChoiceCase constantInChoiceCase = new ConstantInChoiceCase((short)2);
        constantInChoiceCase.setValueOfConstCase((short)42);

        final BitBuffer bitBuffer = SerializeUtil.serialize(constantInChoiceCase);

        final ConstantInChoiceCase readConstantInChoiceCase =
                SerializeUtil.deserialize(ConstantInChoiceCase.class, bitBuffer, (short)2);
        assertEquals(constantInChoiceCase, readConstantInChoiceCase);
    }
}
