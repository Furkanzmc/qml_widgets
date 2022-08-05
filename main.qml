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

                property Calculator window

                onClicked: {
                    if (!window) {
                        window = cmpCalculator.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                text: "Buttons Gallery"

                property ButtonsGallery window

                onClicked: {
                    if (!window) {
                        window = cmpButtonsGallery.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                text: "Text Editing Gallery"

                property TextEditingGallery window

                onClicked: {
                    if (!window) {
                        window = cmpTextEditingGallery.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                text: "Dialogs Gallery"

                property DialogsGallery window

                onClicked: {
                    if (!window) {
                        window = cmpDialogs.createObject(root)
                    }

                    window.visible = true
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

        VBoxLayout {
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
    }

    Component {
        id: cmpCalculator

        Calculator { }
    }

    Component {
        id: cmpButtonsGallery

        ButtonsGallery { }
    }

    Component {
        id: cmpTextEditingGallery

        TextEditingGallery { }
    }

    Component {
        id: cmpDialogs

        DialogsGallery { }
    }
}
