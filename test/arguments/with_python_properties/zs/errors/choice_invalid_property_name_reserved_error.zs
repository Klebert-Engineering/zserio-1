package errors.choice_invalid_property_name_reserved_error;

choice TestChoice(uint32 param) on param
{
    case 0:
        uint32 __str__; // starts with '_'
    default:
        ;
};