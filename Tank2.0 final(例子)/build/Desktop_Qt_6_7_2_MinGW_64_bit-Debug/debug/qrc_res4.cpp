/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/GIt_tank/Tank1990/Tank2.0 final/music/boom.wav
  
  
    // D:/GIt_tank/Tank1990/Tank2.0 final/music/background.wav
  
  
  
static const unsigned char qt_resource_data[34781332] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // music
  0x0,0x5,
  0x0,0x74,0xc9,0xf3,
  0x0,0x6d,
  0x0,0x75,0x0,0x73,0x0,0x69,0x0,0x63,
    // boom.wav
  0x0,0x8,
  0x6,0x60,0x50,0xa6,
  0x0,0x62,
  0x0,0x6f,0x0,0x6f,0x0,0x6d,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
    // background.wav
  0x0,0xe,
  0x7,0x4,0x95,0x46,
  0x0,0x62,
  0x0,0x61,0x0,0x63,0x0,0x6b,0x0,0x67,0x0,0x72,0x0,0x6f,0x0,0x75,0x0,0x6e,0x0,0x64,0x0,0x2e,0x0,0x77,0x0,0x61,0x0,0x76,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/music
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/music/boom.wav
  0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x80,0xa2,0xe0,0x7e,0x18,
  // :/music/background.wav
  0x0,0x0,0x0,0x26,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x1,0xe,0x64,
0x0,0x0,0x1,0x80,0xa2,0xe0,0x7e,0x18,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_res4)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_res4)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res4)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res4)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_res4)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res4)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
