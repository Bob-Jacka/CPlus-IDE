import QtQuick
// import "Button.qml" as Button
import QtQuick.Layouts

Rectangle {

    id: left_menu
    width: 60
    height: 900

    signal menu_visible
    signal menu_hidden

    ColumnLayout {
        id: left_menu_layout
        Button {
            id: build_system
            text: "not some text"
        }

        Button {
            id: comments
            text: "comment"
        }
    }

    onMenu_visible: {
        //
    }

    onMenu_hidden: {
        //
    }
}
