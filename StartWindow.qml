import QtQuick
import QtQuick.Layouts

Window {
    id: root
    width: 400
    height: 400
    color: "black"
    visible: true
    title: qsTr("Start window")

    signal create_proj
    signal open_proj

    ColumnLayout {
        anchors.fill: parent

        Button {
            id: create_new_proj
            text: "Create new project"
            width: 130
            height: 50
            color: "violet"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                root.create_proj
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
               root.open_proj
            }
        }
    }

    onCreate_proj: {
        start_window.close()
        App.show()
    }

    onOpen_proj: {
        start_window.close()
        App.show()
    }
}
