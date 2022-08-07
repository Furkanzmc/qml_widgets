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
                text: "Widgets Gallery"

                property WidgetsGallery window

                onClicked: {
                    if (!window) {
                        window = cmpWidgetsGallery.createObject(root)
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
        id: cmpWidgetsGallery

        WidgetsGallery { }
    }

    Component {
        id: cmpDialogs

        DialogsGallery { }
    }
}
