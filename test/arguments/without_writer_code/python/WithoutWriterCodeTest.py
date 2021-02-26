import unittest
import apsw
import zserio

from testutils import getZserioApi

class WithoutWriterCodeTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "without_writer_code.zs", extraArgs=["-withoutWriterCode"])

    def testItemTypeMethods(self):
        userType = self.api.ItemType

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")

        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

    def testVersionAvailabilityMethods(self):
        userType = self.api.VersionAvailability

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "fromValue")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "__eq__")
        self._assertMethodPresent(userType, "__hash__")
        self._assertMethodPresent(userType, "__str__")
        self._assertMethodPresent(userType, "__or__")
        self._assertMethodPresent(userType, "__and__")
        self._assertMethodPresent(userType, "__xor__")
        self._assertMethodPresent(userType, "__invert__")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "value", readOnly=True)

    def testExtraParamUnionMethods(self):
        userType = self.api.ExtraParamUnion

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "choice_tag", readOnly=True)
        self._assertPropertyPresent(userType, "value16", readOnly=True)
        self._assertPropertyPresent(userType, "value32", readOnly=True)

    def testItemMethods(self):
        userType = self.api.Item

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")
        self._assertMethodNotPresent(userType, "fromFields")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "item_type", readOnly=True)
        self._assertPropertyPresent(userType, "param", readOnly=True)
        self._assertPropertyPresent(userType, "extra_param", readOnly=True)

    def testItemChoiceMethods(self):
        userType = self.api.ItemChoice

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "has_item", readOnly=True)
        self._assertPropertyPresent(userType, "item", readOnly=True)
        self._assertPropertyPresent(userType, "param", readOnly=True)

    def testItemChoiceHolderMethods(self):
        userType = self.api.ItemChoiceHolder

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")
        self._assertMethodNotPresent(userType, "fromFields")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "has_item", readOnly=True)
        self._assertPropertyPresent(userType, "item_choice", readOnly=True)

    def testTileMethods(self):
        userType = self.api.Tile

        self._assertMethodNotPresent(userType, "initializeOffsets")
        self._assertMethodNotPresent(userType, "write")
        self._assertMethodNotPresent(userType, "fromFields")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")
        self._assertMethodPresent(userType, "fromReader")
        self._assertMethodPresent(userType, "bitSizeOf")

        self._assertPropertyPresent(userType, "version", readOnly=True)
        self._assertPropertyPresent(userType, "num_elements_offset", readOnly=True)
        self._assertPropertyPresent(userType, "num_elements", readOnly=True)
        self._assertPropertyPresent(userType, "data", readOnly=True)

    def testGeoMapTableMethods(self):
        userType = self.api.GeoMapTable

        self._assertMethodNotPresent(userType, "createTable")
        self._assertMethodNotPresent(userType, "deleteTable")
        self._assertMethodNotPresent(userType, "write")
        self._assertMethodNotPresent(userType, "update")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "read")

    def testWorldDbMethods(self):
        userType = self.api.WorldDb

        self._assertMethodNotPresent(userType, "createSchema")
        self._assertMethodNotPresent(userType, "deleteSchema")

        self._assertMethodPresent(userType, "__init__")
        self._assertMethodPresent(userType, "fromFile")
        self._assertMethodPresent(userType, "close")

        self._assertPropertyPresent(userType, "europe", readOnly=True)
        self._assertPropertyPresent(userType, "america", readOnly=True)
        self._assertPropertyPresent(userType, "connection", readOnly=True)

        # static constants
        self.assertTrue(hasattr(userType, "DATABASE_NAME"))
        self.assertTrue(hasattr(userType, "TABLE_NAME_europe"))
        self.assertTrue(hasattr(userType, "TABLE_NAME_america"))

    def testRead(self):
        writer = zserio.BitStreamWriter()
        self._writeTile(writer)

        reader = zserio.BitStreamReader(writer.getByteArray(), writer.getBitPosition())
        tile = self.api.Tile()
        tile.read(reader)

        self._checkTile(tile)

    def testFromReader(self):
        writer = zserio.BitStreamWriter()

        self._writeTile(writer)

        reader = zserio.BitStreamReader(writer.getByteArray(), writer.getBitPosition())
        tile = self.api.Tile.fromReader(reader)

        self._checkTile(tile)

    def testReadWorldDb(self):
        connection = self._createWorldDb()

        worldDb = self.api.WorldDb(connection)

        europe = worldDb.europe
        europeRows = europe.read()
        count = 0
        for row in europeRows:
            self.assertEqual(TILE_ID_EUROPE, row[0])
            self._checkTile(row[1])
            count += 1
        self.assertEqual(1, count)

        america = worldDb.america
        americaRows = america.read()
        count = 0
        for row in americaRows:
            self.assertEqual(TILE_ID_AMERICA, row[0])
            self._checkTile(row[1])
            count += 1
        self.assertEqual(1, count)

    def _createWorldDb(self):
        connection = apsw.Connection(":memory:")
        cursor = connection.cursor()

        cursor.execute("CREATE TABLE europe(tileId INTEGER PRIMARY KEY, tile BLOB)")
        cursor.execute("CREATE TABLE america(tileId INTEGER PRIMARY KEY, tile BLOB)")

        writer = zserio.BitStreamWriter()
        self._writeTile(writer)
        blob = writer.getByteArray()

        cursor.execute("INSERT INTO europe VALUES(?, ?)", (TILE_ID_EUROPE, blob))
        cursor.execute("INSERT INTO america VALUES(?, ?)", (TILE_ID_AMERICA, blob))

        return connection

    def _writeTile(self, writer):
        # Tile
        writer.writeBits(VERSION_AVAILABILITY, 3)
        writer.writeBits(VERSION, 8)
        writer.writeBits(6, 32) # numElementsOffset
        writer.alignTo(8)
        writer.writeBits(NUM_ELEMENTS, 32)

        # offsets
        # offset of the first element
        offset = zserio.bitposition.bitsToBytes(writer.getBitPosition()) + 4 * NUM_ELEMENTS
        for i in range(NUM_ELEMENTS):
            writer.writeBits(offset, 32)
            hasItem = i % 2 == 0 # hasItem == True for even elements
            if hasItem:
                offset += 8
            else:
                offset += 3

        for i in range(NUM_ELEMENTS):
            writer.alignTo(8) # aligned because of indexed offsets
            # ItemChoiceHolder
            hasItem = i % 2 == 0 # hasItem == True for even elements
            writer.writeBool(hasItem)
            if hasItem:
                # Item
                writer.writeBits(PARAMS[i], 16)
                # ExtraParamUnion - choiceTag CHOICE_value32
                writer.writeVarSize(self.api.ExtraParamUnion.CHOICE_value32)
                writer.writeBits(EXTRA_PARAM, 32)
            else:
                writer.writeBits(PARAMS[i], 16)

    def _checkTile(self, tile):
        self.assertEqual(VERSION, tile.version)
        self.assertEqual(NUM_ELEMENTS, tile.num_elements)

        data = tile.data
        self.assertEqual(NUM_ELEMENTS, len(data))

        # element 0
        self.assertTrue(data[0].has_item)
        itemChoice0 = data[0].item_choice
        self.assertTrue(itemChoice0.has_item)
        item0 = itemChoice0.item
        self.assertEqual(PARAMS[0], item0.param)
        self.assertEqual(self.api.ItemType.WITH_EXTRA_PARAM, item0.item_type)
        self.assertEqual(self.api.ExtraParamUnion.CHOICE_value32, item0.extra_param.choice_tag)
        self.assertEqual(EXTRA_PARAM, item0.extra_param.value32)

        # element 1
        self.assertFalse(data[1].has_item)
        itemChoice1 = data[1].item_choice
        self.assertFalse(itemChoice1.has_item)
        self.assertEqual(PARAMS[1], itemChoice1.param)

    def _assertMethodNotPresent(self, userType, method):
        self.assertFalse(hasattr(userType, method),
                         msg=("Method '%s' is present in '%s'!" % (method, userType.__name__)))

    def _assertMethodPresent(self, userType, method):
        self.assertTrue(hasattr(userType, method),
                        msg=("Method '%s' is not present in '%s'!" % (method, userType.__name__)))

    def _assertPropertyPresent(self, userType, prop, *, readOnly):
        self.assertTrue(
            hasattr(userType, prop),
            msg=("Property '%s' is not present in '%s'!" % (prop, userType.__name__))
        )
        propAttr = getattr(userType, prop)
        self.assertTrue(
            isinstance(propAttr, property),
            msg=("Attribute '%s' is not a property in '%s'!" % (prop, userType.__name__))
        )
        self.assertIsNotNone(
            propAttr.fget,
            msg=("Property '%s' getter is not set in '%s'!" % (prop, userType.__name__))
        )
        if readOnly:
            self.assertIsNone(
                propAttr.fset,
                msg=("Read-only property '%s' setter is set in '%s'!" % (prop, userType.__name__))
            )
        else:
            self.assertIsNotNone(
                propAttr.fset,
                msg=("Property '%s' setter is not set in '%s'!" % (prop, userType.__name__))
            )

TILE_ID_EUROPE = 99
TILE_ID_AMERICA = 11
VERSION_AVAILABILITY = 1
VERSION = 8
NUM_ELEMENTS = 2
PARAMS = [13, 21]
EXTRA_PARAM = 42
