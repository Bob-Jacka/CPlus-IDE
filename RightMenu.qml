import QtQuick
// import "Button.qml" as Button
import QtQuick.Layouts

Rectangle {

    id: right_menu
    width: 60
    height: 900

    ColumnLayout {
        Button {
            id: git_btn
            text: "git"
        }

        Button {
            id: todo_btn
            text: "to-do"
        }
    }
}
