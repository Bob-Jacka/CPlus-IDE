import QtQuick
import QtQuick.Layouts

Rectangle {

    id: upper_menu
    width: 900
    height: 60

    RowLayout {

        Button {
            id: run_btn
            text: "run"
        }

        Button {
            id: debug_btn
            text: "debug"
        }
    }
}
