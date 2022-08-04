import Qml.Widgets

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Buttons Gallery"

    VBoxLayout {
        RadioButton {
            text: "Call me Misty."
            Layout.row: 0
            Layout.column: 1
        }

        RadioButton {
            text: "Or don't"
            Layout.row: 1
            Layout.column: 0
        }

        PushButton {
            text: "PushButton"
        }

        ToolButton {
            text: "Tool Button"
        }

        GridLayout {
            sizeConstraint: GridLayout.SetFixedSize

            ToolButton {
                text: "Up Arrow"
                arrowType: Qt.UpArrow
                Layout.row: 0
                Layout.column: 0
            }

            ToolButton {
                text: "RightArrow"
                arrowType: Qt.RightArrow
                Layout.row: 0
                Layout.column: 1
            }

            ToolButton {
                text: "LeftArrow"
                arrowType: Qt.LeftArrow
                Layout.row: 1
                Layout.column: 0
            }

            ToolButton {
                text: "BottomArrow"
                arrowType: Qt.DownArrow
                Layout.row: 1
                Layout.column: 1
            }
        }

        CommandLinkButton {
            text: "Command Link"
        }

    }
}

