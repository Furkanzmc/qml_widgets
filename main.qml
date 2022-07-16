import Qml.Widgets

Widget {
    visible: true
    windowTitle: "QML QWidget Gallery"

    HBoxLayout {
        PushButton {
            text: "MessageBox"
            onClicked: {
                mb.open()
            }
        }

        VBoxLayout {
            PushButton {
                text: "ColorDialog"
                toolTip: "Show color dialog using QColorDialog"
                onClicked: {
                    cd.open()
                }
            }

            Label {
                id: colorLabel
                text: "Pick Color"
            }
        }

        VBoxLayout {
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
        }

        GroupBox {
            title: "Group A"

            FormLayout {
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

                HBoxLayout {
                    PushButton {
                        text: "Four"
                        onClicked: {
                            console.log("[main.qml::14::onClicked]", text)
                        }
                    }

                    PushButton {
                        text: "Five"
                        onClicked: {
                            console.log("[main.qml::14::onClicked]", text)
                        }
                    }

                    PushButton {
                        text: "Six"
                        onClicked: {
                            console.log("[main.qml::14::onClicked]", text)
                        }
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
