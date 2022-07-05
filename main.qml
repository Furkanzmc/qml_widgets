import Qml.Widgets

Widget {
    visible: true
    windowTitle: "Hello QML Widgets"

    HBoxLayout {
        PushButton {
            text: "MessageBox"
            onClicked: {
                mb.open()
            }
        }

        PushButton {
            text: "ColorDialog"
            toolTip: "Show color dialog using QColorDialog"
            onClicked: {
                cd.open()
            }
        }

        Label {
            id: colorLabel
        }

        CheckBox {
            text: "Check me out"
            toolTip: "Show color dialog using QColorDialog"
        }

        RadioButton {
            text: "Call me Misty."
        }

        RadioButton {
            text: "Or don't"
        }

        GroupBox {
            title: "Group A"

            VBoxLayout {
                PushButton {
                    text: "One"
                    onClicked: {
                        console.log("[main.qml::14::onClicked]", text)
                    }
                }

                PushButton {
                    text: "One"
                    onClicked: {
                        console.log("[main.qml::14::onClicked]", text)
                    }
                }

                PushButton {
                    text: "Three"
                    onClicked: {
                        console.log("[main.qml::14::onClicked]", text)
                    }
                }
            }
        }
    }

    ErrorMessage {
        id: em
    }

    MessageBox {
        id: mb
        text: "Hello world!"
    }

    ColorDialog {
        id: cd
        options: ColorDialog.ShowAlphaChannel | ColorDialog.DontUseNativeDialog
        onAccepted: {
            colorLabel.text = "Selected Color: " + currentColor
        }
    }
}
