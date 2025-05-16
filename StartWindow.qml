import QtQuick
import QtQuick.Layouts

// Start window
Window {
    id: root
    width: 400
    height: 400
    color: "black"
    visible: true
    title: qsTr("Start window")

    signal create_proj
    signal open_proj
    signal win_visible
    signal win_hidden

    Loader {
        id: page_loader
        anchors.fill: parent
        source: "StartWindow.qml"
    }

    ColumnLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignCenter

        Button {
            id: create_new_proj
            text: "Create new project"
            width: 130
            height: 50
            color: "violet"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                page_loader.source = "App.qml"
            }
        }

        Button {
            id: open_existing
            text: "Open project"
            width: 100
            height: 50
            color: "violet"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
               page_loader.source = "App.qml"
            }
        }
    }

    //image button
    Image {
        id: setting_window
        source: "file"
        anchors.top: parent.top
        Layout.alignment: Qt.AlignHCenter
    }

    onCreate_proj: {
        App.show()
    }

    onOpen_proj: {
        App.show()
    }

    onWin_visible: {
        //
    }

    onWin_hidden: {
        //
    }
}
