// Generated by gencpp from file ros_zserio_test/ZserioWrapper.msg
// DO NOT EDIT!


#ifndef ROS_ZSERIO_TEST_MESSAGE_ZSERIOWRAPPER_H
#define ROS_ZSERIO_TEST_MESSAGE_ZSERIOWRAPPER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_zserio_test
{
template <class ContainerAllocator>
struct ZserioWrapper_
{
  typedef ZserioWrapper_<ContainerAllocator> Type;

  ZserioWrapper_()
    : zserio_bytes()  {
    }
  ZserioWrapper_(const ContainerAllocator& _alloc)
    : zserio_bytes(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _zserio_bytes_type;
  _zserio_bytes_type zserio_bytes;




  typedef boost::shared_ptr< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> const> ConstPtr;

}; // struct ZserioWrapper_

typedef ::ros_zserio_test::ZserioWrapper_<std::allocator<void> > ZserioWrapper;

typedef boost::shared_ptr< ::ros_zserio_test::ZserioWrapper > ZserioWrapperPtr;
typedef boost::shared_ptr< ::ros_zserio_test::ZserioWrapper const> ZserioWrapperConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_zserio_test

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7e3dfc7741682ce331976309ebcb4966";
  }

  static const char* value(const ::ros_zserio_test::ZserioWrapper_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7e3dfc7741682ce3ULL;
  static const uint64_t static_value2 = 0x31976309ebcb4966ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_zserio_test/ZserioWrapper";
  }

  static const char* value(const ::ros_zserio_test::ZserioWrapper_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8[] zserio_bytes\n\
";
  }

  static const char* value(const ::ros_zserio_test::ZserioWrapper_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.zserio_bytes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ZserioWrapper_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_zserio_test::ZserioWrapper_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_zserio_test::ZserioWrapper_<ContainerAllocator>& v)
  {
    s << indent << "zserio_bytes[]" << std::endl;
    for (size_t i = 0; i < v.zserio_bytes.size(); ++i)
    {
      s << indent << "  zserio_bytes[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.zserio_bytes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_ZSERIO_TEST_MESSAGE_ZSERIOWRAPPER_H
