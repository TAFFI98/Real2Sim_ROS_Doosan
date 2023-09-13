# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dsr_msgs/CalcCoordRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CalcCoordRequest(genpy.Message):
  _md5sum = "f183627610e5714b756bba5cf0bcf435"
  _type = "dsr_msgs/CalcCoordRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#____________________________________________________________________________________________
# calc_coord   
#____________________________________________________________________________________________
# This service is only available in M2.50 or later

int8       input_pos_cnt     # input_pos_cnt
float64[6] x1                # task pos(posx)  
float64[6] x2                # task pos(posx)  
float64[6] x3                # task pos(posx)
float64[6] x4                # task pos(posx)
int8       ref               # DR_BASE(0), DR_WORLD(2)
int8       mod               # input mode(only valid when the number of input poses is 2)
                             # 0: defining z-axis based on the current Tool-z direction
                             # 1: defining z-axis based on the z direction of x1 
"""
  __slots__ = ['input_pos_cnt','x1','x2','x3','x4','ref','mod']
  _slot_types = ['int8','float64[6]','float64[6]','float64[6]','float64[6]','int8','int8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       input_pos_cnt,x1,x2,x3,x4,ref,mod

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CalcCoordRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.input_pos_cnt is None:
        self.input_pos_cnt = 0
      if self.x1 is None:
        self.x1 = [0.] * 6
      if self.x2 is None:
        self.x2 = [0.] * 6
      if self.x3 is None:
        self.x3 = [0.] * 6
      if self.x4 is None:
        self.x4 = [0.] * 6
      if self.ref is None:
        self.ref = 0
      if self.mod is None:
        self.mod = 0
    else:
      self.input_pos_cnt = 0
      self.x1 = [0.] * 6
      self.x2 = [0.] * 6
      self.x3 = [0.] * 6
      self.x4 = [0.] * 6
      self.ref = 0
      self.mod = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.input_pos_cnt
      buff.write(_get_struct_b().pack(_x))
      buff.write(_get_struct_6d().pack(*self.x1))
      buff.write(_get_struct_6d().pack(*self.x2))
      buff.write(_get_struct_6d().pack(*self.x3))
      buff.write(_get_struct_6d().pack(*self.x4))
      _x = self
      buff.write(_get_struct_2b().pack(_x.ref, _x.mod))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 1
      (self.input_pos_cnt,) = _get_struct_b().unpack(str[start:end])
      start = end
      end += 48
      self.x1 = _get_struct_6d().unpack(str[start:end])
      start = end
      end += 48
      self.x2 = _get_struct_6d().unpack(str[start:end])
      start = end
      end += 48
      self.x3 = _get_struct_6d().unpack(str[start:end])
      start = end
      end += 48
      self.x4 = _get_struct_6d().unpack(str[start:end])
      _x = self
      start = end
      end += 2
      (_x.ref, _x.mod,) = _get_struct_2b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.input_pos_cnt
      buff.write(_get_struct_b().pack(_x))
      buff.write(self.x1.tostring())
      buff.write(self.x2.tostring())
      buff.write(self.x3.tostring())
      buff.write(self.x4.tostring())
      _x = self
      buff.write(_get_struct_2b().pack(_x.ref, _x.mod))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 1
      (self.input_pos_cnt,) = _get_struct_b().unpack(str[start:end])
      start = end
      end += 48
      self.x1 = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=6)
      start = end
      end += 48
      self.x2 = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=6)
      start = end
      end += 48
      self.x3 = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=6)
      start = end
      end += 48
      self.x4 = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=6)
      _x = self
      start = end
      end += 2
      (_x.ref, _x.mod,) = _get_struct_2b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2b = None
def _get_struct_2b():
    global _struct_2b
    if _struct_2b is None:
        _struct_2b = struct.Struct("<2b")
    return _struct_2b
_struct_6d = None
def _get_struct_6d():
    global _struct_6d
    if _struct_6d is None:
        _struct_6d = struct.Struct("<6d")
    return _struct_6d
_struct_b = None
def _get_struct_b():
    global _struct_b
    if _struct_b is None:
        _struct_b = struct.Struct("<b")
    return _struct_b
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dsr_msgs/CalcCoordResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CalcCoordResponse(genpy.Message):
  _md5sum = "904a2ae76f71ef4190bde0122093ec1b"
  _type = "dsr_msgs/CalcCoordResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float64[6] conv_posx         # task pos(posx) 
bool       success
"""
  __slots__ = ['conv_posx','success']
  _slot_types = ['float64[6]','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       conv_posx,success

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CalcCoordResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.conv_posx is None:
        self.conv_posx = [0.] * 6
      if self.success is None:
        self.success = False
    else:
      self.conv_posx = [0.] * 6
      self.success = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_6d().pack(*self.conv_posx))
      _x = self.success
      buff.write(_get_struct_B().pack(_x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 48
      self.conv_posx = _get_struct_6d().unpack(str[start:end])
      start = end
      end += 1
      (self.success,) = _get_struct_B().unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.conv_posx.tostring())
      _x = self.success
      buff.write(_get_struct_B().pack(_x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 48
      self.conv_posx = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=6)
      start = end
      end += 1
      (self.success,) = _get_struct_B().unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6d = None
def _get_struct_6d():
    global _struct_6d
    if _struct_6d is None:
        _struct_6d = struct.Struct("<6d")
    return _struct_6d
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
class CalcCoord(object):
  _type          = 'dsr_msgs/CalcCoord'
  _md5sum = '2001e63c6ceb43ba2ea8431cc72302b9'
  _request_class  = CalcCoordRequest
  _response_class = CalcCoordResponse