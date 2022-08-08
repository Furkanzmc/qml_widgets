import Qml.Widgets

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Widgets Gallery"

    GridLayout {
        GroupBox {
            title: "GridLayout"
            Layout.column: 0
            Layout.row: 0

            GridLayout {
                Label {
                    text: "Label 1"
                    Layout.column: 0
                    Layout.row: 0
                }

                Label {
                    text: "Label 2"
                    Layout.column: 1
                    Layout.row: 0
                }

                Label {
                    text: "Label 3"
                    Layout.column: 2
                    Layout.row: 0
                }

                PushButton {
                    text: "Button"
                    Layout.column: 0
                    Layout.row: 1
                }

                CheckBox {
                    text: "CheckBox"
                    Layout.column: 1
                    Layout.row: 1
                }

                RadioButton {
                    text: "Radio Button"
                    Layout.column: 2
                    Layout.row: 1
                }
            }
        }

        GroupBox {
            title: "VBoxLayout"
            Layout.column: 1
            Layout.row: 0

            VBoxLayout {
                CheckBox {
                    text: "Option 1"
                }

                CheckBox {
                    text: "Option 2"
                }
            }
        }

        GroupBox {
            title: "HBoxLayout"
            Layout.column: 2
            Layout.row: 0

            HBoxLayout {
                RadioButton {
                    text: "Option 1"
                }

                RadioButton {
                    text: "Option 2"
                }
            }
        }

        GroupBox {
            title: "StackLayout"
            Layout.column: 0
            Layout.row: 1

            StackLayout {
                id: sl

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 1"
                        }

                        Spacer {
                            verticalSizePolicy: SizePolicy.Expanding
                        }

                        HBoxLayout {
                            Spacer {
                                horizontalSizePolicy: SizePolicy.Expanding
                            }

                            PushButton {
                                text: "Go to Page 2"
                                onClicked: {
                                    sl.currentIndex = 1
                                }
                            }
                        }
                    }
                }

                Widget {
                    VBoxLayout {
                        Label {
                            text: "Page 2"
                        }

                        Spacer {
                            verticalSizePolicy: SizePolicy.Expanding
                        }

                        HBoxLayout {
                            Spacer {
                                horizontalSizePolicy: SizePolicy.Expanding
                            }

                            PushButton {
                                text: "Go to Page 1"
                                onClicked: {
                                    sl.currentIndex = 0
                                }
                            }
                        }
                    }
                }
            }
        }

        GroupBox {
            title: "FormLayout"
            Layout.column: 1
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
