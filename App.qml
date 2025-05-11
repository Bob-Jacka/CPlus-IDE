import QtQuick
import QtQuick.Controls


Window {
    id: main_window
    width: 800
    height: 900
    visible: true
    title: qsTr("C+ IDE")

    // property var builtInStyles

    // MenuBar {
    //     Menu {
    //         title: qsTr("&File")
    //         MenuItem {
    //             text: qsTr("&New")
    //             icon.name: "document created"
    //         }
    //         MenuSeparator {}
    //         MenuItem {
    //             text: qsTr("&Open")
    //             icon.name: "document opened"
    //         }
    //         MenuItem {
    //             text: qsTr("&Save")
    //             icon.name: "document saved"
    //         }
    //         MenuItem {
    //             text: qsTr("Save &As...")
    //             icon.name: "document created"
    //         }
    //     }
    // }

    UpperLevelMenu {
        id: upperLevelMenu
        anchors.top: parent.top
    }

    RightMenu {
        id: rightMenu
        anchors.right: parent.right
    }

    LeftMenu {
        id: leftMenu
        anchors.left: parent.left
    }

    TxtInput {
        anchors.right: rightMenu.left
        anchors.left: leftMenu.right
        anchors.top: upperLevelMenu.bottom
        anchors.bottom: parent.bottom
    }
}
