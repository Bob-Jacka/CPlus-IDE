import QtQuick
import QtQuick.Controls

//App - main window of the program
Window {
    id: main_window
    width: 900
    height: 800
    visible: true
    title: qsTr("C+ IDE")

    // property var builtInStyles

    signal win_visible
    signal win_hidden

    MenuBar {
        id: menu_bar

        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&New")
                icon.name: "document created"
            }
            MenuSeparator {}
            MenuItem {
                text: qsTr("&Open")
                icon.name: "document opened"
            }
            MenuItem {
                text: qsTr("&Save")
                icon.name: "document saved"
            }
            MenuItem {
                text: qsTr("Save &As...")
                icon.name: "document created"
            }
        }
    }

    UpperLevelMenu {
        id: upperLevelMen
        anchors.top: parent.top
    }

    RightMenu {
        id: rightMenu
        anchors.right: parent.right
        anchors.top: upperLevelMen.bottom
    }

    LeftMenu {
        id: leftMenu
        anchors.left: parent.left
        anchors.top: upperLevelMen.bottom
    }

    TxtInput {
        id: code_edit
        anchors.top: upperLevelMenu.bottom
        anchors.right: rightMenu.left
        anchors.left: leftMenu.right
        anchors.bottom: parent.bottom
    }

    onWin_visible: {
        //
    }

    onWin_hidden: {
        //
    }

    // LogOutput {

    // }
}
