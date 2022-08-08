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

            PushButton {
                text: "Layouts Gallery"

                property LayoutsGallery window

                onClicked: {
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
