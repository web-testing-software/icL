import QtQuick 2.0
pragma Singleton

QtObject {
    property int hMove: 0x1
    property int vMove: 0x2
    property int hResize: 0x4
    property int vResize: 0x8
}
