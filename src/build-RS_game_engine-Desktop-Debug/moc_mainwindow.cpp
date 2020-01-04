/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RS_game_engine/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "addRectangle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "loadDefaultBackground"
QT_MOC_LITERAL(4, 47, 11), // "addEnemyOne"
QT_MOC_LITERAL(5, 59, 9), // "addPlayer"
QT_MOC_LITERAL(6, 69, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(7, 93, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(8, 117, 24), // "on_actionClear_triggered"
QT_MOC_LITERAL(9, 142, 18), // "on_startBt_clicked"
QT_MOC_LITERAL(10, 161, 22), // "on_cbCollision_clicked"
QT_MOC_LITERAL(11, 184, 7), // "checked"
QT_MOC_LITERAL(12, 192, 20), // "on_cbGravity_clicked"
QT_MOC_LITERAL(13, 213, 23), // "on_cbMoveUpDown_clicked"
QT_MOC_LITERAL(14, 237, 17), // "on_cbJump_clicked"
QT_MOC_LITERAL(15, 255, 23) // "on_cbSpeedBoost_clicked"

    },
    "MainWindow\0addRectangle\0\0loadDefaultBackground\0"
    "addEnemyOne\0addPlayer\0on_actionSave_triggered\0"
    "on_actionLoad_triggered\0"
    "on_actionClear_triggered\0on_startBt_clicked\0"
    "on_cbCollision_clicked\0checked\0"
    "on_cbGravity_clicked\0on_cbMoveUpDown_clicked\0"
    "on_cbJump_clicked\0on_cbSpeedBoost_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addRectangle(); break;
        case 1: _t->loadDefaultBackground(); break;
        case 2: _t->addEnemyOne(); break;
        case 3: _t->addPlayer(); break;
        case 4: _t->on_actionSave_triggered(); break;
        case 5: _t->on_actionLoad_triggered(); break;
        case 6: _t->on_actionClear_triggered(); break;
        case 7: _t->on_startBt_clicked(); break;
        case 8: _t->on_cbCollision_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_cbGravity_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_cbMoveUpDown_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_cbJump_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_cbSpeedBoost_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
