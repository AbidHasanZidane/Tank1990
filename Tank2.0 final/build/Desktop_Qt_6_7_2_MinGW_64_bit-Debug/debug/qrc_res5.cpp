/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/GIt_tank/Tank1990/Tank2.0 final/res5/playagain.png
  
  
    // D:/GIt_tank/Tank1990/Tank2.0 final/res5/icon_bomb.png
  
  
  
static const unsigned char qt_resource_data[11097] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // res5
  0x0,0x4,
  0x0,0x7,0x8c,0x65,
  0x0,0x72,
  0x0,0x65,0x0,0x73,0x0,0x35,
    // playagain.png
  0x0,0xd,
  0x9,0xd0,0xb9,0x27,
  0x0,0x70,
  0x0,0x6c,0x0,0x61,0x0,0x79,0x0,0x61,0x0,0x67,0x0,0x61,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
    // icon_bomb.png
  0x0,0xd,
  0xd,0x79,0xdd,0xc7,
  0x0,0x69,
  0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x5f,0x0,0x62,0x0,0x6f,0x0,0x6d,0x0,0x62,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/res5
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/res5/playagain.png
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x80,0xa2,0xe0,0x7e,0x18,
  // :/res5/icon_bomb.png
  0x0,0x0,0x0,0x2e,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x27,0x5a,
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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_res5)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_res5)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res5)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res5)()
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
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_res5)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res5)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
