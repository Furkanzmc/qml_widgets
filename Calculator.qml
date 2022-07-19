import Qml.Widgets

Widget {
    visible: true
    windowTitle: "Calculator"

    GridLayout {
        sizeConstraint: GridLayout.SetFixedSize

        LineEdit {
            id: display
            Layout.row: 0
            Layout.column: 0
            Layout.rowSpan: 1
            Layout.columnSpan: 6
        }

        PushButton {
            text: "Backspace"
            Layout.row: 1
            Layout.column: 0
            Layout.rowSpan: 1
            Layout.columnSpan: 2
        }

        PushButton {
            text: "Clear"
            Layout.row: 1
            Layout.column: 2
            Layout.rowSpan: 1
            Layout.columnSpan: 2
            onClicked: {
                display.text = ""
            }
        }

        PushButton {
            text: "Clear All"
            Layout.row: 1
            Layout.column: 4
            Layout.rowSpan: 1
            Layout.columnSpan: 2
        }

        PushButton {
            text: "MC"
            Layout.row: 2
            Layout.column: 0
        }

        PushButton {
            text: "7"
            Layout.row: 2
            Layout.column: 1
        }

        PushButton {
            text: "8"
            Layout.row: 2
            Layout.column: 2
        }

        PushButton {
            text: "9"
            Layout.row: 2
            Layout.column: 3
        }

        PushButton {
            text: "/"
            Layout.row: 2
            Layout.column: 4
        }

        PushButton {
            text: "Sqrt"
            Layout.row: 2
            Layout.column: 5
        }

        // Third Row

        PushButton {
            text: "MR"
            Layout.row: 3
            Layout.column: 0
        }

        PushButton {
            text: "4"
            Layout.row: 3
            Layout.column: 1
        }

        PushButton {
            text: "5"
            Layout.row: 3
            Layout.column: 2
        }

        PushButton {
            text: "6"
            Layout.row: 3
            Layout.column: 3
        }

        PushButton {
            text: "x"
            Layout.row: 3
            Layout.column: 4
        }

        PushButton {
            text: "X^2"
            Layout.row: 3
            Layout.column: 5
        }

        // Fourth Row

        PushButton {
            text: "MS"
            Layout.row: 4
            Layout.column: 0
        }

        PushButton {
            text: "1"
            Layout.row: 4
            Layout.column: 1
        }

        PushButton {
            text: "2"
            Layout.row: 4
            Layout.column: 2
        }

        PushButton {
            text: "3"
            Layout.row: 4
            Layout.column: 3
        }

        PushButton {
            text: "-"
            Layout.row: 4
            Layout.column: 4
        }

        PushButton {
            text: "1/x"
            Layout.row: 4
            Layout.column: 5
        }

        // Fifth Row

        PushButton {
            text: "M+"
            Layout.row: 5
            Layout.column: 0
        }

        PushButton {
            text: "0"
            Layout.row: 5
            Layout.column: 1
        }

        PushButton {
            text: "."
            Layout.row: 5
            Layout.column: 2
        }

        PushButton {
            text: "+-"
            Layout.row: 5
            Layout.column: 3
        }

        PushButton {
            text: "+"
            Layout.row: 5
            Layout.column: 4
        }

        PushButton {
            text: "="
            Layout.row: 5
            Layout.column: 5
        }
    }
}
