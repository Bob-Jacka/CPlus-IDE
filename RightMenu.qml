import QtQuick
// import "Button.qml" as Button
import QtQuick.Layouts

Rectangle {

    id: right_menu
    width: 60
    height: 900
    color: "black"

    signal menu_visible
    signal menu_hidden

    ColumnLayout {
        id: right_menu_layout
        Button {
            id: git_btn
            text: "git"
        }

        Button {
            id: todo_btn
            text: "to-do"
        }
    }

    onMenu_visible: {
        //
    }

    onMenu_hidden: {
        //
    }
}
