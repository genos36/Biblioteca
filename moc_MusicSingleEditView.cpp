/****************************************************************************
** Meta object code from reading C++ file 'MusicSingleEditView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interfaccia/MusicSingleEditView.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicSingleEditView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MusicSingleEditView_t {
    uint offsetsAndSizes[10];
    char stringdata0[20];
    char stringdata1[15];
    char stringdata2[21];
    char stringdata3[1];
    char stringdata4[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MusicSingleEditView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MusicSingleEditView_t qt_meta_stringdata_MusicSingleEditView = {
    {
        QT_MOC_LITERAL(0, 19),  // "MusicSingleEditView"
        QT_MOC_LITERAL(20, 14),  // "createNewMedia"
        QT_MOC_LITERAL(35, 20),  // "ListWidgetMediaItem*"
        QT_MOC_LITERAL(56, 0),  // ""
        QT_MOC_LITERAL(57, 8)   // "applyMod"
    },
    "MusicSingleEditView",
    "createNewMedia",
    "ListWidgetMediaItem*",
    "",
    "applyMod"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MusicSingleEditView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    3, 0x10a,    1 /* Public | MethodIsConst  */,
       4,    1,   27,    3, 0x10a,    2 /* Public | MethodIsConst  */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, 0x80000000 | 2,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicSingleEditView::staticMetaObject = { {
    QMetaObject::SuperData::link<AudioEditView::staticMetaObject>(),
    qt_meta_stringdata_MusicSingleEditView.offsetsAndSizes,
    qt_meta_data_MusicSingleEditView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MusicSingleEditView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicSingleEditView, std::true_type>,
        // method 'createNewMedia'
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'applyMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>
    >,
    nullptr
} };

void MusicSingleEditView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicSingleEditView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { ListWidgetMediaItem* _r = _t->createNewMedia();
            if (_a[0]) *reinterpret_cast< ListWidgetMediaItem**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->applyMod((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MusicSingleEditView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicSingleEditView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicSingleEditView.stringdata0))
        return static_cast<void*>(this);
    return AudioEditView::qt_metacast(_clname);
}

int MusicSingleEditView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioEditView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
