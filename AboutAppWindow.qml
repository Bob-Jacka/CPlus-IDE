import QtQuick
import QtQuick.Layouts

Window {
    id: about_window
    visible: true
    width: 200
    height: 200
    color: "black"

    Layout {
        Layout.alignment: Qt.AlignHCenter
        Text {
            id: app_name
            text: qsTr("C plus IDE")
        }

        Text {
            id: app_version
            text: qsTr("App version is - ")
        }

        Text {
            text: qsTr("All rights reserved")
        }
    }
}
