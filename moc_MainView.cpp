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
    uint offsetsAndSizes[28];
    char stringdata0[9];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[21];
    char stringdata5[15];
    char stringdata6[11];
    char stringdata7[16];
    char stringdata8[19];
    char stringdata9[26];
    char stringdata10[28];
    char stringdata11[28];
    char stringdata12[17];
    char stringdata13[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainView_t qt_meta_stringdata_MainView = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainView"
        QT_MOC_LITERAL(9, 24),  // "propagateModNotification"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 19),  // "onDeleteItemPressed"
        QT_MOC_LITERAL(55, 20),  // "ListWidgetMediaItem*"
        QT_MOC_LITERAL(76, 14),  // "newItemCreated"
        QT_MOC_LITERAL(91, 10),  // "clearViews"
        QT_MOC_LITERAL(102, 15),  // "switchToModView"
        QT_MOC_LITERAL(118, 18),  // "switchToCreateView"
        QT_MOC_LITERAL(137, 25),  // "saveAndSwitchToDetailview"
        QT_MOC_LITERAL(163, 27),  // "createAndSwitchToDetailview"
        QT_MOC_LITERAL(191, 27),  // "cancelAndSwitchToDetailview"
        QT_MOC_LITERAL(219, 16),  // "ChangeDetailview"
        QT_MOC_LITERAL(236, 17)   // "refreshDetailView"
    },
    "MainView",
    "propagateModNotification",
    "",
    "onDeleteItemPressed",
    "ListWidgetMediaItem*",
    "newItemCreated",
    "clearViews",
    "switchToModView",
    "switchToCreateView",
    "saveAndSwitchToDetailview",
    "createAndSwitchToDetailview",
    "cancelAndSwitchToDetailview",
    "ChangeDetailview",
    "refreshDetailView"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,
       5,    1,   84,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   87,    2, 0x0a,    6 /* Public */,
       7,    0,   88,    2, 0x0a,    7 /* Public */,
       8,    1,   89,    2, 0x0a,    8 /* Public */,
       9,    0,   92,    2, 0x0a,   10 /* Public */,
      10,    0,   93,    2, 0x0a,   11 /* Public */,
      11,    0,   94,    2, 0x0a,   12 /* Public */,
      12,    1,   95,    2, 0x0a,   13 /* Public */,
      13,    0,   98,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    0x80000000 | 4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

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
        // method 'onDeleteItemPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'newItemCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'clearViews'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<ListWidgetMediaItem *, std::false_type>,
        // method 'refreshDetailView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        case 1: _t->onDeleteItemPressed((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        case 2: _t->newItemCreated((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        case 3: _t->clearViews(); break;
        case 4: _t->switchToModView(); break;
        case 5: _t->switchToCreateView((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->saveAndSwitchToDetailview(); break;
        case 7: { ListWidgetMediaItem* _r = _t->createAndSwitchToDetailview();
            if (_a[0]) *reinterpret_cast< ListWidgetMediaItem**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->cancelAndSwitchToDetailview(); break;
        case 9: _t->ChangeDetailview((*reinterpret_cast< std::add_pointer_t<ListWidgetMediaItem*>>(_a[1]))); break;
        case 10: _t->refreshDetailView(); break;
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
            if (_t _q_method = &MainView::onDeleteItemPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainView::*)(ListWidgetMediaItem * );
            if (_t _q_method = &MainView::newItemCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainView::propagateModNotification()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainView::onDeleteItemPressed(ListWidgetMediaItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainView::newItemCreated(ListWidgetMediaItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
