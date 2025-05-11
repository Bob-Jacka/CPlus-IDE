import QtQuick

//button for other actions, except switch between light and dark theme

Rectangle {

    property int animation_duration: 200
    property string usual_color: "lightsteelblue"
    property string clicked_color: "gray"

    id: button
    property alias text: button_label.text
    property int width_btn: 50
    property int height_btn: 50
    property string color_btn: usual_color

    signal clicked
    signal hovered

    anchors.centerIn: parent.Center
    width: width_btn
    height: height_btn
    color: color_btn
    border.width: 1

    Text {
        id: button_label
        anchors.centerIn: parent
        text: "sometext"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            button_animation.start()
        }
    }

    SequentialAnimation {
        id: button_animation

        NumberAnimation {
            target: parent.width
            to: 70
            duration: parent.animation_duration
            easing.type: Easing.InOutQuad
        }

        //Inverse animation
        NumberAnimation {
            target: parent.width
            to: 50
            duration: parent.animation_duration
            easing.type: Easing.InOutQuad
        }

        ColorAnimation {
            from: parent.usual_color
            to: parent.clicked_color
            duration: parent.animation_duration
        }

        ColorAnimation {
            from: parent.clicked_color
            to: parent.usual_color
            duration: parent.animation_duration
        }
    }
}
