import Qml.Widgets

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Widgets Gallery"

    GridLayout {
        GroupBox {
            title: "Choices"
            Layout.column: 0
            Layout.row: 0

            VBoxLayout {
                RadioButton {
                    text: "Radio Button 1"
                }

                RadioButton {
                    text: "Radio Button 2"
                }

                CheckBox {
                    text: "Radio Button 2"
                }
            }
        }

        GroupBox {
            title: "Buttons"
            Layout.column: 1
            Layout.row: 0

            VBoxLayout {
                PushButton {
                    text: "PushButton"
                }

                HBoxLayout {
                    ToolButton {
                        text: "Tool Button"
                    }

                    CommandLinkButton {
                        text: "Command Link"
                    }
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
            }
        }

        GroupBox {
            title: "Sliders"
            Layout.column: 2
            Layout.row: 0

            VBoxLayout {
                Slider {
                    id: slider
                    maximum: 100
                    minimum: 0
                    orientation: Qt.Horizontal
                    value: spinBox.value
                }

                SpinBox {
                    id: spinBox
                    value: slider.value
                }

                ProgressBar {
                    minimum: 0
                    maximum: 100
                    value: slider.value
                }

                Dial {

                }
            }
        }

        GroupBox {
            title: "Text"
            Layout.column: 0
            Layout.row: 1

            FormLayout {
                labelAlignment: Qt.AlignLeft

                LineEdit {
                    Layout.label: "First Name"
                }

                LineEdit {
                    Layout.label: "Last Name"
                }

                LineEdit {
                    Layout.label:  "Email"
                }

                PlainTextEdit {
                    Layout.label: "Plain Text Field"
                }

                TextEdit {
                    Layout.label: "About Me"
                }

                KeySequenceEdit {
                    Layout.label: "Shortcut"
                }
            }
        }
    }
}
