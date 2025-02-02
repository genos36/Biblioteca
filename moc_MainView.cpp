/****************************************************************************
** Meta object code from reading C++ file 'MainView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interfaccia/MainView.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainView.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainView_t {
    uint offsetsAndSizes[22];
    char stringdata0[9];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[21];
    char stringdata5[16];
    char stringdata6[19];
    char stringdata7[26];
    char stringdata8[28];
    char stringdata9[28];
    char stringdata10[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainView_t qt_meta_stringdata_MainView = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainView"
        QT_MOC_LITERAL(9, 24),  // "propagateModNotification"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 10),  // "deleteItem"
        QT_MOC_LITERAL(46, 20),  // "ListWidgetMediaItem*"
        QT_MOC_LITERAL(67, 15),  // "switchToModView"
        QT_MOC_LITERAL(83, 18),  // "switchToCreateView"
        QT_MOC_LITERAL(102, 25),  // "saveAndSwitchToDetailview"
        QT_MOC_LITERAL(128, 27),  // "createAndSwitchToDetailview"
        QT_MOC_LITERAL(156, 27),  // "cancelAndSwitchToDetailview"
        QT_MOC_LITERAL(184, 16)   // "ChangeDetailview"
    },
    "MainView",
    "propagateModNotification",
    "",
    "deleteItem",
    "ListWidgetMediaItem*",
    "switchToModView",
    "switchToCreateView",
    "saveAndSwitchToDetailview",
    "createAndSwitchToDetailview",
    "cancelAndSwitchToDetailview",
    "ChangeDetailview"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    1,   63,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   66,    2, 0x0a,    4 /* Public */,
       6,    1,   67,    2, 0x0a,    5 /* Public */,
       7,    0,   70,    2, 0x0a,    7 /* Public */,
       8,    0,   71,    2, 0x0a,    8 /* Public */,
       9,    0,   72,    2, 0x0a,    9 /* Public */,
      10,    1,   73,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    0x80000000 | 4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainView.offsetsAndSizes,
    qt_meta_data_MainView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainView, std::true_type>,
        // method 'propagateModNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'switchToModView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToCreateView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'saveAndSwitchToDetailview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createAndSwitchToDetailview'
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'cancelAndSwitchToDetailview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangeDetailview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>
    >,
    nullptr
} };

void MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->propagateModNotification(); break;
        case 1: _t->deleteItem((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        case 2: _t->switchToModView(); break;
        case 3: _t->switchToCreateView((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->saveAndSwitchToDetailview(); break;
        case 5: { ListWidgetMediaItem* _r = _t->createAndSwitchToDetailview();
            if (_a[0]) *reinterpret_cast< ListWidgetMediaItem**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->cancelAndSwitchToDetailview(); break;
        case 7: _t->ChangeDetailview((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainView::*)();
            if (_t _q_method = &MainView::propagateModNotification; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainView::*)(ListWidgetMediaItem * );
            if (_t _q_method = &MainView::deleteItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainView::propagateModNotification()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainView::deleteItem(ListWidgetMediaItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
