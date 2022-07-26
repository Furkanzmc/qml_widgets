import Qml.Widgets
import QtQml 2.15

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "QML QWidget Gallery"

    HBoxLayout {
        VBoxLayout {
            PushButton {
                text: "Calculator"

                property Calculator calculator

                onClicked: {
                    if (!calculator) {
                        calculator = cmp.createObject(root)
                    }

                    calculator.visible = true
                }
            }

            Label {
                id: colorLabel
                text: "Pick Color"
            }
        }

        VBoxLayout {
            HBoxLayout {
                Label {
                    text: "TextEdit"
                }

                TextEdit {

                }
            }

            HBoxLayout {
                Label {
                    text: "First Name"
                }

                LineEdit {

                }
            }

            HBoxLayout {
                Label {
                    text: "PlainTextEdit"
                }

                PlainTextEdit {

                }
            }
        }

        VBoxLayout {
            Label {
                text: "GridLayout"
            }

            GridLayout {
                CheckBox {
                    text: "Check me out"
                    toolTip: "Show color dialog using QColorDialog"
                    Layout.row: 0
                    Layout.column: 0
                }

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

                CheckBox {
                    text: "Check me out twice"
                    toolTip: "Show color dialog using QColorDialog"
                    Layout.row: 1
                    Layout.column: 1
                }
            }
        }

        GroupBox {
            title: "Buttons"

            VBoxLayout {
                PushButton {
                    text: "PushButton"
                }

                ToolButton {
                    text: "ToolButton"
                }

                CommandLinkButton {
                    text: "Command Link"
                }

                GridLayout {

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
            title: "Dialogs"

            VBoxLayout {
                PushButton {
                    text: "Font Dialog"
                    onClicked: {
                        fd.open()
                    }
                }

                PushButton {
                    text: "Color Dialog"
                    toolTip: "Show color dialog using QColorDialog"
                    onClicked: {
                        cd.open()
                    }
                }

                PushButton {
                    text: "Message Box"
                    onClicked: {
                        mb.open()
                    }
                }

                PushButton {
                    text: "File Dialog"
                    onClicked: {
                        fileDialog.open()
                    }
                }
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

        GroupBox {
            title: "StackLayout"

            StackLayout {
                id: sl

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 1"
                        }

                        PushButton {
                            text: "Go to Page 2"
                            onClicked: {
                                sl.currentIndex = 1
                            }
                        }
                    }
                }

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 2"
                        }

                        PushButton {
                            text: "Go to Page 1"
                            onClicked: {
                                sl.currentIndex = 0
                            }
                        }

                        KeySequenceEdit {

                        }
                    }
                }
            }
        }

        VBoxLayout {

            Label {
                text: "StackWidget"
            }

            StackWidget {
                id: sw

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 1"
                        }

                        PushButton {
                            text: "Go to Page 2"
                            onClicked: {
                                sw.currentIndex = 1
                            }
                        }
                    }
                }

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 2"
                        }

                        PushButton {
                            text: "Go to Page 1"
                            onClicked: {
                                sw.currentIndex = 0
                            }
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
        informativeText: "So long long ago"
        detailedText: "Hello from the other side."
        standardButtons: MessageBox.Ok | MessageBox.Discard
        icon: MessageBox.Warning
    }

    ColorDialog {
        id: cd
        options: ColorDialog.ShowAlphaChannel | ColorDialog.DontUseNativeDialog
        onAccepted: {
            colorLabel.text = "Selected Color: " + currentColor
        }
    }

    FontDialog {
        id: fd
        onCurrentFontChanged: {
            console.log("[main.qml::342::onCurrentFontChanged]", currentFont)
        }
    }

    FileDialog {
        id: fileDialog
        onFileSelected: (file) => {
            console.log("[main.qml::342::onFileSelected]", file)
        }
    }

    Component {
        id: cmp

        Calculator { }
    }
}
