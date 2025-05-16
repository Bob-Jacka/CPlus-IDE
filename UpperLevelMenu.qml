import QtQuick
import QtQuick.Layouts

Rectangle {

    id: upper_menu
    width: 900
    height: 60

    signal menu_visible
    signal menu_hidden

    RowLayout {
        id: upper_menu_layout
        Button {
            id: run_btn
            text: "run"
        }

        Button {
            id: debug_btn
            text: "debug"
        }

        Button {
            id: settings_btn
            text: "settings"
        }

        Button {
            id: search_btn
            text: "search"
        }
    }

    onMenu_visible: {
        //
    }

    onMenu_hidden: {
        //
    }
}
