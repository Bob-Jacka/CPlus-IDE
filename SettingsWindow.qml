import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {

    id: settings_window
    visible: true
    width: 700
    height: 600

    signal settings_applied
    signal settings_canceled
    signal win_visible
    signal win_hidden

    ScrollView {
        id: settings_names
        ListView {
            id: settings_point

            ListElement {
                name: appeareance
            }

            ListElement {
                name: sintax_highlight
            }
        }
    }

    //Every point information
    ScrollView {
        Rectangle {
            id: point_info
            Text {
                id: txt
                text: qsTr("text")
            }
        }
    }

    //Buttons at bottom
    Layout {
        id: lower_layout
        anchors.bottom: parent.bottom
        Layout.alignment: Qt.AlignHCenter
        Button {
            id: ok_btn
        }

        Button {
            id: cancel_btn
        }

        Button {
            id: apply_btn
        }
    }

    onSettings_applied: {
        //
    }

    onSettings_canceled: {
        //
    }

    onWin_hidden: {
        //
    }

    onWin_visible: {
        //
    }
}
