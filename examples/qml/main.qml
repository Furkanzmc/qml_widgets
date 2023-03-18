import Qml.Widgets
// import Qml.Widgets.Window
// import Qml.Widgets.Dialogs
import QtQml 2.15

MainWindow {
    id: root
    height: 200
    visible: true
    windowTitle: "QML QWidget Gallery"

    MenuBar {
        Menu {
            title: "Demos"

            Action {
                text: "Calculator"
                onTriggered: {
                    calculator.open()
                }
            }

            Action {
                text: "Widgets Gallery"
                onTriggered: {
                    widgets.open()
                }
            }

            Action {
                text: "Dialogs Gallery"
                onTriggered: {
                    dialogs.open()
                }
            }

            Action {
                text: "Layouts Gallery"
                onTriggered: {
                    layouts.open()
                }
            }
        }

        Menu {
            title: "Help"

            Action {
                property MessageBox aboutBox: MessageBox {
                    text: "This is a sample QWidgets application using QML."
                    detailedText: "This message box is created from QML."
                    icon: MessageBox.Information
                    standardButtons: MessageBox.Close
                }

                text: "About QML Widgets"
                onTriggered: {
                    aboutBox.open()
                }
            }
        }
    }

    HBoxLayout {
        VBoxLayout {
            PushButton {
                id: calculator

                text: "Calculator"

                property Calculator window

                onClicked: {
                    open()
                }

                function open() {
                    if (!window) {
                        window = cmpCalculator.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                id: widgets
                text: "Widgets Gallery"

                property WidgetsGallery window

                onClicked: {
                    open()
                }

                function open() {
                    if (!window) {
                        window = cmpWidgetsGallery.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                id: dialogs
                text: "Dialogs Gallery"

                property DialogsGallery window

                onClicked: {
                    open()
                }

                function open() {
                    if (!window) {
                        window = cmpDialogs.createObject(root)
                    }

                    window.visible = true
                }
            }

            PushButton {
                id: layouts
                text: "Layouts Gallery"

                property LayoutsGallery window

                onClicked: {
                    open()
                }

                function open() {
                    if (!window) {
                        window = cmpLayouts.createObject(root)
                    }

                    window.visible = true
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

    Component {
        id: cmpLayouts

        LayoutsGallery { }
    }
}
