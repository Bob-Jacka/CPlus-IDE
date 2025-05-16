import QtQuick

Rectangle {

    width: 60
    height: width
    color: "black" //background color of the button

    property string img_path: ""
    property string txt: "" //text will apply if image is not available
    property int anim_dur: 200

    signal click //signal for click state - onClick is slot for signal
    signal txtBase //if image does not exist

    Image {
        id: img
        source: img_path
        width: parent.width
        height: parent.height
        clip: true

        MouseArea {
            anchors.fill: parent
            onClicked: {
                onClick()
            }
        }
    }

    //Custom slot
    onClick {
        SequentialAnimation {
            id: img_anim
            NumberAnimation {
                targets: [width, height]
                from: 60, 60
                to: 70, 70
                properties: "up"
                duration: anim_dur
            }

            NumberAnimation {
                targets: [width, height]
                from: 70, 70
                to: 60, 60
                properties: "down"
                duration: anim_dur
            }
        }
    }

    onTxtBase {
        txt: "some_text"
    }
}
