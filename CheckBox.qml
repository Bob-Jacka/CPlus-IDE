import QtQuick
import QtQuick.Controls

//Toggle
Item {
    property string text
    property alias checked: toggleIndicator.checked
    readonly property alias hasFocus: toggleIndicator.activeFocus
    implicitWidth: toggleText.width + toggleIndicator.width
    implicitHeight: 50

    Label {
        id: toggleText
        text: parent.text
        anchors.verticalCenter: toggleIndicator.verticalCenter
    }

    Switch {
        id: toggleIndicator
        anchors.left: toggleText.right
        anchors.rightMargin: 8
    }
}
